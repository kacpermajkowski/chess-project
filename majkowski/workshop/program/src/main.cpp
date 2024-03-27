// Introduction project.

#include <iostream>
#include "model/Client.h"

using namespace std;

int main()
{
    Client client1("Tester", "Testowski", "123456");
    Client* client2 = new Client("Kacper", "Majkowski", "251578");

    cout << client1.getInfo() << std::endl;
    cout << client2->getInfo() << std::endl;

    client1.setFirstName("Zlodziej");

    delete client2;
	return 0;
}
