//
// Created by szindzeks on 14.05.2024.
//

#include <sstream>
#include "model/client/Platinum.h"

int Platinum::getMaxVehicles() const {
    return 5;
}

double Platinum::applyDiscount(double price) {
    return price * 0.9;
}

std::string Platinum::getInfo() {
    std::ostringstream ss;
    ss << "Max vehicles: " << getMaxVehicles() << std::endl;
    return ss.str();
}

Platinum::Platinum() {

}

Platinum::~Platinum() {

}
