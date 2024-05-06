#include <boost/test/unit_test.hpp>
#include "model/Rent.h"
#include "model/Client.h"
#include "model/Vehicle.h"

struct TestSuiteRentFixture{
    Address* address;
    Client* client;
    Vehicle* vehicle;
    unsigned int rentID;

    TestSuiteRentFixture() {
        address = new Address("Łódź", "Piotrkowska", "17");
        client = new Client("Kacper", "Majkowski", "251578", address);
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

    ///@brief Checks if constructor initializes Vehicle fields correctly and modifies Client and Vehicle objects accordingly
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
        for(Rent* r: client->getCurrentRents()){
            if(r->getId() == rentID){
                hasPointerBeenAddedToCurrentRentsOfClient = true;
                break;
            }
        }
        BOOST_TEST(hasPointerBeenAddedToCurrentRentsOfClient);

        BOOST_TEST(vehicle->isRented());
    }

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

    BOOST_AUTO_TEST_CASE(ConstructorInvalidTimeTests){
        BOOST_REQUIRE_EQUAL(vehicle->isRented(), false);
        pt::ptime now = pt::second_clock::local_time();
        pt::ptime customBeginTime = now + pt::hours(1);
        pt::ptime incorrectEndTimeInThePast = now - pt::hours(5);
        Rent rent(rentID, client, vehicle, customBeginTime);
        rent.endRent(incorrectEndTimeInThePast);
        BOOST_TEST(rent.getEndTime() == rent.getBeginTime());
    }

    //@brief We're checking if system allows to change rent time, which it shouldn't
    BOOST_AUTO_TEST_CASE(DoubleEndRentTests){
        BOOST_REQUIRE_EQUAL(vehicle->isRented(), false);
        Rent rent(rentID, client, vehicle, pt::not_a_date_time);
        rent.endRent(pt::not_a_date_time);
        pt::ptime endTime = rent.getEndTime();
        rent.endRent(pt::second_clock::local_time() + pt::hours(3));
        BOOST_TEST(endTime == rent.getEndTime());
    }

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

    BOOST_AUTO_TEST_CASE(GetRentCostTests){
        pt::ptime now = pt::second_clock::local_time();

        BOOST_REQUIRE_EQUAL(vehicle->isRented(), false);
        Rent rentFor59Seconds(rentID, client, vehicle, now);
        rentFor59Seconds.endRent(now + pt::seconds(59));
        BOOST_TEST(rentFor59Seconds.getRentCost() == 0);

        Rent rentForSixHours(rentID, client, vehicle, now);
        rentForSixHours.endRent(now + pt::hours(6));
        BOOST_TEST(rentForSixHours.getRentCost() == vehicle->getBasePrice());

    }

BOOST_AUTO_TEST_SUITE_END()