#include "model/Rent.h"
#include <iostream>

Rent::Rent(const unsigned int id, Client* client, Vehicle* vehicle):
    id(id),
    client(client),
    vehicle(vehicle)
{
    client->addRent(this);
    vehicle->setRented(true);
}

std::string Rent::getInfo() const {
    return "NR." + std::to_string(Rent::id) + " CLIENT: " + Rent::client->getInfo() + " VEHICLE: " + Rent::vehicle->getInfo();
}

const unsigned int Rent::getId() const {
    return id;
}

const Client* Rent::getClient() const {
    return client;
}

const Vehicle* Rent::getVehicle() const {
    return vehicle;
}
