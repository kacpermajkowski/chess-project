//
// Created by ola on 15.05.2024.
//

#ifndef CARRENTAL_BRONZE_H
#define CARRENTAL_BRONZE_H


#include "ClientType.h"

class Bronze : public ClientType{

    Bronze();
    ~Bronze();

    unsigned int getMaxVehicles() const override;
    double applyDiscount(double price) override;
    std::string getInfo() const override;
};


#endif //CARRENTAL_BRONZE_H
