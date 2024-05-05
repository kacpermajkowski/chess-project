//
// Created by szindzeks on 04.05.2024.
//

#include "model/Rent.h"

Rent::Rent(const unsigned int id, Client *client, Vehicle *vehicle) :
    id(id),
    client(client),
    vehicle(vehicle)
{
    client->addNewRent(this);
}

const unsigned int Rent::getId() const {
    return id;
}

const Client *Rent::getClient() const {
    return client;
}

const Vehicle *Rent::getVehicle() const {
    return vehicle;
}

const std::string Rent::getInfo() const{
    return std::to_string(Rent::id) + " " + Rent::client->getInfo() + " " + Rent::vehicle->getInfo();
}
