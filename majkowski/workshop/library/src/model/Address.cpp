//
// Created by szindzeks on 11.04.2024.
//

#include <iostream>
#include "model/Address.h"


Address::Address(const std::string &city, const std::string &street, const std::string &number) :
        city(city),
        street(street),
        number(number)
{
    //
}

Address::~Address() {
    //
}

std::string Address::getInfo() const {
    return city + ", " + street + " " + number;
}

const std::string & Address::getCity() const {
    return Address::city;
}

const std::string & Address::getStreet() const {
    return Address::street;
}

const std::string & Address::getNumber() const {
    return Address::number;
}
void Address::setCity(const std::string &city){
    Address::city = city;
}
void Address::setStreet(const std::string &street){
    Address::street = street;
}
void Address::setNumber(const std::string &number){
    Address::number = number;
}
