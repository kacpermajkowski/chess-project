//
// Created by ola on 15.05.2024.
//

#include "model/Platinum.h"

Platinum::Platinum() {}
Platinum::~Platinum() {}

unsigned int Platinum::getMaxVehicles() const {
    return 5;
}

double Platinum::applyDiscount(double price) {
    return 0.90 * price;
}

std::string Platinum::getInfo() const {
    return "Max vehicles: " + std::to_string(getMaxVehicles());
}





