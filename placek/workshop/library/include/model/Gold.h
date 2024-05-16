//
// Created by ola on 15.05.2024.
//

#ifndef CARRENTAL_GOLD_H
#define CARRENTAL_GOLD_H


#include "ClientType.h"

class Gold : public ClientType{
public:
    Gold();
    ~Gold();

    unsigned int getMaxVehicles() const override;
    double applyDiscount(double price) override;
    std::string getInfo() const override;
};


#endif //CARRENTAL_GOLD_H
