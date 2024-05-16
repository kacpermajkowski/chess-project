#include <boost/test/unit_test.hpp>
#include "model/Rent.h"
#include "model/Client.h"
#include "model/Vehicle.h"
#include "model/Bicycle.h"

struct TestSuiteRentFixture{
    ClientPtr client;
    AddressPtr address;
    VehiclePtr vehicle;
    unsigned int rentID;
    pt::ptime time1;
    pt::ptime time2;

    TestSuiteRentFixture(){
        address = new Address("Poznan", "Ogrodowa", "15");
        client = new Client("Adam", "Nowak", "123", address, nullptr);
        vehicle = new Bicycle("GD12345", 100);
        rentID = 1;
        time1 = pt::ptime(gr::date(2020,5,13),pt::hours(9)+pt::minutes(25));
        time2 = pt::ptime(gr::date(2024,5,13),pt::hours(9)+pt::minutes(25));
    }
    ~TestSuiteRentFixture(){
        delete address;
        delete client;
        delete vehicle;
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRent, TestSuiteRentFixture)

    BOOST_AUTO_TEST_CASE(TestConstructorRent){
    Rent rent(rentID, client, vehicle, pt::not_a_date_time);
        BOOST_TEST(rent.getId()==rentID);
        BOOST_TEST(rent.getClient()==client);
        BOOST_TEST(rent.getVehicle()==vehicle);
        BOOST_TEST(vehicle->isRented()==true);
}

    BOOST_AUTO_TEST_CASE(TestPointerRent){ //checks if the pointer has been added to client's vector
    Rent rent(rentID, client, vehicle, pt::not_a_date_time);
    bool isPointerAddedToClient = false;
    for (const Rent* r : client->getCurrentRents()){
        if (r == &rent) {
            isPointerAddedToClient = true;
            break;
        }
    }
    BOOST_TEST(isPointerAddedToClient == true);
}

    BOOST_AUTO_TEST_CASE(TestDefaultBeginTimeRent){ //when beginTime is not given
        Rent rent(rentID, client, vehicle, pt::not_a_date_time);
        pt::ptime now = pt::second_clock::local_time();
        BOOST_TEST_REQUIRE(rent.getBeginTime() != pt::not_a_date_time);
        BOOST_TEST(rent.getBeginTime() == now);
}

    BOOST_AUTO_TEST_CASE(TestSetBeginTimeRent){ //when beginTime is given
        Rent rent(rentID, client, vehicle, time1);
        BOOST_TEST(rent.getBeginTime() == time1);
    }

    BOOST_AUTO_TEST_CASE(TestEndRent){ //checks if client and bicycle values change correctly due to the end of the rent
        BOOST_REQUIRE(vehicle->isRented() == false);
        BOOST_REQUIRE(client->getCurrentRents().size() == 0);

        Rent rent(rentID, client, vehicle, pt::not_a_date_time);

        BOOST_REQUIRE(vehicle->isRented() == true);
        BOOST_REQUIRE(client->getCurrentRents().size() == 1);

        rent.endRent(pt::not_a_date_time);

        BOOST_TEST(vehicle->isRented() == false);
        BOOST_TEST(client->getCurrentRents().size() == 0);
}


    BOOST_AUTO_TEST_CASE(TestDefaultEndTimeRent){ //when endTime is not given
        Rent rent(rentID, client, vehicle, pt::not_a_date_time);
        BOOST_TEST_REQUIRE(rent.getEndTime() == pt::not_a_date_time);
        BOOST_TEST_REQUIRE(vehicle->isRented() == true);

        rent.endRent(pt::not_a_date_time);
        pt::ptime now = pt::second_clock::local_time();

        BOOST_TEST(rent.getEndTime() == now);
        BOOST_TEST_REQUIRE(vehicle->isRented() == false);
}

    BOOST_AUTO_TEST_CASE(TestSetRightEndTimeRent){ //when given endTime is after beginTime
        Rent rent(rentID, client, vehicle, time1);
        BOOST_TEST_REQUIRE(rent.getEndTime() == pt::not_a_date_time);
        BOOST_TEST_REQUIRE(vehicle->isRented() == true);

        rent.endRent(time2);

        BOOST_TEST(rent.getEndTime() == time2);
        BOOST_TEST_REQUIRE(vehicle->isRented() == false);
}

