//
// Created by majkosia on 23.03.2024.
//

#ifndef START_CLIENT_H
#define START_CLIENT_H

class Client {

private:

    std::string firstName;
    std::string lastName;
    std::string personalID;
public:
    Client(std::string firstName, std::string lastName, std::string personalID);
    ~Client();

    std::string getInfo();
};


#endif //START_CLIENT_H
