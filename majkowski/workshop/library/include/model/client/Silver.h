//
// Created by szindzeks on 14.05.2024.
//

#ifndef CARRENTAL_Silver_H
#define CARRENTAL_Silver_H


#include "model/ClientType.h"

class Silver : public ClientType {
public:
    explicit Silver();

public:
    int getMaxVehicles() const override;

    double applyDiscount(double price) override;

    std::string getInfo() override;
};


#endif //CARRENTAL_Silver_H
