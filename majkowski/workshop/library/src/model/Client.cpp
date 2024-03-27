//
// Created by majkosia on 23.03.2024.
//

#include <iostream>
#include "../../include/model/Client.h"


Client::Client(){
    std::cout << "Konstruktor klasy Client został wywołany" << std::endl;
}

Client::Client(std::string firstName, std::string lastName, std::string personalID) :
    firstName(firstName),
    lastName(lastName),
    personalID(personalID)
{
    std::cout << "Konstruktor klasy Client został wywołany z parametrami" << std::endl;
}

Client::~Client(){
    std::cout << "Dekonstrutor klasy Client został wywołany" << std::endl;
}

std::string Client::getInfo() {
    return firstName + " " + lastName + " " + personalID;
}