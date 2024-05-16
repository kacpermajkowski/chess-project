//
// Created by szindzeks on 14.05.2024.
//

#ifndef CARRENTAL_BRONZE_H
#define CARRENTAL_BRONZE_H


#include "model/ClientType.h"

class Bronze : public ClientType {
public:
    explicit Bronze();

    ~Bronze();

    int getMaxVehicles() const override;

    double applyDiscount(double price) override;

    std::string getInfo() override;
};


#endif //CARRENTAL_BRONZE_H
