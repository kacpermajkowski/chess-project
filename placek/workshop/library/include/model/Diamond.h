//
// Created by ola on 15.05.2024.
//

#ifndef CARRENTAL_DIAMOND_H
#define CARRENTAL_DIAMOND_H


#include "ClientType.h"

class Diamond : public ClientType{
public:
    Diamond();
    ~Diamond();

    unsigned int getMaxVehicles() const override;
    double applyDiscount(double price) override;
    std::string getInfo() const override;
};


#endif //CARRENTAL_DIAMOND_H
