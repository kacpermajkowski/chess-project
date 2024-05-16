//CarRental project

#include <iostream>
#include "model/Client.h"
#include "model/Address.h"
#include "model/Vehicle.h"
#include "model/Rent.h"
#include "model/Car.h"
#include "model/Bicycle.h"
#include "typedefs.h"

using namespace std;

int main(){


    AddressPtr addr = new Address("Poznan", "Ogrodowa", "17");
    ClientPtr cl1 = new Client("Adam", "Nowak", "123", addr, nullptr);
    VehiclePtr car = new Car("EL12345", 500, 1500, B);


//    pt::ptime now = pt::second_clock::local_time();
//
//    Rent* rent1 = new Rent(1, cl1, veh1, now);
//    rent1->endRent(now + pt::hours(5));

    cout << car->getInfo() << endl;
    cout << car->getActualRentalPrice() << endl;

	return 0;
}
