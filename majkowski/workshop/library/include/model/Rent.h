//
// Created by szindzeks on 04.05.2024.
//

#ifndef CARRENTAL_RENT_H
#define CARRENTAL_RENT_H


#include "Vehicle.h"
#include "Client.h"
#include <boost/date_time.hpp>
#include <math.h>

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

class Client;

class Rent {
private:
    const unsigned int id;
    //TODO: to samo co niżej
    Client* client;
    //TODO: czemu nie zawsze pozwala wywołać funkcje setRented() kiedy jest const Vehicle*
    Vehicle *vehicle;
    unsigned int rentCost = 0;
    pt::ptime beginTime;
    pt::ptime endTime = pt::not_a_date_time;

public:
    ///
    /// @param id - unique identifier of instance of renting a vehicle
    /// @param client - represents a client to which vehicle was rented
    /// @param vehicle - represents a rented vehicle
    /// @param beginTime - time at which vehicle was rented
    ///
    /// @brief sets fields of created objects, but also adds pointer to itself to client->currentRents and sets vehicle as rented
    ///
    Rent(const unsigned int id, Client *client, Vehicle *vehicle, pt::ptime beginTime);

    /// @return rent ID
    const unsigned int getId() const;

    /// @return pointer to Client object to whom vehicle was rented
    const Client *getClient() const;

    /// @return pointer to rented Vehicle object
    const Vehicle *getVehicle() const;

    /// @return time at which vehicle was rented
    const pt::ptime &getBeginTime() const;

    /// @return time at which vehicle was brought back
    const pt::ptime &getEndTime() const;

    /// @return string containing concatenated fields of this objects and objects contained within
    std::string getInfo() const;

    unsigned int getRentDays() const;
    unsigned int getRentCost() const;

    void endRent(pt::ptime endTime);

};

#endif //CARRENTAL_RENT_H
