//
// Created by ola on 15.05.2024.
//

#include <sstream>
#include "model/Default.h"

Default::Default() {}
Default::~Default() {
}


unsigned int Default::getMaxVehicles() const {
    return 1;
}

double Default::applyDiscount(double price) {
    return price;
}

std::string Default::getInfo() const {
    return "Max vehicles: " + std::to_string(getMaxVehicles());
}



