//
// Created by szindzeks on 04.05.2024.
//

#ifndef CARRENTAL_RENT_H
#define CARRENTAL_RENT_H


#include "Vehicle.h"
#include "Client.h"

class Client;

class Rent {
private:
    const unsigned int id;
    const Client* client;
    const Vehicle* vehicle;
public:
    Rent(const unsigned int id, Client *client, Vehicle *vehicle);

    const unsigned int getId() const;
    const Client *getClient() const;
    const Vehicle *getVehicle() const;
    const std::string getInfo() const;

};


#endif //CARRENTAL_RENT_H
