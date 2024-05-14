//
// Created by szindzeks on 14.05.2024.
//

#include "model/client/Bronze.h"

int Bronze::getMaxVehicles() const {
    return ClientType::getMaxVehicles();
}

double Bronze::applyDiscount(double price) {
    return price - 3;
}

std::string Bronze::getInfo() {
    return ClientType::getInfo();
}

Bronze::Bronze() : ClientType(2) {

}
