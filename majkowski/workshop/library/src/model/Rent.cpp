//
// Created by szindzeks on 04.05.2024.
//

#include "model/Rent.h"


Rent::Rent(const unsigned int id, Client* client, Vehicle* vehicle, pt::ptime beginTime) :
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

const Client *Rent::getClient() const {
    return client;
}

const Vehicle *Rent::getVehicle() const {
    return vehicle;
}

std::string Rent::getInfo() const{
    return std::to_string(id) + " " + to_iso_string(beginTime) + " " + to_iso_string(endTime) + " " + client->getInfo() + " " + vehicle->getInfo();
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
    rentCost = getRentDays() * vehicle->getBasePrice();
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
