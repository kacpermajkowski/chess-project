#ifndef CARRENTAL_ADDRESS_H
#define CARRENTAL_ADDRESS_H

#include <iostream>

class Address{
private:
    std::string city;
    std::string street;
    std::string houseNumber;

public:
    Address(const std::string &city, const std::string &street, const std::string &houseNumber);
    ~Address();

    std::string getInfo(); //const;

    const std::string &getCity() const;
    const std::string &getStreet() const;
    const std::string &getHouseNumber() const;

    void setCity(const std::string &city);
    void setStreet(const std::string &street);
    void setHouseNumber(const std::string &houseNumber);
};

#endif //CARRENTAL_ADDRESS_H