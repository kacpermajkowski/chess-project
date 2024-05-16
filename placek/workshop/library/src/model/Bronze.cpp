//
// Created by ola on 15.05.2024.
//

#include <sstream>
#include "model/Bronze.h"

Bronze::Bronze() {}
Bronze::~Bronze() {}


unsigned int Bronze::getMaxVehicles() const {
    return 2;
}

double Bronze::applyDiscount(double price) {
    return price - 3;
}

std::string Bronze::getInfo() const {
    return "Max vehicles: " + std::to_string(getMaxVehicles());
}
