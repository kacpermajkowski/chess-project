#include <boost/test/unit_test.hpp>
#include "model/Rent.h"
#include "model/Client.h"
#include "model/Vehicle.h"

struct TestSuiteRentFixture{
    Client* client;
    Address* address;
    Vehicle* vehicle;
    unsigned int rentID;

    TestSuiteRentFixture(){
        address = new Address("Poznan", "Ogrodowa", "15");
        client = new Client("Adam", "Nowak", "123", address);
        vehicle = new Vehicle("GD12345", 600);
        rentID = 1;
    }
    ~TestSuiteRentFixture(){
        delete address;
        delete client;
        delete vehicle;
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRent, TestSuiteRentFixture)

    BOOST_AUTO_TEST_CASE(TestConstructorRent){
    Rent rent(rentID, client, vehicle);
        BOOST_TEST(rent.getId()==rentID);
        BOOST_TEST(rent.getClient()==client);
        BOOST_TEST(rent.getVehicle()==vehicle);
        BOOST_TEST(vehicle->isRented()==true);
}

    BOOST_AUTO_TEST_CASE(TestPointerRent){
    Rent rent(rentID, client, vehicle);
    bool isPointerAddedToClient = false;
    for (const Rent* r : client->getCurrentRents()){
        if (r == &rent) {
            isPointerAddedToClient = true;
            break;
        }
    }
        BOOST_TEST(isPointerAddedToClient == true);
}


BOOST_AUTO_TEST_SUITE_END()