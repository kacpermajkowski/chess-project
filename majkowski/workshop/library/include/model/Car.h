//
// Created by szindzeks on 11.05.2024.
//

#ifndef CARRENTAL_CAR_H
#define CARRENTAL_CAR_H


#include "MotorVehicle.h"

//Fixed precision at 0.1
enum SegmentType{
    A = 10,
    B = 11,
    C = 12,
    D = 13,
    E = 15
};

class Car : public MotorVehicle{
private:
    SegmentType segment;
public:
    std::string getInfo() const override;

    Car(const std::string &plateNumber, unsigned int basePrice, int engineDisplacement, SegmentType segment);

    ///
    /// @return returns rent cost multiplied ty segment type multiplier
    const unsigned int getActualRentalPrice() const override;
};


#endif //CARRENTAL_CAR_H
