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
    ///
    /// @param id - unique identifier of instance of renting a vehicle
    /// @param client - represents a client to which vehicle was rented
    /// @param vehicle - represent rented vehicle
    ///
    /// @brief sets fields of created objects, but also adds pointer to itself to client->currentRents and sets vehicle as rented
    ///
    Rent(const unsigned int id, Client *client, Vehicle *vehicle);

    /// @return rent ID
    const unsigned int getId() const;

    /// @return pointer to Client object to whom vehicle was rented
    const Client *getClient() const;

    /// @return pointer to rented Vehicle object
    const Vehicle *getVehicle() const;

    /// @return string containing concatenated fields of this objects and objects contained within
    std::string getInfo() const;

};

#endif //CARRENTAL_RENT_H
