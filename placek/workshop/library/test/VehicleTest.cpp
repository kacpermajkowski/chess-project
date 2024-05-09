#include <boost/test/unit_test.hpp>
#include "model/Vehicle.h"

BOOST_AUTO_TEST_SUITE(TestSuiteVehicle)

    Vehicle vehicle("12345", 1500);
    BOOST_AUTO_TEST_CASE(TestConstructorVehicle){
        BOOST_TEST(vehicle.getPlateNumber()=="12345");
        BOOST_TEST(vehicle.getBasePrice()==1500);
    }

    BOOST_AUTO_TEST_CASE(TestSettersVehicle){
        vehicle.setPlateNumber("67890");
        vehicle.setBasePrice(4000);

        vehicle.setPlateNumber("");

        BOOST_TEST(vehicle.getPlateNumber()=="67890");
        BOOST_TEST(vehicle.getBasePrice()==4000);
    }

BOOST_AUTO_TEST_SUITE_END()
