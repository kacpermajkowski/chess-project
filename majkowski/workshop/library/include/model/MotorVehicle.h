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

    ///
    /// @return engine displacement in mm^3
    int getEngineDisplacement() const;
    /// @brief sets new engine displacement
    /// @param engineDisplacement new engine displacement in mm^3
    void setEngineDisplacement(int engineDisplacement);

    std::string getInfo() const override;
    ///
    /// @return returns actual rent price
    const unsigned int getActualRentalPrice() const override;
};


#endif //CARRENTAL_MOTORVEHICLE_H
