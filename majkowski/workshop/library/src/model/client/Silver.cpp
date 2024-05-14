//
// Created by szindzeks on 14.05.2024.
//

#include "model/client/Silver.h"

int Silver::getMaxVehicles() const {
    return ClientType::getMaxVehicles();
}

double Silver::applyDiscount(double price) {
    return price - 6;
}

std::string Silver::getInfo() {
    return ClientType::getInfo();
}

Silver::Silver() : ClientType(3) {

}
