#ifndef CHESSPROJECT_PLAYER_H
#define CHESSPROJECT_PLAYER_H


#include "typedefs.h"
#include "model/move/Move.h"

/**
 * @brief Player class is an abstract base class for different types of players in the chess game
 *
 * This class holds the basic attributes and methods required for a player, such as the player's color and
 * the ability to choose a move
 */
class Player : public std::enable_shared_from_this<Player>{
private:
    PlayerColor color; ///< The color of the player (WHITE or BLACK)

public:
    /**
     * @brief Constructs a Player object with the specified color
     *
     * @param color The color assigned to the player
     */
    explicit Player(PlayerColor color);
    virtual ~Player();

    /**
     * @return The color of the player.
     */
    PlayerColor getColor() const;

    /**
     * @brief Pure virtual function to choose a move
     *
     * This function must be implemented by derived classes to select a move based on the current game state
     *
     * @param game The current game instance
     * @return A pointer to the selected move
     */
    virtual MovePtr chooseAMove(const GamePtr &game) = 0;
};


#endif //CHESSPROJECT_PLAYER_H
