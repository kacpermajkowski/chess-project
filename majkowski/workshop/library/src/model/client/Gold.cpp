//
// Created by szindzeks on 14.05.2024.
//

#include <sstream>
#include "model/client/Gold.h"

int Gold::getMaxVehicles() const {
    return 4;
}

double Gold::applyDiscount(double price) {
    return price * 0.95;
}

std::string Gold::getInfo() {
    std::ostringstream ss;
    ss << "Max vehicles: " << getMaxVehicles() << std::endl;
    return ss.str();
}

Gold::Gold() {

}

Gold::~Gold() {

}
