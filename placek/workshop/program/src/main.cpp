//CarRental project

#include <iostream>
#include "model/Client.h"


using namespace std;

int main(){
    Client cl1;
    Client* cl2 = new Client();

    cout << cl1.getInfo();

	return 0;
}
