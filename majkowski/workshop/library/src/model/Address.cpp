//
// Created by szindzeks on 11.04.2024.
//

#include <iostream>
#include "../../include/model/Address.h"


Address::Address(std::string city, std::string street, std::string number) :
        city(city),
        street(street),
        number(number)
{
    //
}

Address::~Address() {
    //
}

std::string Address::getInfo() {
    return city + ", " + street + " " + number;
}

std::string Address::getCity() {
    return Address::city;
}

std::string Address::getStreet() {
    return Address::street;
}

std::string Address::getNumber(){
    return Address::number;
}
void Address::setCity(std::string city){
    Address::city = city;
}
void Address::setStreet(std::string street){
    Address::street = street;
}
void Address::setNumber(std::string number){
    Address::number = number;
}
