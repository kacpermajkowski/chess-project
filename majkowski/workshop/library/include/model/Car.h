//
// Created by szindzeks on 11.05.2024.
//

#ifndef CARRENTAL_CAR_H
#define CARRENTAL_CAR_H


#include "MotorVehicle.h"

enum SegmentType{
    A, B, C, D, E
};

class Car : MotorVehicle{
private:
    SegmentType segment;
public:
    Car(const std::string &plateNumber, unsigned int basePrice, int engineDisplacement, SegmentType segment);
};


#endif //CARRENTAL_CAR_H
