//
// Created by szindzeks on 11.05.2024.
//

#include "../../include/model/MotorVehicle.h"

int MotorVehicle::getEngineDisplacement() const {
    return engineDisplacement;
}

void MotorVehicle::setEngineDisplacement(int engineDisplacement) {
    MotorVehicle::engineDisplacement = engineDisplacement;
}

MotorVehicle::MotorVehicle(const std::string &plateNumber, unsigned int basePrice, int engineDisplacement) :
    Vehicle(plateNumber, basePrice),
    engineDisplacement(engineDisplacement) {

}

const unsigned int MotorVehicle::getActualRentalPrice() const {
    double multiplier;
    if(engineDisplacement < 1000) {
        multiplier = 1.0;
    } else if(engineDisplacement > 2000) {
        multiplier = 1.5;
    } else {
        double linearScalingMultiplier = ((double)engineDisplacement - 1000.0) / 1000.0;
        multiplier = 1.0 + (0.5 * linearScalingMultiplier);
    }

    return getBasePrice() * multiplier;
}
