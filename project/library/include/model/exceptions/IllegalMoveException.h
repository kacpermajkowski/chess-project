//
// Created by user on 15.06.2024.
//

#ifndef CHESSPROJECT_ILLEGALMOVEEXCEPTION_H
#define CHESSPROJECT_ILLEGALMOVEEXCEPTION_H

#include <exception>
#include <string>

using namespace std;

class IllegalMoveException : public exception{
private:
    string message = "This move cannot be performed, as it is illegal in this state.";
public:
    IllegalMoveException();
    explicit IllegalMoveException(string message);

    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;

};

#endif //CHESSPROJECT_ILLEGALMOVEEXCEPTION_H



