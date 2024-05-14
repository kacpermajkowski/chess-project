//
// Created by ola on 14.05.2024.
//

#include <sstream>
#include "model/Car.h"

Car::Car(const std::string &plateNumber, unsigned int basePrice, unsigned int engineDisplacement, SegmentType segment)
        : MotorVehicle(plateNumber, basePrice, engineDisplacement), segment(segment) {}

SegmentType Car::getSegment() const {
    return segment;
}

void Car::setSegment(SegmentType segment) {
    Car::segment = segment;
}

double Car::getActualRentalPrice() const {
    double q = static_cast<double>(segment) / 10;
    return MotorVehicle::getActualRentalPrice() * q;
}

std::string Car::getInfo() const {
    std::ostringstream ss;
    ss << MotorVehicle::getInfo();
    ss << " segment: " << segment;
    return ss.str();
}
