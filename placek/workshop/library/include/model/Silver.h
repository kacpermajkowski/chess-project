//
// Created by ola on 15.05.2024.
//

#ifndef CARRENTAL_SILVER_H
#define CARRENTAL_SILVER_H


#include <string>
#include "ClientType.h"

class Silver : public ClientType{
public:
    Silver();
    ~Silver();

    unsigned int getMaxVehicles() const override;
    double applyDiscount(double price) override;
    std::string getInfo() const override;
};


#endif //CARRENTAL_SILVER_H
