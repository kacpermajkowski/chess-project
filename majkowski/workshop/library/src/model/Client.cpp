//
// Created by majkosia on 23.03.2024.
//

#include <iostream>
#include "../../include/model/Client.h"

Client::Client(std::string firstName, std::string lastName, std::string personalID) :
    firstName(firstName),
    lastName(lastName),
    personalID(personalID)
{
    std::cout << "Konstruktor klasy Client został wywołany z parametrami. " << getInfo() << std::endl;
}

Client::~Client(){
    std::cout << "Dekonstrutor klasy Client został wywołany. " << getInfo() << std::endl;
}

std::string Client::getInfo() {
    return firstName + " " + lastName + " " + personalID;
}

std::string Client::getFirstName() {
    return Client::firstName;
}

std::string Client::getLastName() {
    return Client::lastName;
}

std::string Client::getPerosnalID(){
    return Client::personalID;
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

