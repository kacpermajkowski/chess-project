//
// Created by ola on 14.05.2024.
//

#include "model/Bicycle.h"

Bicycle::Bicycle(const std::string &plateNumber, unsigned int basePrice) :
    Vehicle(plateNumber, basePrice) {

}

std::string Bicycle::getInfo() const {
    return Vehicle::getInfo();
}

double Bicycle::getActualRentalPrice() const {
    return Vehicle::getActualRentalPrice();
}



