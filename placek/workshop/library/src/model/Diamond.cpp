//
// Created by ola on 15.05.2024.
//

#include <sstream>
#include "model/Diamond.h"

Diamond::Diamond() {}
Diamond::~Diamond() {}

unsigned int Diamond::getMaxVehicles() const {
    return 10;
}

double Diamond::applyDiscount(double price) {
    double discount = 1.0;
    if(price > 0 && price <= 125) {
        discount = 0.9;
    } else if (price > 125 && price <= 250){
        discount = 0.8;
    } else if (price > 250 && price <= 500){
        discount = 0.7;
    } else if  (price > 500){
        discount = 0.6;
    }

    return price * discount;
}

std::string Diamond::getInfo() const {
    return "Max vehicles: " + std::to_string(getMaxVehicles());
}



