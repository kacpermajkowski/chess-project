// Introduction project.

#include <iostream>
#include "model/Client.h"
#include "model/Address.h"

#include <boost/date_time.hpp>

namespace pt = boost::posix_time;
using namespace std;

int main()
{
// eksperyment 1
//    Client client1("Tester", "Testowski", "123456", nullptr);
//    Client* client2 = new Client("Kacper", "Majkowski", "251578", nullptr);
//
//    cout << client1.getInfo() << std::endl;
//    cout << client2->getInfo() << std::endl;
//
//    client1.setFirstName("Zlodziej");
//
//    delete client2;
// eksperyment 2
//    Address* address = new Address("Szadek", "Prusinowska", "4");
//    Client* client1 = new Client("Kacper", "Majkowski", "251578", nullptr);
//    Client* client2 = new Client("Kuba", "Majkowski", "123456", address);
//
//    client1->setAddress(address);
//    address->setCity("AUUUU");
//
//    cout << client1->getInfo() << endl;
//    cout << client2->getInfo() << endl;
// eksperyment 3
//    Address* address = new Address("Szadek", "Prusinowska", "4");
//    string fname1 = "Jon";
//    Client c(fname1,"Arbuckle", "0123456789", address);
//    fname1.assign("Doc Boy");
//    cout << c.getFirstName() << endl;
//
//    string fname2 = "Garfield";
//    c.setFirstName(fname2);
//    fname2.assign("Liz");
//    cout << c.getFirstName() << endl;
// eksperyment 4
    Address* address = new Address("Łódź", "Piotrkowska", "17");
    Client* client = new Client("Kacper", "Majkowski", "251578", address, nullptr);
    Vehicle* vehicle = new Vehicle("EZD 10000", 1234);
    pt::ptime now = pt::second_clock::local_time();
    Rent* rent = new Rent(1, client, vehicle, pt::not_a_date_time);

	return 0;
}
