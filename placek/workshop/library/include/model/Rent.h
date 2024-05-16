#ifndef CARRENTAL_RENT_H
#define CARRENTAL_RENT_H

#include <iostream>
#include "Vehicle.h"
#include "Client.h"
#include "typedefs.h"

#include <boost/date_time.hpp>
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

class Client;

class Rent{
private:
    const unsigned int id;
    ClientPtr client;
    VehiclePtr vehicle;
    pt::ptime beginTime;
    pt::ptime endTime = pt::not_a_date_time;
    double rentCost = 0;


public:
    /**
     *
     * @brief rent constructor; creates a rental using client and bicycle data and sets the initial rental time
     *
     * @param id unique rent identifier
     * @param client client who rented the bicycle
     * @param vehicle rented bicycle
     * @param beginTime initial rental time
     */
    Rent(const unsigned int id, ClientPtr client, VehiclePtr vehicle, pt::ptime beginTime);

    /// \return returns id, client, bicycle, beginTime and endTime (or info that the rental is still on)
    std::string getInfo() const;

    /// \return returns id
    const unsigned int getId() const;
    /// \return returns client
    const ClientPtr getClient() const;
    /// \return returns bicycle
    const VehiclePtr getVehicle() const;

    /// \return returns beginTime
    const pt::ptime &getBeginTime() const;
    /// \return returns endTime
    const pt::ptime &getEndTime() const;

    /// \return returns number of days for which the fee will be charged
    unsigned int getRentDays() const;
    /// \return returns cost of the rental
    unsigned int getRentCost() const;

    /// \brief ends the rental with the specified time, if no time given then, sets the current time
    /// \param endTime - termination time
    void endRent(pt::ptime endTime);

};


#endif //CARRENTAL_RENT_H
