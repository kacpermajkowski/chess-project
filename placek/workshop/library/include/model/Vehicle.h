#ifndef CARRENTAL_VEHICLE_H
#define CARRENTAL_VEHICLE_H

#include <iostream>

class Vehicle{
private:
    std::string plateNumber;
    unsigned int basePrice;
    bool rented = false;

public:
    /**
     *
     * @brief constructor; sets bicycle's values
     *
     * @param plateNumber bicycle's real plate number
     * @param basePrice bicycle's real base rental price per one day
     */
    Vehicle(const std::string &plateNumber, unsigned int basePrice);
    virtual ~Vehicle();

    /// \return returns plateNumber and basePrice
    virtual std::string getInfo() const;

    /// \return returns plateNumber
    const std::string &getPlateNumber() const;
    /// \return returns basePrice
    unsigned int getBasePrice() const;

    /// \return returns true or false depending on whether the bicycle is currently rented
    bool isRented() const;

    /// \brief sets new value for bicycle's plate number
    /// \param plateNumber - new plate number
    void setPlateNumber(const std::string &plateNumber);
    /// \brief sets new value for bicycle's base price
    /// \param basePrice - new base price
    void setBasePrice(unsigned int basePrice);

    /// \brief changes the bicycle's rental status
    /// \param rented - true if rented, false if not
    void setRented(bool rented);


    virtual double getActualRentalPrice() const = 0;
};

#endif //CARRENTAL_VEHICLE_H
