//
// Created by user on 15.06.2024.
//

#ifndef CHESSPROJECT_ILLEGALMOVEEXCEPTION_H
#define CHESSPROJECT_ILLEGALMOVEEXCEPTION_H

#include <exception>
#include <string>

using namespace std;

/**
 * @brief Exception class to indicate an illegal move in a chess game.
 *
 * This exception is thrown when an illegal move is attempted in the chess game.
 */
class IllegalMoveException : public exception {
private:
    string message = "This move cannot be performed, as it is illegal in this state."; /**< The default exception message */
public:
    /**
     * @brief Constructs a new IllegalMoveException with a default message.
     */
    IllegalMoveException();

    /**
     * @brief Constructs a new IllegalMoveException with a specified message.
     *
     * @param message The exception message.
     */
    explicit IllegalMoveException(string message);

    /**
     * @brief Returns the exception message.
     *
     * This function overrides the what() function of std::exception to provide a custom message.
     *
     * @return The exception message as a C-style string.
     */
    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;
};

#endif //CHESSPROJECT_ILLEGALMOVEEXCEPTION_H