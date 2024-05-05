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
    BOOST_AUTO_TEST_CASE(RentConstrutorTests){
        BOOST_REQUIRE_EQUAL(vehicle->isRented(), false);
        Rent rent(rentID, client, vehicle);
        BOOST_TEST(rent.getId() == rentID);
        BOOST_TEST(rent.getClient() == client);
        BOOST_TEST(rent.getVehicle() == vehicle);

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

BOOST_AUTO_TEST_SUITE_END()