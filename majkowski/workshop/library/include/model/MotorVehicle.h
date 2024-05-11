//
// Created by szindzeks on 11.05.2024.
//

#ifndef CARRENTAL_MOTORVEHICLE_H
#define CARRENTAL_MOTORVEHICLE_H


#include "Vehicle.h"

class MotorVehicle : Vehicle {

public:
    MotorVehicle(const std::string &plateNumber, unsigned int basePrice, int engineDisplacement);

private:
    int engineDisplacement;
public:
    int getEngineDisplacement() const;

    void setEngineDisplacement(int engineDisplacement);
};


#endif //CARRENTAL_MOTORVEHICLE_H
