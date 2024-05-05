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
    std::string info = firstName + " " + lastName + " " + personalID + " " + address->getInfo();

    return info;
}

const std::string Client::getFullInfo() const {
    std::string info = getInfo();
    for(Rent* r: currentRents){
        info += " " + r->getInfo();
    }
    return std::string();
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

const std::vector<Rent *> &Client::getCurrentRents() const {
    return currentRents;
}

void Client::addNewRent(Rent *newRent) {
    if(newRent->getClient() == this){
        for(Rent* rent:currentRents){
            if(rent->getId() == newRent->getId())
                return;
        }
        //If the loop finishes and code still executes, newRent is not contained in the vector, so we can safely add it
        currentRents.push_back(newRent);
    }
}

void Client::removeRent(unsigned int rentID) {
    std::vector<Rent*>::iterator it;
    for(it = currentRents.begin(); it != currentRents.end(); it++){
        if((*it)->getId() == rentID) {
            currentRents.erase(it);
            return;
        }
    }
}

