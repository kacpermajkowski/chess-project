//
// Created by szindzeks on 16.05.2024.
//

#ifndef CARRENTAL_DEFAULT_H
#define CARRENTAL_DEFAULT_H


#include "model/ClientType.h"

class Default : public ClientType{
public:
    Default();

    ~Default();

    int getMaxVehicles() const override;

    double applyDiscount(double price) override;

    std::string getInfo() override;
};


#endif //CARRENTAL_DEFAULT_H
