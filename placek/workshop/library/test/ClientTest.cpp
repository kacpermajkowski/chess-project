#include <boost/test/unit_test.hpp>
#include "model/Client.h"

BOOST_AUTO_TEST_SUITE(TestSuiteClient)
/// \brief example tests
BOOST_AUTO_TEST_CASE(AssertionsTests) {
        BOOST_TEST(1.0/3.0 == 0.333, boost::test_tools::tolerance(0.01));
        BOOST_TEST(true);
}

Client client("Adam", "Nowak", "123");
/// \brief checks if getter returns correct value
BOOST_AUTO_TEST_CASE(TestConstructorClient){
    BOOST_TEST(client.getFirstName()=="Adam");
    BOOST_TEST(client.getLastName()=="Nowak");
    BOOST_TEST(client.getPersonalID()=="123");
}

/// \brief checks if setter sets correct value that cannot be empty
BOOST_AUTO_TEST_CASE(TestSettersClient){
    client.setFirstName("Jan");
    client.setLastName("Kowalski");
    client.setFirstName("");
    client.setLastName("");
    BOOST_TEST(client.getFirstName()=="Jan");
    BOOST_TEST(client.getLastName()=="Kowalski");
}

BOOST_AUTO_TEST_SUITE_END()
