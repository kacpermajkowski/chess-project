//CarRental project

#include <iostream>
#include "model/Client.h"
#include "model/Address.h"
#include "model/Vehicle.h"
#include "model/Rent.h"

using namespace std;

int main(){


        const Address addr1 ("Poznan", "Ogrodowa", "17");
        cout << addr1.getInfo() << endl;



//    Address* addr2 = new Address("Szczecin", "Parkowa", "21");
//
//    Client* cl1 = new Client("Adam", "Nowak", "123", addr1);
//    Client* cl2 = new Client("Jan", "Kowalski", "456", addr1);
//
//    Vehicle* veh1 = new Vehicle("EL12345", 500);
//    Vehicle* veh2 = new Vehicle("KR67890", 800);
//
//    Rent* rent1 = new Rent(1, cl1, veh1);
//    Rent* rent2 = new Rent(2, cl1, veh2);
//
//    cout << cl1->getInfo() << endl;
//    cout << veh1->getInfo() << endl;
//    cout << rent1->getInfo() << endl << endl;
//    cout << cl1->getFullInfo() << endl;






	return 0;
}
