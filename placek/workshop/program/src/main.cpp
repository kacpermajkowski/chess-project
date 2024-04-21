//CarRental project

#include <iostream>
#include "model/Client.h"
#include "model/Address.h"

using namespace std;

int main(){




    Address* addr1 = new Address("Poznan", "Ogrodowa", "17");
    Client* cl1 = new Client("Adam", "Nowak", "123", addr1);
    Client* cl2 = new Client("Jan", "Kowalski", "456", addr1);

    Address* addr2 = new Address("Szczecin", "Parkowa", "21");
    cl2->setAddress(addr2);



    cout << cl1->getInfo() << endl;
    cout << cl2->getInfo() << endl;




	return 0;
}
