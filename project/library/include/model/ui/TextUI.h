#ifndef CHESSPROJECT_TEXTUI_H
#define CHESSPROJECT_TEXTUI_H

#include <map>
#include "UI.h"
#include "typedefs.h"

/**
 * @brief A text-based implementation of the User Interface for the chess game
 *
 * This class provides a console-based UI for displaying the game state,
 * handling end game conditions, and interacting with the user
 */
class TextUI : public UI{
public:
    /**
     * @brief Constructor for TextUI.
     */
    TextUI();

    /**
     * @brief Updates the console display with the current game state
     *
     * Overrides the abstract update function to print the board state and
     * piece positions to the console
     *
     * @param state Current state of the game to be displayed
     */
    void update(StatePtr state) override;

    /**
     * @brief Displays the end game screen in the console
     *
     * Overrides the abstract endGameScreen function to show the final
     * game state and the result of the game
     *
     * @param state Final state of the game to be displayed
     */
    void endGameScreen(StatePtr state) override;

    /**
     * @brief Gets a character input from the user within a specified range
     *
     * Overrides the abstract getFromUser function to prompt the user for input
     * and validate that the input falls within the given range
     *
     * @param begin The starting character of the valid input range
     * @param end The ending character of the valid input range
     * @return The character input from the user within the specified range
     */
    wchar_t getFromUser(wchar_t begin, wchar_t end) override;
    wchar_t getFromUser(std::map<wchar_t, wchar_t> ranges) override;

    /**
     * @brief Prompts the user to choose a player type and returns the corresponding Player object
     *
     * Overrides the abstract getPlayerByUserChoice function to prompt the user
     * to select between a human player and a computer player
     *
     * @param color The color of the player to be chosen
     * @return A shared pointer to the Player object chosen by the user
     */
    PlayerPtr getPlayerByUserChoice(PlayerColor color) override;
};


#endif //CHESSPROJECT_TEXTUI_H
