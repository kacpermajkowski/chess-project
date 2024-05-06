//
// Created by szindzeks on 06.05.2024.
//

#ifndef CARRENTAL_TYPEDEFS_H
#define CARRENTAL_TYPEDEFS_H

#include "model/Client.h"
#include "model/Address.h"
#include "model/Rent.h"
#include "model/Vehicle.h"

typedef Address *AddressPtr;

class Client;

typedef Client *ClientPtr;

class Rent;

typedef Rent *RentPtr;
typedef Vehicle *VehiclePtr;

#endif //CARRENTAL_TYPEDEFS_H
