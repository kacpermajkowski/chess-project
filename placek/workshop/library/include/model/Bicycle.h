//
// Created by ola on 14.05.2024.
//

#ifndef CARRENTAL_BICYCLE_H
#define CARRENTAL_BICYCLE_H

#include "Vehicle.h"

class Bicycle : public Vehicle {
public:
    Bicycle(const std::string &plateNumber, unsigned int basePrice);

    std::string getInfo() const override;

    double getActualRentalPrice() const override;

};


#endif //CARRENTAL_BICYCLE_H
