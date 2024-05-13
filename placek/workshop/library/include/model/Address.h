#ifndef CARRENTAL_ADDRESS_H
#define CARRENTAL_ADDRESS_H

#include <iostream>

class Address{
private:
    std::string city;
    std::string street;
    std::string houseNumber;

public:
    /**
     *
     * @brief constructor; sets address data
     *
     * @param city
     * @param street
     * @param houseNumber
     */
    Address(const std::string &city, const std::string &street, const std::string &houseNumber);
    ~Address();

    /// \return returns city, street and houseNumber
    std::string getInfo() const;

    /// \return returns city
    const std::string &getCity() const;
    /// \return returns street
    const std::string &getStreet() const;
    /// \return returns houseNumber
    const std::string &getHouseNumber() const;

    /// \param city new value of city
    void setCity(const std::string &city);
    /// \param street new value of street
    void setStreet(const std::string &street);
    /// \param houseNumber new value of houseNumber
    void setHouseNumber(const std::string &houseNumber);
};

#endif //CARRENTAL_ADDRESS_H