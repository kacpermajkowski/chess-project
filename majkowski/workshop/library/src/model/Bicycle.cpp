//
// Created by szindzeks on 11.05.2024.
//

#include "../../include/model/Bicycle.h"

Bicycle::Bicycle(const std::string &plateNumber, unsigned int basePrice) :
    Vehicle(plateNumber, basePrice){

}

const unsigned int Bicycle::getActualRentalPrice() const {
    return Vehicle::getActualRentalPrice();
}

std::string Bicycle::getInfo() const {
    return Vehicle::getInfo();
}
