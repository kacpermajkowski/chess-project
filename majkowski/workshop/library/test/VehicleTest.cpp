#include <boost/test/unit_test.hpp>
#include "model/Vehicle.h"

BOOST_AUTO_TEST_SUITE(TestSuiteVehicle)

    std::string plateNumber1 = "EZD 2137";
    unsigned int basePrice1 = 1337;
    Vehicle vehicle(plateNumber1, basePrice1);
    ///@brief Checks if Vehicle getters return expected values after setting them via constructor.
    BOOST_AUTO_TEST_CASE(VehicleConstrutorTests){
        BOOST_TEST(vehicle.getBasePrice() == basePrice1);
        BOOST_TEST(vehicle.getPlateNumber() == plateNumber1);
    }

    std::string plateNumber2 = "EL 666P";
    unsigned int basePrice2 = 1000;
    ///@brief Checks if using Vehicle setters changes value returned by getters.
    BOOST_AUTO_TEST_CASE(VehicleSettersTests){
        vehicle.setPlateNumber(plateNumber2);
        vehicle.setBasePrice(basePrice2);
        BOOST_TEST(vehicle.getBasePrice() == basePrice2);
        BOOST_TEST(vehicle.getPlateNumber() == plateNumber2);
    }

    ///@brief Checks if string values remain unchanged if set to empty string.
    BOOST_AUTO_TEST_CASE(VehicleSettersEmptyStringTests){
        vehicle.setPlateNumber("");
        BOOST_TEST(vehicle.getPlateNumber() == plateNumber2);
    }


BOOST_AUTO_TEST_SUITE_END()