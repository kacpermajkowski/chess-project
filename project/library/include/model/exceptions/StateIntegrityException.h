//
// Created by user on 15.06.2024.
//

#ifndef CHESSPROJECT_STATEINTEGRITYEXCEPTION_H
#define CHESSPROJECT_STATEINTEGRITYEXCEPTION_H

#include <exception>
#include <string>

class StateIntegrityException : public std::exception {
private:
    std::string message;
public:
    StateIntegrityException();

    explicit StateIntegrityException(const std::string &message);

    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;
};


#endif //CHESSPROJECT_STATEINTEGRITYEXCEPTION_H
