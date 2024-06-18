#ifndef CHESSPROJECT_GAME_H
#define CHESSPROJECT_GAME_H

#include "player/Player.h"
#include "State.h"
#include "typedefs.h"
#include "model/ui/UI.h"

/**
 * @brief Game class manages the overall flow of a chess game
 *
 * This class controls the players, the current state of the game, and the user interface
 * It handles the turn-based logic and ensures the game progresses until a conclusion is reached
 */
class Game : public std::enable_shared_from_this<Game>{
private:
    PlayerPtr firstPlayer; ///< Pointer to the first player
    PlayerPtr secondPlayer; ///< Pointer to the second player
    StatePtr state; ///< Pointer to the current state of the game
    UIPtr ui; ///< Pointer to the user interface for updating game display and receiving input

public:
    /**
     * @brief Constructs a Game object with the specified players and user interface
     *
     * @param firstPlayer A pointer to the first player
     * @param secondPlayer A pointer to the second player
     * @param ui A pointer to the user interface
     * @throws std::invalid_argument If both players are not of opposing colors or if any player pointer is null
     */
    Game(PlayerPtr firstPlayer, PlayerPtr secondPlayer, UIPtr ui);
    virtual ~Game();

    /**
     * @param color The color of the player to retrieve (WHITE or BLACK)
     * @return A pointer to the player with the specified color
     */
    PlayerPtr getPlayer(PlayerColor color) const;

    /**
     * @return A pointer to the current game state
     */
    StatePtr getState() const;

    /**
     * @return A pointer to the user interface
     */
    UIPtr getUI() const;

    /**
     * @brief Starts and runs the game loop
     *
     * The game loop continues until the game reaches a conclusion, alternating turns between players
     * and updating the user interface after each move
     */
    void run();
};


#endif //CHESSPROJECT_GAME_H
