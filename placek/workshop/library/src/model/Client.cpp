#include "../../include/model/Client.h"
#include <iostream>


    Client::Client(std::string firstName, std::string lastName, std::string personalID)
    :
        firstName(firstName),
        lastName(lastName),
        personalID(personalID)
    {
        std::cout << "Konstruktor z parametrami '" << getInfo() << "' zostal wywolany" << std::endl;
    }

    Client::~Client(){
        std::cout << "Destruktor zostal wywolany: " << getInfo() << std::endl;
    }

    std::string Client::getInfo(){
        return firstName + " " +  lastName + " " + personalID;
    }

    std::string Client::getFirstName(){
        return Client::firstName;
    }
    std::string Client::getLastName(){
        return Client::lastName;
    }
    std::string Client::getPersonalID(){
        return Client::personalID;
    }

    void Client::setFirstName(std::string firstName){
        if(firstName != ""){
            Client::firstName = firstName;
        }
    }
    void Client::setLastName(std::string lastName){
        if(lastName != ""){
            Client::lastName = lastName;
        }
    }







