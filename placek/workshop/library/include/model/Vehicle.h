#ifndef CARRENTAL_VEHICLE_H
#define CARRENTAL_VEHICLE_H

#include <iostream>

class Vehicle{
private:
    std::string plateNumber;
    unsigned int basePrice;
    bool rented = false;

public:
    Vehicle(const std::string &plateNumber, unsigned int basePrice);
    ~Vehicle();

    const std::string getInfo() const;

    const std::string &getPlateNumber() const;
    const unsigned int getBasePrice() const;

    bool isRented() const;

    void setPlateNumber(const std::string &plateNumber);
    void setBasePrice(unsigned int basePrice);

    void setRented(bool rented);
};

#endif //CARRENTAL_VEHICLE_H
