#include <boost/test/unit_test.hpp>
#include "model/Rent.h"
#include "model/Client.h"
#include "model/Vehicle.h"
#include "model/client/Default.h"
#include "model/client/Bronze.h"

struct TestSuiteRentFixture{
    AddressPtr address;
    ClientPtr client;
    VehiclePtr vehicle;
    unsigned int rentID;
    ClientType* def;
    ClientType* bronze;

    TestSuiteRentFixture() {
        def = new Default();
        bronze = new Bronze();

        address = new Address("Łódź", "Piotrkowska", "17");
        client = new Client("Kacper", "Majkowski", "251578", address, def);
        vehicle = new Vehicle("EZD 10000", 1234);
        rentID = 1;
    }

    ~TestSuiteRentFixture() {
        delete address;
        delete client;
        delete vehicle;
    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRent, TestSuiteRentFixture)

    ///@brief Checks if constructor initializes Vehicle fields correctly and modifies Client and Vehicle objects accordingly.
    BOOST_AUTO_TEST_CASE(ConstrutorDefaultTests){
        BOOST_REQUIRE_EQUAL(vehicle->isRented(), false);
        Rent rent(rentID, client, vehicle, pt::not_a_date_time);
        BOOST_TEST(rent.getId() == rentID);
        BOOST_TEST(rent.getClient() == client);
        BOOST_TEST(rent.getVehicle() == vehicle);
        // We're going for the default behaviour, which is setting beginTime to the moment Rent object was created
        BOOST_TEST(rent.getBeginTime() == pt::second_clock::local_time());
        BOOST_TEST(rent.getEndTime().is_not_a_date_time());

        bool hasPointerBeenAddedToCurrentRentsOfClient = false;
        for(RentPtr r: client->getCurrentRents()){
            if(r->getId() == rentID){
                hasPointerBeenAddedToCurrentRentsOfClient = true;
                break;
            }
        }
        BOOST_TEST(hasPointerBeenAddedToCurrentRentsOfClient);
        BOOST_TEST(vehicle->isRented());
    }

    ///@brief checks if Vehicle and Client objects states are updated after ending a rent( endRent() method ).
    BOOST_AUTO_TEST_CASE(EndRentTests){
        BOOST_REQUIRE_EQUAL(vehicle->isRented(), false);
        BOOST_REQUIRE_EQUAL(client->getCurrentRents().size(), 0);
        Rent rent(rentID, client, vehicle, pt::not_a_date_time);
        BOOST_REQUIRE_EQUAL(vehicle->isRented(), true);
        BOOST_REQUIRE_EQUAL(client->getCurrentRents().size(), 1);
        rent.endRent(pt::not_a_date_time);
        BOOST_TEST(vehicle->isRented() == false);
        BOOST_TEST(client->getCurrentRents().size() == 0);
    }

    ///@brief checks if rent time is calculated properly when provided endTime - provided beginTime is a positive integer.
    BOOST_AUTO_TEST_CASE(ConstructorValidTimeTests){
        BOOST_REQUIRE_EQUAL(vehicle->isRented(), false);
        pt::ptime now = pt::second_clock::local_time();
        pt::ptime customBeginTimeInThePast = now - pt::hours(1);
        // Here we're going for custom behaviour, vehicle was rented before entering data in the system, so beginTime is in the past
        Rent rent(rentID, client, vehicle, customBeginTimeInThePast);
        BOOST_TEST(rent.getBeginTime() == customBeginTimeInThePast);
        // endTime is not specified, so we expect it to be set to current time
        rent.endRent(pt::not_a_date_time);
        BOOST_TEST(rent.getEndTime() == now);

        // This time endTime will be set manually, but beginTime will be in the future;
        pt::ptime customBeginTimeInTheFuture = now + pt::hours(1);
        pt::ptime customEndTimeInTheFuture = now + pt::hours(5);
        BOOST_REQUIRE_EQUAL(vehicle->isRented(), false);
        Rent rent2(rentID, client, vehicle, customBeginTimeInTheFuture);
        BOOST_TEST(rent2.getBeginTime() == customBeginTimeInTheFuture);
        rent2.endRent(customEndTimeInTheFuture);
        BOOST_TEST(rent2.getEndTime() == customEndTimeInTheFuture);

    }

