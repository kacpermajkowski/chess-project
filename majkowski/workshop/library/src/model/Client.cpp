//
// Created by majkosia on 23.03.2024.
//

#include <iostream>
#include "model/Client.h"
#include "model/Address.h"

Client::Client(const std::string & firstName, const std::string & lastName, const std::string & personalID, AddressPtr address) :
    firstName(firstName),
    lastName(lastName),
    personalID(personalID),
    address(address)
{
    //
}

Client::~Client(){

}

std::string Client::getInfo() const {
    std::ostringstream ss;
    ss << "First name: " << firstName << "\n";
    ss << "Last name: " << lastName << "\n";
    ss << "Personal ID: " << personalID << "\n";
    ss << address->getInfo();
    return ss.str();
}

std::string Client::getFullInfo() const {
    std::ostringstream ss;
    ss << getInfo();
    for(RentPtr r: currentRents){
        ss << r->getInfo();
    }
    return ss.str();
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

const AddressPtr Client::getAddress() const{
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

void Client::setAddress(AddressPtr address) {
    if(address != nullptr){
        Client::address = address;
    }
}

const std::vector<RentPtr> & Client::getCurrentRents() const {
    return currentRents;
}

void Client::addNewRent(RentPtr newRent) {
    if(newRent->getClient() == this){
        for(RentPtr rent:currentRents){
            if(rent->getId() == newRent->getId())
                return;
        }
        //If the loop finishes and code still executes, newRent is not contained in the vector, so we can safely add it
        currentRents.push_back(newRent);
    }
}

void Client::removeRent(unsigned int rentID) {
    std::vector<RentPtr>::iterator it;
    for(it = currentRents.begin(); it != currentRents.end(); it++){
        if((*it)->getId() == rentID) {
            currentRents.erase(it);
            return;
        }
    }
}

void Client::removeRent(RentPtr rentToRemove) {
    removeRent(rentToRemove->getId());
}

