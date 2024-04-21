#include <boost/test/unit_test.hpp>
#include "model/Address.h"

BOOST_AUTO_TEST_SUITE(TestSuiteAddress)

Address address("Poznan","Ogrodowa","17");
BOOST_AUTO_TEST_CASE(TestConstructorAddress){
    BOOST_TEST(address.getCity()=="Poznan");
    BOOST_TEST(address.getStreet()=="Ogrodowa");
    BOOST_TEST(address.getHouseNumber()=="17");
}

/*BOOST_AUTO_TEST_CASE(TestSettersAddress){
    address.setCity("Szczecin");
    address.setStreet("Parkowa");
    address.setHouseNumber("21");
        address.setCity("");
        address.setStreet("");
        address.setHouseNumber("");
    BOOST_TEST(address.getCity()=="Szczecin");
    BOOST_TEST(address.getStreet()=="Parkowa");
    BOOST_TEST(address.getHouseNumber()=="21");

}*/

BOOST_AUTO_TEST_SUITE_END()
