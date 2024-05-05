//
// Created by majkosia on 23.03.2024.
//

#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H

#include "Address.h"
#include "Rent.h"
#include <vector>

/// @brief Represents a real-world client
class Rent;

class Client {

private:
    std::string firstName;
    std::string lastName;
    const std::string personalID;
    Address* address;
    std::vector<Rent*> currentRents;

public:
    /**
     * @brief constructor
     *
     * @param firstName - first legal name
     * @param lastName - last legal name
     * @param personalID - unique identifier
     * @param address - physical postal address
     */
    Client(const std::string &firstName, const std::string &lastName, const std::string &personalID, Address* address);

    /// @brief destructor
    ~Client();

    /// @return all field values concatenated into one string
    const std::string getInfo() const;

    /// @return all field values concatenated into one string
    const std::string getFullInfo() const;

    /// @return get first legal name
    const std::string &getFirstName() const;

    /// @return get last legal name
    const std::string &getLastName() const;

    /// @return get unique client identifier
    const std::string &getPersonalID() const;

    /// @return get postal address
    const Address * getAddress() const;

    /// @return get vector with pointers to current rents
    const std::vector<Rent *> &getCurrentRents() const;

    /// @brief sets client's first name to a new value if it's a non-empty string
    /// @param firstName - new value of firstName. Has to be a non-empty string.
    void setFirstName(const std::string &firstName);

    /// @brief sets client's last name to a new value if it's a non-empty string
    /// @param lastName - new value of lastName. Has to be a non-empty string.
    void setLastName(const std::string &lastName);

    /// @brief sets client's postal address to a new value if it's a non-empty string
    /// @param address - new value of address. Has to be a non-empty string.
    void setAddress(Address* address);

    void addNewRent(Rent * newRent);

    void removeRent(unsigned int rentID);


};


#endif //CARRENTAL_CLIENT_H
