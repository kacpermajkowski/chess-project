#include <boost/test/unit_test.hpp>
#include "../include/model/Client.h"

BOOST_AUTO_TEST_SUITE(TestSuiteClient)

    BOOST_AUTO_TEST_CASE(AssertionsTests) {
        BOOST_TEST(1.0/3.0 == 0.333, boost::test_tools::tolerance(0.0011));
        BOOST_TEST(true);
    }

    Client client("Kacper", "Majkowski", "251578");
    BOOST_AUTO_TEST_CASE(ClientConstrutorTests){
        BOOST_TEST(client.getFirstName() == "Kacper");
        BOOST_TEST(client.getLastName() == "Majkowski");
        BOOST_TEST(client.getPerosnalID() == "251578");
    }

    BOOST_AUTO_TEST_CASE(ClientSettersTests){
        client.setFirstName("Robert");
        client.setLastName("Rządziński");
        BOOST_TEST(client.getFirstName() == "Robert");
        BOOST_TEST(client.getLastName() == "Rządziński");
    }

    BOOST_AUTO_TEST_CASE(ClientSettersEmptyStringTests){
        std::string firstName = client.getFirstName();
        std::string lastName = client.getLastName();
        client.setFirstName("");
        client.setLastName("");
        BOOST_TEST(client.getFirstName() == firstName);
        BOOST_TEST(client.getLastName() == lastName);
    }



BOOST_AUTO_TEST_SUITE_END()