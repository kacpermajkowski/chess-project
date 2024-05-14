//
// Created by szindzeks on 11.05.2024.
//

#include "../../include/model/Moped.h"

Moped::Moped(const std::string &plateNumber, unsigned int basePrice, int engineDisplacement) :
    MotorVehicle(plateNumber,basePrice,engineDisplacement) {

}

const unsigned int Moped::getActualRentalPrice() const {
    return MotorVehicle::getActualRentalPrice();
}

std::string Moped::getInfo() const {
    return MotorVehicle::getInfo();
}
