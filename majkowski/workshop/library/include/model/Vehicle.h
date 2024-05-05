//
// Created by szindzeks on 04.05.2024.
//

#ifndef CARRENTAL_VEHICLE_H
#define CARRENTAL_VEHICLE_H


#include <string>

class Vehicle {
private:
    std::string plateNumber;
    unsigned int basePrice;
    bool rented = false;
public:
    void setRented(bool rented);

public:
    bool isRented() const;

public:
    const std::string &getPlateNumber() const;
    const unsigned int getBasePrice() const;
    const std::string getInfo() const {
        return plateNumber + " " + std::to_string(basePrice);
    }

    void setPlateNumber(const std::string &plateNumber);
    void setBasePrice(unsigned int basePrice);


public:
    Vehicle(const std::string &plateNumber, unsigned int basePrice);

};


#endif //CARRENTAL_VEHICLE_H
