#include <iostream>

class Client{
private:
    std::string firstName;
    std::string lastName;
    const std::string personalID;

public:
    /**
     *
     * @brief constructor; sets client's values
     *
     * @param firstName client's real first name
     * @param lastName client's real last name
     * @param personalID client's unique identifier
     */
    Client(std::string firstName, std::string lastName, std::string personalID);
    ~Client();

    /// \return returns firstName, lastName and personalID
    std::string getInfo();

    /// \return returns firstName
    std::string getFirstName();
    /// \return returns lastName
    std::string getLastName();
    /// \return returns lastName
    std::string getPersonalID();

    /// \brief sets new value for client's real first name. if the provided value is empty, the first name remains unchanged.
    /// \param firstName - new value of firstName
    void setFirstName(std::string firstName);
    /// \brief sets new value for client's real last name. if the provided value is empty, the last name remains unchanged.
    /// \param lastName - new value of lastName
    void setLastName(std::string lastName);
};

