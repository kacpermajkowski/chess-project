#include <boost/test/unit_test.hpp>
#include "../include/model/Client.h"

struct TestSuiteClientFixture{
    const std::string testFirstName = "Kacper";
    const std::string testLastName = "Majkowski";
    const std::string testPersonalID = "251578";

    const std::string newTestFirstName = "Robert";
    const std::string newTestLastName = "Rządziński";

    AddressPtr testAddress;
    AddressPtr newTestAddress;

    VehiclePtr testVehicle;

    TestSuiteClientFixture(){
        testAddress = new Address("Warszawa", "Srebrna", "17");
        newTestAddress = new Address("Łódź", "al. Politechniki", "22");
        testVehicle = new Vehicle("EZD 10000", 1234);
    }

    ~TestSuiteClientFixture(){
        delete testAddress;
        delete newTestAddress;
        delete testVehicle;
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

    ///@brief Checks if Client getters return expected values after setting them via constructor.
    BOOST_AUTO_TEST_CASE(ClientConstrutorTests){
        Client client(testFirstName, testLastName, testPersonalID, testAddress, nullptr);
        BOOST_TEST(client.getFirstName() == testFirstName);
        BOOST_TEST(client.getLastName() == testLastName);
        BOOST_TEST(client.getPersonalID() == testPersonalID);
        BOOST_TEST(client.getAddress() == testAddress);
    }

    ///@brief Checks if using setters changes value returned by getters.
    BOOST_AUTO_TEST_CASE(ClientSettersTests){
        Client client(testFirstName, testLastName, testPersonalID, testAddress, nullptr);
        client.setFirstName(newTestFirstName);
        client.setLastName(newTestLastName);
        client.setAddress(newTestAddress);
        BOOST_TEST(client.getFirstName() == newTestFirstName);
        BOOST_TEST(client.getLastName() == newTestLastName);
        BOOST_TEST(client.getAddress() == newTestAddress);
    }

    ///@brief Checks if getters still return the same value after using setters with empty string param.
    BOOST_AUTO_TEST_CASE(ClientSettersEmptyStringTests){
        Client client(testFirstName, testLastName, testPersonalID, testAddress, nullptr);
        std::string firstName = client.getFirstName();
        std::string lastName = client.getLastName();
        client.setFirstName("");
        client.setLastName("");
        BOOST_TEST(client.getFirstName() == firstName);
        BOOST_TEST(client.getLastName() == lastName);
    }

    ///@brief checks if accessors of vector<RentPtr> currentRents work as expected.
    BOOST_AUTO_TEST_CASE(ClientCurrentRentsAccessorsTests){
        ClientPtr client = new Client(testFirstName, testLastName, testPersonalID, testAddress, nullptr);
        Rent rent(132, client, testVehicle, pt::not_a_date_time);
        client->removeRent(&rent);
        BOOST_TEST(client->getCurrentRents().size() == 0);
        Rent rent2(133, client, testVehicle, pt::not_a_date_time);
        BOOST_TEST(client->getCurrentRents().size() == 1);
        BOOST_TEST(client->getCurrentRents()[0]->getId() == 133);
        client->removeRent(rent2.getId());
        BOOST_TEST(client->getCurrentRents().size() == 0);
        delete client;
    }

BOOST_AUTO_TEST_SUITE_END()