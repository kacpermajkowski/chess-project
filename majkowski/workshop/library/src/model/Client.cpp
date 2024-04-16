//
// Created by majkosia on 23.03.2024.
//

#include <iostream>
#include "model/Client.h"

Client::Client(std::string firstName, std::string lastName, std::string personalID, Address* address) :
    firstName(firstName),
    lastName(lastName),
    personalID(personalID),
    address(address)
{
    //
}

Client::~Client(){
    //
}

std::string Client::getInfo() {
    return firstName + " " + lastName + " " + personalID + " " + address->getInfo();
}

std::string Client::getFirstName() {
    return Client::firstName;
}

std::string Client::getLastName() {
    return Client::lastName;
}

std::string Client::getPersonalID(){
    return Client::personalID;
}

Address* Client::getAddress(){
    return Client::address;
}

void Client::setFirstName(std::string firstName){
    if(firstName != ""){
        Client::firstName = firstName;
    }

}
void Client::setLastName(std::string lastName){
    if(lastName != "") {
        Client::lastName = lastName;
    }
}

void Client::setAddress(Address *address) {
    if(address != nullptr){
        Client::address = address;
    }
}

