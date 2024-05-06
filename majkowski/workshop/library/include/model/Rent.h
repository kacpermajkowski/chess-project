//
// Created by szindzeks on 04.05.2024.
//

#ifndef CARRENTAL_RENT_H
#define CARRENTAL_RENT_H


#include "Vehicle.h"
#include "Client.h"
#include "typedefs.h"
#include <boost/date_time.hpp>
#include <math.h>

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

class Client;

///@brief Represents a vehicle rent instance to a client
class Rent {
private:
    const unsigned int id;
    //TODO: to samo co niżej
    ClientPtr client;
    //TODO: czemu nie zawsze pozwala wywołać funkcje setRented() kiedy jest const Vehicle*
    VehiclePtr vehicle;
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
    /// @brief sets fields of created objects, but also adds pointer to itself to client->currentRents and sets vehicle as rented.
    ///
    Rent(const unsigned int id, ClientPtr client, VehiclePtr vehicle, pt::ptime beginTime);

    /// @return rent ID
    const unsigned int getId() const;

    /// @return pointer to Client object to whom vehicle was rented
    const ClientPtr getClient() const;

    /// @return pointer to rented Vehicle object
    const VehiclePtr getVehicle() const;

    /// @return time at which vehicle was rented
    const pt::ptime &getBeginTime() const;

    /// @return time at which vehicle was brought back
    const pt::ptime &getEndTime() const;

    /// @return string containing concatenated fields of this objects and objects contained within
    std::string getInfo() const;

    /**
     * @brief Rent days are calculated as per business logic.
     *
     * 0 for rents that have not ended yet\n
     * 0 for under 1 minute.\n
     * 1 for every started 24h e.g. \n
     *      1 for 1 minute or 23h59m59s,\n
     *      2 for 24 hours.\n
     *
     * @return calculated value of rent days passed
    */
    unsigned int getRentDays() const;

    /**
     * @brief Rent cost is calculated as rent days multiplied by daily rent price for a given vehicle at the moment of ending rent.
     * @return calculated rent cost
     */
    unsigned int getRentCost() const;

    /**
     * @brief sets rent end time to given endtime and modifies Vehicle and Client objects accordingly.
     *
     * Removes pointer to this object from currentRents of Client.
     * Sets vehicle rent status to false (vehicle->setRented(false)).
     *
     * @param endTime - time which will be considered moment of ending a rent
     */
    void endRent(pt::ptime endTime);

};

#endif //CARRENTAL_RENT_H
