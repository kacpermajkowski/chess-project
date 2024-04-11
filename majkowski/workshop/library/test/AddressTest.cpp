#include <boost/test/unit_test.hpp>
#include "../include/model/Address.h"

BOOST_AUTO_TEST_SUITE(TestSuiteAddress)

    Address address("Łódź", "Piotrkowska", "17");
    ///@brief Checks if Client getters return expected values after setting them via constructor
    BOOST_AUTO_TEST_CASE(AddressConstrutorTests){
        BOOST_TEST(address.getCity() == "Łódź");
        BOOST_TEST(address.getStreet() == "Piotrkowska");
        BOOST_TEST(address.getNumber() =="17");
    }

    ///@brief Checks if using setters changes value returned by getters
    BOOST_AUTO_TEST_CASE(AddressSettersTests){
        address.setCity("Warszawa");
        address.setStreet("Srebrna");
        address.setNumber("30");
        BOOST_TEST(address.getCity() == "Warszawa");
        BOOST_TEST(address.getStreet() == "Srebrna");
        BOOST_TEST(address.getNumber() == "30");
    }

BOOST_AUTO_TEST_SUITE_END()