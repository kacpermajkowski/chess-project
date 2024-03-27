//
// Created by majkosia on 23.03.2024.
//

#ifndef START_CLIENT_H
#define START_CLIENT_H

/// @brief Represents a real-world client
class Client {

private:
    std::string firstName;
    std::string lastName;
    const std::string personalID;

public:
    /**
     * @brief constructor
     *
     * @param firstName - first legal name of a client
     * @param lastName - last legal name of a client
     * @param personalID - unique identifier of a client
     */
    Client(std::string firstName, std::string lastName, std::string personalID);

    /// @brief destructor
    ~Client();

    /// @return all field values concatenated into one string
    std::string getInfo();

    /// @return get first legal name of a client
    std::string getFirstName();

    /// @return get last legal name of a client
    std::string getLastName();

    /// @return get unique client identifier
    std::string getPerosnalID();

    /// @brief sets client's first name to a new value if it's a non-empty string
    /// @param firstName - new value of firstName. Has to be a non-empty string.
    void setFirstName(std::string firstName);

    /// @brief sets client's last name to a new value if it's a non-empty string
    /// @param lastName - new value of lastName. Has to be a non-empty string.
    void setLastName(std::string lastName);
};


#endif //START_CLIENT_H
