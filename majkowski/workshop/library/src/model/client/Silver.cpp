//
// Created by szindzeks on 14.05.2024.
//

#include <sstream>
#include "model/client/Silver.h"

int Silver::getMaxVehicles() const {
    return 3;
}

double Silver::applyDiscount(double price) {
    return price - 6;
}

std::string Silver::getInfo() {
    std::ostringstream ss;
    ss << "Max vehicles: " << getMaxVehicles() << std::endl;
    return ss.str();
}

Silver::Silver() {

}

Silver::~Silver() {

}
