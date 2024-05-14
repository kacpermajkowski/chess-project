//
// Created by szindzeks on 11.05.2024.
//

#include "../../include/model/Car.h"

Car::Car(const std::string &plateNumber, unsigned int basePrice, int engineDisplacement, SegmentType segment):
        MotorVehicle(plateNumber, basePrice, engineDisplacement),
        segment(segment) {
}

const unsigned int Car::getActualRentalPrice() const {
    return MotorVehicle::getActualRentalPrice() * segment / 10;
}
