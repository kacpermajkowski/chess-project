//
// Created by szindzeks on 04.05.2024.
//

#include "model/Rent.h"

Rent::Rent(const unsigned int id, const Client *client, const Vehicle *vehicle) :
    id(id),
    client(client),
    vehicle(vehicle) {

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
