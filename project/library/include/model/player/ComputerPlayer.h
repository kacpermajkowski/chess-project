#ifndef CHESSPROJECT_COMPUTERPLAYER_H
#define CHESSPROJECT_COMPUTERPLAYER_H


#include "Player.h"

/**
 * @brief The ComputerPlayer class represents a computer-controlled player in the chess game
 *
 * This class allows a computer player to choose moves randomly from the list of legal moves
 */
class ComputerPlayer : public Player{
public:
    /**
     * @brief Constructs a ComputerPlayer object with the specified color
     *
     * @param color The color assigned to the computer player
     */
    explicit ComputerPlayer(PlayerColor color);

    /**
     * @brief Allows the computer player to choose a move
     *
     * This function selects a move randomly from the list of legal moves
     *
     * @param game The current game instance
     * @return A pointer to the selected move
     */
    MovePtr chooseAMove(const GamePtr &game) override;
};


#endif //CHESSPROJECT_COMPUTERPLAYER_H
