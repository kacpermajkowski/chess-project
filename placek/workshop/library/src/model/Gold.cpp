//
// Created by ola on 15.05.2024.
//

#include <sstream>
#include "model/Gold.h"

Gold::Gold() {}
Gold::~Gold() {}

unsigned int Gold::getMaxVehicles() const {
    return 4;
}

double Gold::applyDiscount(double price) {
    return 0.95 * price;
}

std::string Gold::getInfo() const {
    return "Max vehicles: " + std::to_string(getMaxVehicles());
}



