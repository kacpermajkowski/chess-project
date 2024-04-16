#include <boost/test/unit_test.hpp>
#include "../include/model/Client.h"

struct TestSuiteClientFixture{
    const std::string testFirstName = "Kacper";
    const std::string testLastName = "Majkowski";
    const std::string testPersonalID = "251578";

    const std::string newTestFirstName = "Robert";
    const std::string newTestLastName = "Rządziński";

    Address *testAddress;
    Address *newTestAddress;

    TestSuiteClientFixture(){
        testAddress = new Address("Warszawa", "Srebrna", "17");
        newTestAddress = new Address("Łódź", "al. Politechniki", "22");
    }

    ~TestSuiteClientFixture(){
        delete testAddress;
        delete newTestAddress;
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

    ///@brief Example assertion tests
    BOOST_AUTO_TEST_CASE(AssertionsTests) {
        BOOST_TEST(1.0/3.0 == 0.333, boost::test_tools::tolerance(0.0011));
        BOOST_TEST(true);
    }

    ///@brief Checks if Client getters return expected values after setting them via constructor
    BOOST_AUTO_TEST_CASE(ClientConstrutorTests){
        Client client(testFirstName, testLastName, testPersonalID, testAddress);
        BOOST_TEST(client.getFirstName() == testFirstName);
        BOOST_TEST(client.getLastName() == testLastName);
        BOOST_TEST(client.getPersonalID() == testPersonalID);
        BOOST_TEST(client.getAddress() == testAddress);
    }

    ///@brief Checks if using setters changes value returned by getters
    BOOST_AUTO_TEST_CASE(ClientSettersTests){
        Client client(testFirstName, testLastName, testPersonalID, testAddress);
        client.setFirstName(newTestFirstName);
        client.setLastName(newTestLastName);
        client.setAddress(newTestAddress);
        BOOST_TEST(client.getFirstName() == newTestFirstName);
        BOOST_TEST(client.getLastName() == newTestLastName);
        BOOST_TEST(client.getAddress() == newTestAddress);
    }

    ///@brief Checks if getters still return the same value after using setters with empty string param
    BOOST_AUTO_TEST_CASE(ClientSettersEmptyStringTests){
        Client client(testFirstName, testLastName, testPersonalID, testAddress);
        std::string firstName = client.getFirstName();
        std::string lastName = client.getLastName();
        client.setFirstName("");
        client.setLastName("");
        BOOST_TEST(client.getFirstName() == firstName);
        BOOST_TEST(client.getLastName() == lastName);
    }

BOOST_AUTO_TEST_SUITE_END()