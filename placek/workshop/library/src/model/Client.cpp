#include "../../include/model/Client.h"
#include <iostream>


    Client::Client(){
        std::cout << "Konstruktor zostal wywolany" << std::endl;
    }
    Client::~Client(){
        std::cout << "Destruktor zostal wywolany";
    }

    std::string Client::getInfo(){
        return firstName + " " +  lastName + " " + personalID;
    }

