#ifndef CHESSPROJECT_HUMANPLAYER_H
#define CHESSPROJECT_HUMANPLAYER_H

#include "Player.h"

/**
 * @brief HumanPlayer class represents a human player in the chess game
 *
 * This class allows a human player to choose moves via a user interface
 */
class HumanPlayer : public Player{
public:
    /**
     * @brief Constructs a HumanPlayer object with the specified color
     *
     * @param color The color assigned to the human player
     */
    explicit HumanPlayer(PlayerColor color);

    /**
     * @brief Allows the human player to choose a move
     *
     * This function interacts with the user interface to get input from the player for selecting a move
     *
     * @param game The current game instance
     * @return A pointer to the selected move
     */
    MovePtr chooseAMove(const GamePtr &game) override;
};


#endif //CHESSPROJECT_HUMANPLAYER_H