    BOOST_AUTO_TEST_CASE(TestSetWrongEndTimeRent){ //when given endTime is before beginTime
        Rent rent(rentID, client, vehicle, time2);
        BOOST_TEST_REQUIRE(rent.getEndTime() == pt::not_a_date_time);
        BOOST_TEST_REQUIRE(vehicle->isRented() == true);

        rent.endRent(time1);

        BOOST_TEST(rent.getEndTime() == time2);
        BOOST_TEST_REQUIRE(vehicle->isRented() == false);
    }

    BOOST_AUTO_TEST_CASE(TestTryToOverwriteEndTimeRent){ //when endTime is already set, nothing should change
        Rent rent(rentID, client, vehicle, time1);
        rent.endRent(time2);

        BOOST_TEST_REQUIRE(rent.getEndTime() != pt::not_a_date_time);

        vehicle->setRented(true);
        rent.endRent(time1);

        BOOST_TEST(rent.getEndTime() == time2);
        BOOST_TEST(vehicle->isRented()==true);
    }

    BOOST_AUTO_TEST_CASE(TestGetRentDays){
        pt::ptime now = pt::second_clock::local_time();

        Rent rentUnderMinute(rentID, client, vehicle, now);
        BOOST_REQUIRE(vehicle->isRented() == true);
        BOOST_TEST_REQUIRE(rentUnderMinute.getEndTime() == pt::not_a_date_time);
        BOOST_TEST(rentUnderMinute.getRentDays() == 0);
        pt::ptime UnderMinute = now + pt::seconds(59);
        rentUnderMinute.endRent(UnderMinute);
        BOOST_TEST(rentUnderMinute.getRentDays() == 0);     //rent ends in less than a minute, cancelled

        Rent rentMinute(rentID, client, vehicle, now);
        pt::ptime Minute = now + pt::minutes(1);
        rentMinute.endRent(Minute);
        BOOST_TEST(rentMinute.getRentDays() == 0);    //rent ends in exactly a minute, cancelled

        Rent rentOverAMinute(rentID, client, vehicle, now);
        pt::ptime OverAMinute = now + pt::minutes(1) + pt::seconds(1);
        rentOverAMinute.endRent(OverAMinute);
        BOOST_TEST(rentOverAMinute.getRentDays() == 1); //rent ends in more than a minute, not cancelled

        Rent rentAlmostADay(rentID, client, vehicle, now);
        pt::ptime AlmostADay = now + pt::hours(23) + pt::minutes(59);
        rentAlmostADay.endRent(AlmostADay);
        BOOST_TEST(rentAlmostADay.getRentDays() == 1); //rent ends in 23 hours 59 minutes

        Rent rentExactlyADay(rentID, client, vehicle, now);
        pt::ptime ExactlyADay = now + pt::hours(24);
        rentExactlyADay.endRent(ExactlyADay);
        BOOST_TEST(rentExactlyADay.getRentDays() == 1); //rent ends in exactly 24 hours 0 minutes

        Rent rentMoreThanADay(rentID, client, vehicle, now);
        pt::ptime MoreThanADay = now + pt::hours(24) + pt::minutes(1);
        rentMoreThanADay.endRent(MoreThanADay);
        BOOST_TEST(rentMoreThanADay.getRentDays() == 2); //rend ends in more than 24 hours
}

    BOOST_AUTO_TEST_CASE(TestGetRentCost){
        pt::ptime now = pt::second_clock::local_time();

        Rent rentCancelled(rentID, client, vehicle, now);
        rentCancelled.endRent(now + pt::seconds(10));
        BOOST_TEST(rentCancelled.getRentCost() == 0);

        Rent rent(rentID, client, vehicle, now);
        rent.endRent(now + pt::hours(40)); //2 rent days
        unsigned int twoDaysCost = rent.getRentDays() * vehicle->getBasePrice();
        BOOST_TEST(rent.getRentCost() == twoDaysCost);
}



BOOST_AUTO_TEST_SUITE_END()