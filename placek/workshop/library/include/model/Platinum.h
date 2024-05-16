//
// Created by ola on 15.05.2024.
//

#ifndef CARRENTAL_PLATINUM_H
#define CARRENTAL_PLATINUM_H

#include <string>
#include "ClientType.h"

class Platinum : public ClientType{
public:
    Platinum();
    ~Platinum();

    unsigned int getMaxVehicles() const override;
    double applyDiscount(double price) override;
    std::string getInfo() const override;
};


#endif //CARRENTAL_PLATINUM_H
