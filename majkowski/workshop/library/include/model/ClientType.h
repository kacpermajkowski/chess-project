//
// Created by szindzeks on 14.05.2024.
//

#ifndef CARRENTAL_CLIENTTYPE_H
#define CARRENTAL_CLIENTTYPE_H


#include <string>

class ClientType {
private:
    int maxVehicles;
public:
    virtual int getMaxVehicles() const = 0;
    virtual double applyDiscount(double price) = 0;
    virtual std:: string getInfo() = 0;

    virtual ~ClientType() = 0;

    explicit ClientType(int maxVehicles);
};


#endif //CARRENTAL_CLIENTTYPE_H
