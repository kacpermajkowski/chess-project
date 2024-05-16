//
// Created by ola on 15.05.2024.
//

#include "model/Silver.h"

Silver::Silver() {}
Silver::~Silver() {}


unsigned int Silver::getMaxVehicles() const {
    return 3;
}

double Silver::applyDiscount(double price) {
    return price - 6;
}

std::string Silver::getInfo() const {
    return "Max vehicles: " + std::to_string(getMaxVehicles());
}
