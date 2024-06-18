#ifndef CHESSPROJECT_UI_H
#define CHESSPROJECT_UI_H

#include "typedefs.h"
#include <memory>

/**
 * @brief Abstract base class for the User Interface in the chess game
 *
 * This class defines the interface for any UI implementation, ensuring
 * consistent methods for updating the game state on the screen, ending the game,
 * and interacting with the user
 */
class UI : public std::enable_shared_from_this<UI>{
public:
    /**
     * @brief Pure virtual function to update the game state display
     *
     * This method should be implemented by derived classes to update
     * the visual representation of the game state
     *
     * @param state Current state of the game to be displayed
     */
    virtual void update(StatePtr state) = 0;

    /**
     * @brief Pure virtual function to display the end game screen
     *
     * This method should be implemented by derived classes to show
     * the final game state and any conclusion details
     *
     * @param state Final state of the game to be displayed
     */
    virtual void endGameScreen(StatePtr state) = 0;

    /**
     * @brief Pure virtual function to get a character input from the user
     *
     * This method should prompt the user for input within a specified range
     * and return the chosen character
     *
     * @param begin The starting character of the valid input range
     * @param end The ending character of the valid input range
     * @return The character input from the user within the specified range
     */
    virtual wchar_t getFromUser(wchar_t begin, wchar_t end) = 0;
    //virtual PromotionType getTypeOfPromotion() = 0;

    /**
     * @brief Pure virtual function to get a Player object based on user input
     *
     * This method should prompt the user to select a player type (e.g., Human or Computer)
     * and return a corresponding Player object
     *
     * @param color The color of the player to be chosen
     * @return A shared pointer to the Player object chosen by the user
     */
    virtual PlayerPtr getPlayerByUserChoice(PlayerColor color) = 0;
};


#endif //CHESSPROJECT_UI_H
