//
// Created by szindzeks on 04.05.2024.
//

#include <string>
#include "model/Vehicle.h"

Vehicle::Vehicle(const std::string &plateNumber, unsigned int basePrice) : plateNumber(
        plateNumber), basePrice(basePrice) {}

void Vehicle::setPlateNumber(const std::string &plateNumber) {
    if(plateNumber != "")
        Vehicle::plateNumber = plateNumber;
}

void Vehicle::setBasePrice(unsigned int basePrice) {
    Vehicle::basePrice = basePrice;
}

const std::string &Vehicle::getPlateNumber() const {
    return plateNumber;
}

const unsigned int Vehicle::getBasePrice() const {
    return basePrice;
}
