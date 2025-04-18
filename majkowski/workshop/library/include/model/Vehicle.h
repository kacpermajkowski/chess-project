//
// Created by szindzeks on 04.05.2024.
//

#ifndef CARRENTAL_VEHICLE_H
#define CARRENTAL_VEHICLE_H

#include <string>

/// @brief Represent a rentable vehicle
class Vehicle {
private:
    std::string plateNumber;
    unsigned int basePrice;
    bool rented = false;
public:
    ///
    /// @param plateNumber license plate number
    /// @param basePrice base rental price
    ///
    Vehicle(const std::string &plateNumber, unsigned int basePrice);

    virtual ~Vehicle();

    ///
    /// @return license plate number
    const std::string &getPlateNumber() const;
    ///
    /// @return base rental price
    const unsigned int getBasePrice() const;

    virtual const unsigned int getActualRentalPrice() const;
    ///
    /// @return all field values contatenated into single string
    virtual std::string getInfo() const;
    ///
    /// @return whether vehicle is rented or not
    bool isRented() const;

    /// @brief sets new license plate number.
    /// @param plateNumber new license plate number
    void setPlateNumber(const std::string &plateNumber);

    /// @brief sets new base rental price.
    /// @param basePrice new base rental price
    void setBasePrice(unsigned int basePrice);

    /// @brief sets rental status of vehicle.
    /// @param rented represents whethever vehicle is currently rented(true) or not(false)
    void setRented(bool rented);

};


#endif //CARRENTAL_VEHICLE_H
