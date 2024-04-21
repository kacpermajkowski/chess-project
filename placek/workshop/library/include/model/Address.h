#ifndef START_ADDRESS_H
#define START_ADDRESS_H

#include <iostream>

class Address{
private:
    std::string city;
    std::string street;
    std::string houseNumber;

public:
    Address(std::string city, std::string street, std::string houseNumber);
    ~Address();

    std::string getInfo();

    std::string getCity();
    std::string getStreet();
    std::string getHouseNumber();

    void setCity(std::string city);
    void setStreet(std::string street);
    void setHouseNumber(std::string houseNumber);
};

#endif //START_ADDRESS_H