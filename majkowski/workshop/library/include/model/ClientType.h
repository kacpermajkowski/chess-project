//
// Created by szindzeks on 14.05.2024.
//

#ifndef CARRENTAL_CLIENTTYPE_H
#define CARRENTAL_CLIENTTYPE_H


#include <string>

class ClientType {
public:
    ///
    /// @return maximum vehicle amount a client can rent at the same time
    virtual int getMaxVehicles() const = 0;
    ///
    /// @param price - price to apply discount to
    /// @return discounted price as per client type policy
    virtual double applyDiscount(double price) = 0;
    ///
    /// @return returns client type info
    virtual std::string getInfo() = 0;

};


#endif //CARRENTAL_CLIENTTYPE_H
