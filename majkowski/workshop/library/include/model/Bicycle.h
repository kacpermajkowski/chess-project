//
// Created by szindzeks on 11.05.2024.
//

#include "Vehicle.h"

#ifndef CARRENTAL_BICYCLE_H
#define CARRENTAL_BICYCLE_H


class Bicycle : public Vehicle {
public:
    Bicycle(const std::string &plateNumber, unsigned int basePrice);

private:
public:
    std::string getInfo() const override;

private:
    const unsigned int getActualRentalPrice() const override;
};


#endif //CARRENTAL_BICYCLE_H
