//
// Created by szindzeks on 11.05.2024.
//

#ifndef CARRENTAL_MOPED_H
#define CARRENTAL_MOPED_H


#include "MotorVehicle.h"

class Moped : MotorVehicle {
public:
    Moped(const std::string &plateNumber, unsigned int basePrice, int engineDisplacement);
};


#endif //CARRENTAL_MOPED_H
