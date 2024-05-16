//
// Created by ola on 15.05.2024.
//

#ifndef CARRENTAL_DEFAULT_H
#define CARRENTAL_DEFAULT_H


#include "ClientType.h"

class Default : public ClientType{
public:
    Default();
    ~Default();

    unsigned int getMaxVehicles() const override;
    double applyDiscount(double price) override;
    std::string getInfo() const override;
};


#endif //CARRENTAL_DEFAULT_H
