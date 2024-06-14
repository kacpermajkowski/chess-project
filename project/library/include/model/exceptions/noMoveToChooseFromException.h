//
// Created by majkosia on 14.06.2024.
//

#ifndef CHESSPROJECT_NOMOVETOCHOOSEFROMEXCEPTION_H
#define CHESSPROJECT_NOMOVETOCHOOSEFROMEXCEPTION_H

#include <exception>

class noMoveToChooseFromException : public std::exception{
private:
    char* message;
public:
    noMoveToChooseFromException();

    explicit noMoveToChooseFromException(char *message);

    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;

};


#endif //CHESSPROJECT_NOMOVETOCHOOSEFROMEXCEPTION_H
