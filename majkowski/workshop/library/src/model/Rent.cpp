//
// Created by szindzeks on 04.05.2024.
//

#include "model/Rent.h"

Rent::Rent(const unsigned int id, ClientPtr client, VehiclePtr vehicle, pt::ptime beginTime) :
    id(id),
    client(client),
    vehicle(vehicle)
{
    if(beginTime == pt::not_a_date_time){
        this->beginTime = pt::second_clock::local_time();
    } else {
        this->beginTime = beginTime;
    }

    client->addNewRent(this);
    vehicle->setRented(true);
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

std::string Rent::getInfo() const{
    std::ostringstream ss;
    ss << "Rent ID: " << id << "\n";
    ss << "Begin time: " << beginTime << "\n";
    ss << "End time: " << endTime << "\n";
    ss << client->getInfo();
    ss << vehicle->getInfo();
    return ss.str();
}

const pt::ptime &Rent::getBeginTime() const {
    return beginTime;
}

const pt::ptime &Rent::getEndTime() const {
    return endTime;
}

void Rent::endRent(pt::ptime endTime) {
    if(this->endTime.is_not_a_date_time()){
        if(endTime.is_not_a_date_time()){
            pt::ptime now = pt::second_clock::local_time();
            this->endTime = (now >= this->beginTime) ? now : this->beginTime;
        } else {
            this->endTime = (endTime >= this->beginTime) ? endTime : this->beginTime;
        }
    }
    vehicle->setRented(false);
    client->removeRent(this);
    rentCost = getRentDays() * client->applyDiscount(vehicle->getBasePrice());
}

unsigned int Rent::getRentDays() const {
    if(endTime.is_not_a_date_time()) {
        return 0;
    } else {
        pt::time_period rentTime(beginTime, endTime);
        if(rentTime.length() < pt::minutes(1)){
            return 0;
        } else return floor((rentTime.length().minutes() + rentTime.length().hours() * 60) / (24.0 * 60.0) ) + 1;
    }
}

unsigned int Rent::getRentCost() const {
    return rentCost;
}
