//
// Created by ola on 15.05.2024.
//

#ifndef CARRENTAL_CLIENTTYPE_H
#define CARRENTAL_CLIENTTYPE_H

#include <string>

class ClientType {
public:
    virtual unsigned int getMaxVehicles() const = 0;
    virtual double applyDiscount(double price) = 0;
    virtual std::string getInfo() const = 0;
};


#endif //CARRENTAL_CLIENTTYPE_H
