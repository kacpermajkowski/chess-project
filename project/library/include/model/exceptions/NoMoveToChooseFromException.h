//
// Created by majkosia on 14.06.2024.
//

#ifndef CHESSPROJECT_NOMOVETOCHOOSEFROMEXCEPTION_H
#define CHESSPROJECT_NOMOVETOCHOOSEFROMEXCEPTION_H

#include <exception>
#include <string>

class NoMoveToChooseFromException : public std::exception{
private:
    std::string message;
public:
    NoMoveToChooseFromException();

    explicit NoMoveToChooseFromException(std::string message);

    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;

};


#endif //CHESSPROJECT_NOMOVETOCHOOSEFROMEXCEPTION_H
