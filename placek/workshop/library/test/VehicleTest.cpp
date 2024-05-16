#include <boost/test/unit_test.hpp>
#include "model/Vehicle.h"
#include "model/Bicycle.h"
#include "typedefs.h"

BOOST_AUTO_TEST_SUITE(TestSuiteVehicle)

    Bicycle bicycle("12345", 1500);
    BOOST_AUTO_TEST_CASE(TestConstructorBicycle){
        BOOST_TEST(bicycle.getPlateNumber() == "12345");
        BOOST_TEST(bicycle.getBasePrice() == 1500);
    }

    BOOST_AUTO_TEST_CASE(TestSettersBicycle){
        bicycle.setPlateNumber("67890");
        bicycle.setBasePrice(4000);

        bicycle.setPlateNumber("");

        BOOST_TEST(bicycle.getPlateNumber() == "67890");
        BOOST_TEST(bicycle.getBasePrice() == 4000);
    }

    BOOST_AUTO_TEST_CASE(TestActualRentalPrice){
        int price = 1000;
        //VehiclePtr
    }




BOOST_AUTO_TEST_SUITE_END()
