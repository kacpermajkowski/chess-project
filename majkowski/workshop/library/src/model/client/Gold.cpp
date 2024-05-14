//
// Created by szindzeks on 14.05.2024.
//

#include "model/client/Gold.h"

int Gold::getMaxVehicles() const {
    return ClientType::getMaxVehicles();
}

double Gold::applyDiscount(double price) {
    return price * 0.95;
}

std::string Gold::getInfo() {
    return ClientType::getInfo();
}

Gold::Gold() : ClientType(4) {

}
