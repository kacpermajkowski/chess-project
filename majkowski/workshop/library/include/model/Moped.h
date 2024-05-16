//
// Created by szindzeks on 11.05.2024.
//

#ifndef CARRENTAL_MOPED_H
#define CARRENTAL_MOPED_H


#include "MotorVehicle.h"

class Moped : public MotorVehicle {
public:
    std::string getInfo() const override;

    Moped(const std::string &plateNumber, unsigned int basePrice, int engineDisplacement);
    const unsigned int getActualRentalPrice() const override;
};


#endif //CARRENTAL_MOPED_H
