#include <boost/test/unit_test.hpp>
#include "model/Bicycle.h"
#include "model/MotorVehicle.h"
#include "model/Car.h"
#include "model/Moped.h"
#include "typedefs.h"

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

    BOOST_AUTO_TEST_CASE(VehicleActualPriceTests){
        VehiclePtr vehicle = new Vehicle("E", 1000);
        VehiclePtr bicycle = new Bicycle("E", 1000);
        VehiclePtr motorVehicle1 = new MotorVehicle("E", 1000, 500);
        VehiclePtr motorVehicle2 = new MotorVehicle("E", 1000, 1000);
        VehiclePtr motorVehicle3 = new MotorVehicle("E", 1000, 1340);
        VehiclePtr motorVehicle4 = new MotorVehicle("E", 1000, 2000);
        VehiclePtr motorVehicle5 = new MotorVehicle("E", 1000, 2001);
        VehiclePtr moped = new Moped("E", 1000, 330);
        VehiclePtr car1 = new Car("E", 1000, 2500, A);
        VehiclePtr car2 = new Car("E", 1000, 2500, B);
        VehiclePtr car3 = new Car("E", 1000, 2500, C);
        VehiclePtr car4 = new Car("E", 1000, 2500, D);
        VehiclePtr car5 = new Car("E", 1000, 2500, E);

        BOOST_TEST(vehicle->getActualRentalPrice() == vehicle->getBasePrice());
        BOOST_TEST(bicycle->getActualRentalPrice() == bicycle->getBasePrice());
        BOOST_TEST(motorVehicle1->getActualRentalPrice() == (int)(motorVehicle1->getBasePrice() * 1.0));
        BOOST_TEST(motorVehicle2->getActualRentalPrice() == (int)(motorVehicle2->getBasePrice() * 1.0));
        BOOST_TEST(motorVehicle3->getActualRentalPrice() == (int)(motorVehicle3->getBasePrice() * 1.17));
        BOOST_TEST(motorVehicle4->getActualRentalPrice() == (int)(motorVehicle4->getBasePrice() * 1.5));
        BOOST_TEST(motorVehicle5->getActualRentalPrice() == (int)(motorVehicle5->getBasePrice() * 1.5));
        BOOST_TEST(moped->getActualRentalPrice() == moped->getBasePrice());
        BOOST_TEST(car1->getActualRentalPrice() == (int)(car1->getBasePrice() * 1.5 *  1.0));
        BOOST_TEST(car2->getActualRentalPrice() == (int)(car2->getBasePrice() * 1.5 *  1.1));
        BOOST_TEST(car3->getActualRentalPrice() == (int)(car3->getBasePrice() * 1.5 *  1.2));
        BOOST_TEST(car4->getActualRentalPrice() == (int)(car4->getBasePrice() * 1.5 *  1.3));
        BOOST_TEST(car5->getActualRentalPrice() == (int)(car5->getBasePrice() * 1.5 *  1.5));



        delete vehicle;
        delete bicycle;
        delete motorVehicle1;
        delete motorVehicle2;
        delete motorVehicle3;
        delete motorVehicle4;
        delete motorVehicle5;
        delete moped;
        delete car1;
        delete car2;
        delete car3;
        delete car4;
        delete car5;
    }


BOOST_AUTO_TEST_SUITE_END()