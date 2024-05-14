//
// Created by ola on 14.05.2024.
//

#ifndef CARRENTAL_MOTORVEHICLE_H
#define CARRENTAL_MOTORVEHICLE_H


#include "Vehicle.h"

class MotorVehicle : public Vehicle{
private:
    unsigned int engineDisplacement;

public:
    MotorVehicle(const std::string &plateNumber, unsigned int basePrice, unsigned int engineDisplacement);

    virtual std::string getInfo() const override;

    void setEngineDisplacement(unsigned int engineDisplacement);
    unsigned int getEngineDisplacement() const;

    virtual double getActualRentalPrice() const override = 0;

};


#endif //CARRENTAL_MOTORVEHICLE_H
