//
// Created by szindzeks on 14.05.2024.
//

#include <sstream>
#include "model/client/Diamond.h"

int Diamond::getMaxVehicles() const {
    return 10;
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
    std::ostringstream ss;
    ss << "Max vehicles: " << getMaxVehicles() << std::endl;
    return ss.str();
}

Diamond::Diamond() {

}

Diamond::~Diamond() {

}


