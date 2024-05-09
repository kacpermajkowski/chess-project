#include "model/Address.h"
#include <iostream>

Address::Address(const std::string &city, const std::string &street, const std::string &houseNumber)
:
    city(city),
    street(street),
    houseNumber(houseNumber)
{}

Address::~Address(){}

std::string Address::getInfo(){ //const
    return city + " " +  street + " " + houseNumber;
}

const std::string &Address::getCity() const{
    return Address::city;
}

const std::string &Address::getStreet() const{
    return Address::street;
}

const std::string &Address::getHouseNumber() const{
    return Address::houseNumber;
}

void Address::setCity(const std::string &city){
    if(city != ""){
        Address::city = city;
    }
}

void Address::setStreet(const std::string &street){
    if(street != ""){
        Address::street = street;
    }
}

void Address::setHouseNumber(const std::string &houseNumber){
    if(houseNumber != ""){
        Address::houseNumber = houseNumber;
    }
}



