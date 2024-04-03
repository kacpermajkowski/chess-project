#include <iostream>

class Client{
private:
    std::string firstName;
    std::string lastName;
    const std::string personalID;

public:
    Client(std::string firstName, std::string lastName, std::string personalID);
    ~Client();

    std::string getInfo();

    std::string getFirstName();
    std::string getLastName();
    std::string getPersonalID();

    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
};

