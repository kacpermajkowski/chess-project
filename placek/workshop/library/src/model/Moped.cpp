//
// Created by ola on 14.05.2024.
//

#include "model/Moped.h"

Moped::Moped(const std::string &plateNumber, unsigned int basePrice, unsigned int engineDisplacement) : MotorVehicle(
        plateNumber, basePrice, engineDisplacement) {}

double Moped::getActualRentalPrice() const {
    return MotorVehicle::getActualRentalPrice();
}

std::string Moped::getInfo() const {
    return MotorVehicle::getInfo();
}
