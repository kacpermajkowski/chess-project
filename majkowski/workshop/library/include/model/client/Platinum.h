//
// Created by szindzeks on 14.05.2024.
//

#ifndef CARRENTAL_Platinum_H
#define CARRENTAL_Platinum_H


#include "model/ClientType.h"

class Platinum : public ClientType {
public:
    explicit Platinum();

    ~Platinum();

public:
    int getMaxVehicles() const override;

    double applyDiscount(double price) override;

    std::string getInfo() override;
};


#endif //CARRENTAL_Platinum_H
