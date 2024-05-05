//
// Created by majkosia on 23.03.2024.
//

#include <iostream>
#include "model/Client.h"

Client::Client(const std::string & firstName, const std::string & lastName, const std::string & personalID, Address* address) :
    firstName(firstName),
    lastName(lastName),
    personalID(personalID),
    address(address)
{
    //
}

Client::~Client(){

}

const std::string Client::getInfo() const {
    return firstName + " " + lastName + " " + personalID + " " + address->getInfo();
}

const std::string &Client::getFirstName() const{
    return Client::firstName;
}

const std::string &Client::getLastName() const {
    return Client::lastName;
}

const std::string &Client::getPersonalID() const{
    return Client::personalID;
}

const Address * Client::getAddress() const{
    return Client::address;
}

void Client::setFirstName(const std::string &firstName){
    if(firstName != ""){
        Client::firstName = firstName;
    }

}
void Client::setLastName(const std::string &lastName){
    if(lastName != "") {
        Client::lastName = lastName;
    }
}

void Client::setAddress(Address *address) {
    if(address != nullptr){
        Client::address = address;
    }
}

