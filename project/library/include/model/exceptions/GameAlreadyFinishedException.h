//
// Created by user on 14.06.2024.
//

#ifndef CHESSPROJECT_GAMEALREADYFINISHEDEXCEPTION_H
#define CHESSPROJECT_GAMEALREADYFINISHEDEXCEPTION_H


#include <exception>
#include <string>

class GameAlreadyFinishedException : public std::exception{
private:
    std::string message;
public:
    ~GameAlreadyFinishedException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;

    explicit GameAlreadyFinishedException(std::string message);

    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;

};


#endif //CHESSPROJECT_GAMEALREADYFINISHEDEXCEPTION_H
