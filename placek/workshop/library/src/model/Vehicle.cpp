#include "model/Vehicle.h"
#include <iostream>

Vehicle::Vehicle(const std::string &plateNumber, unsigned int basePrice)
:
    plateNumber(plateNumber),
    basePrice(basePrice)
{}

Vehicle::~Vehicle(){}

std::string Vehicle::getInfo() const{
    return plateNumber + " " + std::to_string(basePrice);
}

const std::string &Vehicle::getPlateNumber() const{
    return plateNumber;
}

unsigned int Vehicle::getBasePrice() const{
    return basePrice;
}

bool Vehicle::isRented() const{
    return rented;
}

void Vehicle::setPlateNumber(const std::string &plateNumber){
    if(plateNumber != ""){
        Vehicle::plateNumber = plateNumber;
    }
}
void Vehicle::setBasePrice(unsigned int basePrice){
    Vehicle::basePrice = basePrice;
}
void Vehicle::setRented(bool rented){
    Vehicle::rented = rented;
}

double Vehicle::getActualRentalPrice() const {
    return getBasePrice();
}

