//
// Created by ola on 14.05.2024.
//

#ifndef CARRENTAL_MOPED_H
#define CARRENTAL_MOPED_H

#include "MotorVehicle.h"

class Moped : public MotorVehicle{

public:
    Moped(const std::string &plateNumber, unsigned int basePrice, unsigned int engineDisplacement);

    std::string getInfo() const override;

    double getActualRentalPrice() const override;
};


#endif //CARRENTAL_MOPED_H
