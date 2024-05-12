#ifndef CARRENTAL_RENT_H
#define CARRENTAL_RENT_H

#include <iostream>
#include "Vehicle.h"
#include "Client.h"

#include <boost/date_time.hpp>
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

class Client;

class Rent{
private:
    const unsigned int id;
    Client* client;
    Vehicle* vehicle;
    pt::ptime beginTime;
    pt::ptime endTime = pt::not_a_date_time;
    unsigned int rentCost = 0;


public:
    Rent(const unsigned int id, Client *client, Vehicle *vehicle, pt::ptime beginTime);

    std::string getInfo() const;

    const unsigned int getId() const;
    const Client* getClient() const;
    const Vehicle* getVehicle() const;

    const pt::ptime &getBeginTime() const;
    const pt::ptime &getEndTime() const;

    unsigned int getRentDays() const;
    unsigned int getRentCost() const;

    void endRent(pt::ptime endTime);

};


#endif //CARRENTAL_RENT_H
