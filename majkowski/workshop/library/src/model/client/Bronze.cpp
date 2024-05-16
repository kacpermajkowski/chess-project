//
// Created by szindzeks on 14.05.2024.
//

#include <sstream>
#include "model/client/Bronze.h"

int Bronze::getMaxVehicles() const {
    return 2;
}

double Bronze::applyDiscount(double price) {
    return price - 3;
}

std::string Bronze::getInfo() {
    std::ostringstream ss;
    ss << "Max vehicles: " << getMaxVehicles() << std::endl;
    return ss.str();
}

Bronze::Bronze() = default;

Bronze::~Bronze() = default;

