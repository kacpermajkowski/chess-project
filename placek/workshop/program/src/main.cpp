//CarRental project

#include <iostream>
#include "model/Client.h"
#include "model/Address.h"
#include "model/Vehicle.h"
#include "model/Rent.h"

using namespace std;

int main(){


    Address* addr1 = new Address("Poznan", "Ogrodowa", "17");
    Client* cl1 = new Client("Adam", "Nowak", "123", addr1);
    Vehicle* veh1 = new Vehicle("EL12345", 500);

//    Address* addr2 = new Address("Szczecin", "Parkowa", "21");
//    Client* cl2 = new Client("Jan", "Kowalski", "456", addr1);
//    Vehicle* veh2 = new Vehicle("KR67890", 800);

//    pt::ptime time1 = pt::ptime(gr::date(2015,5,10),pt::hours(12)+pt::minutes(0)+pt::seconds(0));
//    pt::ptime time2 = pt::ptime(gr::date(2015,5,11),pt::hours(12)+pt::minutes(0)+pt::seconds(0));
    pt::ptime now = pt::second_clock::local_time();

    Rent* rent1 = new Rent(1, cl1, veh1, now);
    rent1->endRent(now + pt::hours(5));


	return 0;
}
