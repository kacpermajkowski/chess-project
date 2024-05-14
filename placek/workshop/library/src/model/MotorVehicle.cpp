//
// Created by ola on 14.05.2024.
//

#include "model/MotorVehicle.h"

MotorVehicle::MotorVehicle(const std::string &plateNumber, unsigned int basePrice, unsigned int engineDisplacement)
        : Vehicle(plateNumber, basePrice), engineDisplacement(engineDisplacement) {}

unsigned int MotorVehicle::getEngineDisplacement() const {
    return engineDisplacement;
}

void MotorVehicle::setEngineDisplacement(unsigned int engineDisplacement) {
    MotorVehicle::engineDisplacement = engineDisplacement;
}

double MotorVehicle::getActualRentalPrice() const {
    double q = 1;
    if(engineDisplacement > 1000 && engineDisplacement <= 2000){
          for(int i=0; i < (engineDisplacement-1000); i++){
              q += 0.0005;
          }
    }else if(engineDisplacement > 2000){
        q = 1.5;
    }
    return Vehicle::getActualRentalPrice() * q;
}

std::string MotorVehicle::getInfo() const {
    return Vehicle::getInfo() + " " + std::to_string(engineDisplacement);
}
