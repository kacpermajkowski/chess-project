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

    ///@brief Checks if Rent getters return expected values after setting them via constructor and if Rent* is added to currentRents of Client
    BOOST_AUTO_TEST_CASE(RentConstrutorTests){
        Rent rent(rentID, client, vehicle);
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
    }

BOOST_AUTO_TEST_SUITE_END()