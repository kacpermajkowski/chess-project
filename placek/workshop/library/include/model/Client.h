#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H

#include <vector>
#include "Address.h"
#include "Rent.h"
#include "typedefs.h"
#include "ClientType.h"

class Rent;

class Client{
private:
    std::string firstName;
    std::string lastName;
    const std::string personalID;
    AddressPtr address;
    ClientType* clientType;
    std::vector<RentPtr> currentRents;

public:
    /**
     *
     * @brief constructor; sets client's values
     *
     * @param firstName client's real first name
     * @param lastName client's real last name
     * @param personalID client's unique identifier
     * @param address client's real address
     */
    Client(const std::string &firstName, const std::string &lastName, const std::string &personalID, AddressPtr address, ClientType* clientType);
    ~Client();

    /// \return returns firstName, lastName, personalID and address
    std::string getInfo() const;

    /// \return returns full info about the client: firstName, lastName, personalID, address and all rents
    std::string getFullInfo() const;

    /// \return returns firstName
    const std::string &getFirstName() const;
    /// \return returns lastName
    const std::string &getLastName() const;
    /// \return returns lastName
    const std::string &getPersonalID() const;
    /// \return returns address
    const AddressPtr getAddress() const;
    /// \return returns current rents
    const std::vector<RentPtr> &getCurrentRents() const;

    /// \brief sets new value for client's real first name. if the provided value is empty, the first name remains unchanged.
    /// \param firstName - new value of firstName
    void setFirstName(const std::string &firstName);
    /// \brief sets new value for client's real last name. if the provided value is empty, the last name remains unchanged.
    /// \param lastName - new value of lastName
    void setLastName(const std::string &lastName);
    /// \brief sets new value for client's real address. if the provided value is empty, the address remains unchanged.
    /// \param address - new value of address
    void setAddress(AddressPtr address);
    /// \brief adds new real rent to client's data
    /// \param rent - new client's rent
    void addRent(RentPtr rent);
    /// \brief removes rent from client's data
    /// \param rent - rent to be removed
    void removeRent(RentPtr rent);

    double applyDiscount(double price) const;

};

#endif //CARRENTAL_CLIENT_H