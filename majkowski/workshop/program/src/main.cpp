// Introduction project.

#include <iostream>
#include "math_helpers.h"
#include "model/Client.h"

using namespace std;

int main()
{
    Client client1;
    Client* client2 = new Client("Kacper", "Majkowski", "251578");

    cout << client1.getInfo() << std::endl;
    cout << client2->getInfo() << std::endl;
	return 0;
}
