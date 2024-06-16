//
// Created by user on 14.06.2024.
//

#ifndef CHESSPROJECT_GAMEALREADYFINISHEDEXCEPTION_H
#define CHESSPROJECT_GAMEALREADYFINISHEDEXCEPTION_H

#include <exception>
#include <string>

/**
 * @brief Exception class to indicate that the game has already finished.
 *
 * This exception is thrown when an operation is attempted on a game that has already finished.
 */
class GameAlreadyFinishedException : public std::exception {
private:
    std::string message; /**< The exception message */
public:
    /**
     * @brief Destructor for the GameAlreadyFinishedException class.
     *
     * This destructor overrides the default destructor of std::exception.
     */
    ~GameAlreadyFinishedException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;

    /**
     * @brief Constructs a new GameAlreadyFinishedException with a specified message.
     *
     * @param message The exception message.
     */
    explicit GameAlreadyFinishedException(std::string message);

    /**
     * @brief Returns the exception message.
     *
     * This function overrides the what() function of std::exception to provide a custom message.
     *
     * @return The exception message as a C-style string.
     */
    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;
};

#endif //CHESSPROJECT_GAMEALREADYFINISHEDEXCEPTION_H