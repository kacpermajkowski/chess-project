#include "model/Address.h"
#include <iostream>

Address::Address(std::string city, std::string street, std::string houseNumber)
:
    city(city),
    street(street),
    houseNumber(houseNumber)
{}

Address::~Address(){}

std::string Address::getInfo(){
    return city + " " +  street + " " + houseNumber;
}

std::string Address::getCity(){
    return Address::city;
}

std::string Address::getStreet(){
    return Address::street;
}

std::string Address::getHouseNumber(){
    return Address::houseNumber;
}

/*void Address::setCity(std::string city){
    if(city != ""){
        Address::city = city;
    }
}

void Address::setStreet(std::string street){
    if(street != ""){
        Address::street = street;
    }
}

void Address::setHouseNumber(std::string houseNumber){
    if(houseNumber != ""){
        Address::houseNumber = houseNumber;
    }
}*/



