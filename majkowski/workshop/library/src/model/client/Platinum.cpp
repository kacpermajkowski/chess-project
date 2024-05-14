//
// Created by szindzeks on 14.05.2024.
//

#include "model/client/Platinum.h"

int Platinum::getMaxVehicles() const {
    return ClientType::getMaxVehicles();
}

double Platinum::applyDiscount(double price) {
    return price * 0.9;
}

std::string Platinum::getInfo() {
    return ClientType::getInfo();
}

Platinum::Platinum() : ClientType(5) {

}
