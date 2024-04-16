//
// Created by majkosia on 23.03.2024.
//

#ifndef START_CLIENT_H
#define START_CLIENT_H

#include "Address.h"

/// @brief Represents a real-world client
class Client {

private:
    std::string firstName;
    std::string lastName;
    const std::string personalID;
    Address* address;

public:
    /**
     * @brief constructor
     *
     * @param firstName - first legal name
     * @param lastName - last legal name
     * @param personalID - unique identifier
     * @param address - physical postal address
     */
    Client(std::string firstName, std::string lastName, std::string personalID, Address* address);

    /// @brief destructor
    ~Client();

    /// @return all field values concatenated into one string
    std::string getInfo();

    /// @return get first legal name
    std::string getFirstName();

    /// @return get last legal name
    std::string getLastName();

    /// @return get unique client identifier
    std::string getPersonalID();

    /// @return get postal address
    Address* getAddress();

    /// @brief sets client's first name to a new value if it's a non-empty string
    /// @param firstName - new value of firstName. Has to be a non-empty string.
    void setFirstName(std::string firstName);

    /// @brief sets client's last name to a new value if it's a non-empty string
    /// @param lastName - new value of lastName. Has to be a non-empty string.
    void setLastName(std::string lastName);

    /// @brief sets client's postal address to a new value if it's a non-empty string
    /// @param address - new value of address. Has to be a non-empty string.
    void setAddress(Address* address);
};


#endif //START_CLIENT_H
