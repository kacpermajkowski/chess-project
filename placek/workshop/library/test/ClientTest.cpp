#include <boost/test/unit_test.hpp>
#include "model/Client.h"

struct TestSuiteClientFixture {
    const std::string firstName1 = "Adam";
    const std::string lastName1 = "Nowak";
    const std::string personalID1 = "123";

    const std::string firstName2 = "Jan";
    const std::string lastName2 = "Kowalski";

    Address *address1;
    Address *address2;

    TestSuiteClientFixture() {
        address1 = new Address("Poznan", "Ogrodowa", "17");
        address2 = new Address("Szczecin", "Parkowa", "21");
    }

    ~TestSuiteClientFixture() {
        delete address1;
        delete address2;
    }

};


BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

            /// \brief example tests
            BOOST_AUTO_TEST_CASE(AssertionsTests) {
                    BOOST_TEST(1.0/3.0 == 0.333, boost::test_tools::tolerance(0.01));
                    BOOST_TEST(true);
            }


/// \brief checks if getter returns correct value
BOOST_AUTO_TEST_CASE(TestConstructorClient){
    Client client(firstName1, lastName1, personalID1, address1);
    BOOST_TEST(client.getFirstName()==firstName1);
    BOOST_TEST(client.getLastName()==lastName1);
    BOOST_TEST(client.getPersonalID()==personalID1);
    BOOST_TEST(client.getAddress()==address1);
}

/// \brief checks setter sets correct value that cannot be empty

    BOOST_AUTO_TEST_CASE(TestSetterClient){
        Client client(firstName1, lastName1, personalID1, address1);
        client.setFirstName(firstName2);
        client.setLastName(lastName2);
        client.setAddress(address2);

        client.setFirstName("");
        client.setLastName("");
        client.setAddress(nullptr);

        BOOST_TEST(client.getFirstName()==firstName2);
        BOOST_TEST(client.getLastName()==lastName2);
        BOOST_TEST(client.getAddress()==address2);
    }

BOOST_AUTO_TEST_SUITE_END()
