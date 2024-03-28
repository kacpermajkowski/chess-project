#include <iostream>

class Client{
public:
    Client();
    ~Client();
    std::string getInfo();
private:
    std::string firstName;
    std::string lastName;
    std::string personalID;
};

