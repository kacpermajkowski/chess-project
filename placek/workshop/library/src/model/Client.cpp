#include "model/Client.h"
#include <iostream>

    Client::Client(const std::string &firstName, const std::string &lastName, const std::string &personalID, AddressPtr address)
    :
        firstName(firstName),
        lastName(lastName),
        personalID(personalID),
        address(address)
    {}

    Client::~Client(){}

    std::string Client::getInfo() const{
        return firstName + " " +  lastName + " " + personalID + " " + address->getInfo();
    }

    std::string Client::getFullInfo() const{
        std::string fullInfo = getInfo() + "\n";
        for(int i=0; i<currentRents.size(); i++){
            fullInfo += currentRents[i]->getInfo() + "\n";
        }
        return fullInfo;
    }

    const std::string &Client::getFirstName() const{
        return Client::firstName;
    }
    const std::string &Client::getLastName() const{
        return Client::lastName;
    }
    const std::string &Client::getPersonalID() const{
        return Client::personalID;
    }
    const AddressPtr Client::getAddress() const {
        return Client::address;
    }
    const std::vector<RentPtr> &Client::getCurrentRents() const {
        return currentRents;
    }

    void Client::setFirstName(const std::string &firstName){
        if(firstName != ""){
            Client::firstName = firstName;
        }
    }
    void Client::setLastName(const std::string &lastName){
        if(lastName != ""){
            Client::lastName = lastName;
        }
    }
    void Client::setAddress(AddressPtr address) {
        if(address != nullptr){
            Client::address = address;
        }
    }
    void Client::addRent(RentPtr rent) {
        currentRents.push_back(rent);
    }

    void Client::removeRent(RentPtr rent) {
        currentRents.erase(remove(currentRents.begin(), currentRents.end(), rent), currentRents.end());
    }
