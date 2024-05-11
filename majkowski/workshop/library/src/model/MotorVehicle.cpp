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