    ///@brief checks if rent time is calculated properly when provided endTime - provided beginTime is a a negative integer.
    BOOST_AUTO_TEST_CASE(ConstructorInvalidTimeTests){
        BOOST_REQUIRE_EQUAL(vehicle->isRented(), false);
        pt::ptime now = pt::second_clock::local_time();
        pt::ptime customBeginTime = now + pt::hours(1);
        pt::ptime incorrectEndTimeInThePast = now - pt::hours(5);
        Rent rent(rentID, client, vehicle, customBeginTime);
        rent.endRent(incorrectEndTimeInThePast);
        BOOST_TEST(rent.getEndTime() == rent.getBeginTime());
    }

    //@brief checks if system allows to change rent time, which it shouldn't
    BOOST_AUTO_TEST_CASE(DoubleEndRentTests){
        BOOST_REQUIRE_EQUAL(vehicle->isRented(), false);
        Rent rent(rentID, client, vehicle, pt::not_a_date_time);
        rent.endRent(pt::not_a_date_time);
        pt::ptime endTime = rent.getEndTime();
        rent.endRent(pt::second_clock::local_time() + pt::hours(3));
        BOOST_TEST(endTime == rent.getEndTime());
    }

    ///@brief checks if rent days are calculated properly as per business logic requirements.
    BOOST_AUTO_TEST_CASE(GetRentDaysTests){
        pt::ptime now = pt::second_clock::local_time();

        BOOST_REQUIRE_EQUAL(vehicle->isRented(), false);
        Rent rentCancelled(rentID, client, vehicle, now);
        BOOST_TEST(rentCancelled.getRentDays() == 0);
        rentCancelled.endRent(now - pt::hours(1));
        BOOST_TEST(rentCancelled.getRentDays() == 0);

        BOOST_REQUIRE_EQUAL(vehicle->isRented(), false);
        Rent rentFor59Seconds(rentID, client, vehicle, now);
        rentFor59Seconds.endRent(now + pt::seconds(59));
        BOOST_TEST(rentFor59Seconds.getRentDays() == 0);

        BOOST_REQUIRE_EQUAL(vehicle->isRented(), false);
        Rent rentForAMinute(rentID, client, vehicle, now);
        rentForAMinute.endRent(now + pt::seconds(60));
        BOOST_TEST(rentForAMinute.getRentDays() == 1);

        BOOST_REQUIRE_EQUAL(vehicle->isRented(), false);
        Rent rentForSixHours(rentID, client, vehicle, now);
        rentForSixHours.endRent(now + pt::hours(6));
        BOOST_TEST(rentForSixHours.getRentDays() == 1);

        BOOST_REQUIRE_EQUAL(vehicle->isRented(), false);
        Rent rentForAlmostADay(rentID, client, vehicle, now);
        rentForSixHours.endRent(now + pt::hours(23) + pt::minutes(59) + pt::seconds(59));
        BOOST_TEST(rentForSixHours.getRentDays() == 1);

        BOOST_REQUIRE_EQUAL(vehicle->isRented(), false);
        Rent rentFor24Hours(rentID, client, vehicle, now);
        rentFor24Hours.endRent(now + pt::hours(24));
        BOOST_TEST(rentFor24Hours.getRentDays() == 2);
    }

    ///@brief checks if rent cost is calculated properly as per business logic requirements
    BOOST_AUTO_TEST_CASE(GetRentCostTests){
        pt::ptime now = pt::second_clock::local_time();

        BOOST_REQUIRE_EQUAL(vehicle->isRented(), false);
        Rent rentFor59Seconds(rentID, client, vehicle, now);
        rentFor59Seconds.endRent(now + pt::seconds(59));
        BOOST_TEST(rentFor59Seconds.getRentCost() == 0);

        Rent rentForSixHours(rentID, client, vehicle, now);
        rentForSixHours.endRent(now + pt::hours(6));
        BOOST_TEST(rentForSixHours.getRentCost() == vehicle->getBasePrice());

        client->setType(bronze);
        BOOST_TEST(rentForSixHours.getRentCost() == vehicle->getBasePrice());
        Rent rentForTenHours(rentID, client, vehicle, now);
        rentForTenHours.endRent(now + pt::hours(10));
        BOOST_TEST(rentForTenHours.getRentCost() == vehicle->getBasePrice() - 3);

    }

BOOST_AUTO_TEST_SUITE_END()