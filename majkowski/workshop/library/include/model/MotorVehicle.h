//
// Created by szindzeks on 11.05.2024.
//

#ifndef CARRENTAL_MOTORVEHICLE_H
#define CARRENTAL_MOTORVEHICLE_H


#include "Vehicle.h"

class MotorVehicle : public Vehicle {
private:
    int engineDisplacement;
public:
    virtual ~MotorVehicle() override;

    MotorVehicle(const std::string &plateNumber, unsigned int basePrice, int engineDisplacement);

    int getEngineDisplacement() const;
    void setEngineDisplacement(int engineDisplacement);

    std::string getInfo() const override;
    const unsigned int getActualRentalPrice() const override;
};


#endif //CARRENTAL_MOTORVEHICLE_H
