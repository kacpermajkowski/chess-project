// Introduction project.

#include <iostream>
#include "model/Client.h"
#include "model/Address.h"

using namespace std;

int main()
{
//    Client client1("Tester", "Testowski", "123456", nullptr);
//    Client* client2 = new Client("Kacper", "Majkowski", "251578", nullptr);
//
//    cout << client1.getInfo() << std::endl;
//    cout << client2->getInfo() << std::endl;
//
//    client1.setFirstName("Zlodziej");
//
//    delete client2;

    Address* address = new Address("Szadek", "Prusinowska", "4");
    Client* client1 = new Client("Kacper", "Majkowski", "251578", nullptr);
    Client* client2 = new Client("Kuba", "Majkowski", "123456", address);

    client1->setAddress(address);
    address->setCity("AUUUU");

    cout << client1->getInfo() << endl;
    cout << client2->getInfo() << endl;




	return 0;
}
