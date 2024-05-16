//
// Created by szindzeks on 16.05.2024.
//

#include <sstream>
#include "model/client/Default.h"

int Default::getMaxVehicles() const {
    return 1;
}

double Default::applyDiscount(double price) {
    return price;
}

std::string Default::getInfo() {
    std::ostringstream ss;
    ss << "Max vehicles: " << getMaxVehicles() << std::endl;
    return ss.str();
}

Default::Default() {}

Default::~Default() = default;
