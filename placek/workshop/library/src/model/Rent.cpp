#include "model/Rent.h"
#include <iostream>
#include <cmath>

Rent::Rent(const unsigned int id, ClientPtr client, VehiclePtr vehicle, pt::ptime beginTime) :
    id(id),
    client(client),
    vehicle(vehicle)
{
    if (beginTime == pt::not_a_date_time){
        this->beginTime = pt::second_clock::local_time();
    } else {
        this->beginTime = beginTime;
    };

    client->addRent(this);
    vehicle->setRented(true);
}

std::string Rent::getInfo() const {
    std::ostringstream ossBegin, ossEnd;
    ossBegin << beginTime;
    std::string beginString = ossBegin.str();
    std::string info = "NR." + std::to_string(id) + " CLIENT: " + client->getInfo() + " VEHICLE: " + vehicle->getInfo() + " BEGIN_TIME: " + beginString + " END_TIME: ";

    if(endTime != pt::not_a_date_time){
        ossEnd << endTime;
        std::string endString = ossEnd.str();
        info += endString;
    }else info += "the rental is still on";

    return info;
}

const unsigned int Rent::getId() const {
    return id;
}
const ClientPtr Rent::getClient() const {
    return client;
}
const VehiclePtr Rent::getVehicle() const {
    return vehicle;
}

const pt::ptime &Rent::getBeginTime() const {
    return beginTime;
}
const pt::ptime &Rent::getEndTime() const {
    return endTime;
}

unsigned int Rent::getRentDays() const {

    if(endTime == pt::not_a_date_time){
        return 0;
    } else {
        pt::time_period rentTime(beginTime, endTime);
        if (rentTime.length() <= pt::minutes(1)){
            return 0;
        } else {
            unsigned int rentMinutes = rentTime.length().hours() * 60 + rentTime.length().minutes();
            unsigned int rentDays = std::floor(rentMinutes/1440); //minutes in a day 24*60=1440
            if (rentMinutes % 1440 != 0) rentDays += 1;
            return rentDays;
        }
    }
};

unsigned int Rent::getRentCost() const {
    return rentCost;
};

void Rent::endRent(pt::ptime endTime){
    if (Rent::endTime == pt::not_a_date_time) {
        if (endTime == pt::not_a_date_time) {
            Rent::endTime = pt::second_clock::local_time();
        } else Rent::endTime = (Rent::beginTime < endTime) ? endTime : Rent::beginTime;

        vehicle->setRented(false);
        client->removeRent(this);
        rentCost =  static_cast<double>(this->getRentDays()) * vehicle->getActualRentalPrice();
    }
}
