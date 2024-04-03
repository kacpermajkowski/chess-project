//CarRental project

#include <iostream>
#include "model/Client.h"

using namespace std;

int main(){
    Client cl1("Jan", "Nowak", "123");
    Client* cl2 = new Client("Adam", "Kowalski", "456");

    cout << cl1.getInfo() << endl;
    cout << cl2->getInfo() << endl;

    cl1.setFirstName("");

    cout << cl1.getInfo() << endl;

    delete cl2;
	return 0;
}
