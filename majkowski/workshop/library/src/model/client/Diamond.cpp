//
// Created by szindzeks on 14.05.2024.
//

#include "model/client/Diamond.h"

int Diamond::getMaxVehicles() const {
    return ClientType::getMaxVehicles();
}

double Diamond::applyDiscount(double price) {
    double multiplier = 1.0;
    if(price > 0 && price <= 125){
        multiplier = 0.9;
    } else if (price > 125 && price <= 250) {
        multiplier = 0.8;
    } else if (price > 250 && price <= 500) {
        multiplier = 0.7;
    } else if(price > 500){
        multiplier = 0.6;
    }
    return price * multiplier;
}

std::string Diamond::getInfo() {
    return ClientType::getInfo();
}

Diamond::Diamond() : ClientType(10) {

}
