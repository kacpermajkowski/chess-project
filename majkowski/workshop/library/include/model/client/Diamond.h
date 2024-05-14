//
// Created by szindzeks on 14.05.2024.
//

#ifndef CARRENTAL_Diamond_H
#define CARRENTAL_Diamond_H


#include "model/ClientType.h"

class Diamond : public ClientType {
public:
    explicit Diamond();

public:
    int getMaxVehicles() const override;

    double applyDiscount(double price) override;

    std::string getInfo() override;
};


#endif //CARRENTAL_Diamond_H
