//
// Created by szindzeks on 14.05.2024.
//

#ifndef CARRENTAL_Gold_H
#define CARRENTAL_Gold_H


#include "model/ClientType.h"

class Gold : public ClientType {
public:
    explicit Gold();

public:
    int getMaxVehicles() const override;

    double applyDiscount(double price) override;

    std::string getInfo() override;
};


#endif //CARRENTAL_Gold_H
