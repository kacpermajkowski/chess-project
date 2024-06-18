#ifndef CHESSPROJECT_KING_H
#define CHESSPROJECT_KING_H

#include "Unit.h"
/**
 * @brief King class represents a king unit
 */
class King : public Unit{
public:
    /**
     * @brief Constructor for creating a King object with a specified color
     * @param color The color of the king (WHITE or BLACK)
     */
    explicit King(PlayerColor color);

    /**
     * @brief Retrieves the possible move vectors for the king
     *
     * The king can move one square in any direction (horizontally, vertically, or diagonally)
     *
     * @return Vector of vectors of MoveVectorPtr objects representing possible move vectors
     */
    std::vector<std::vector<MoveVectorPtr>> getBranchesOfPossibleMoveVectors();

    /**
     * @brief Calculates legal moves for the king based on the current game state
     *
     * Overrides the base class method to compute legal moves specific to the king,
     * including checks to avoid moving into check and potential castling moves
     *
     * @param state Pointer to the current game state
     * @return Vector of MovePtr objects representing legal moves for the king
     */
    std::vector<MovePtr> getLegalMoves(const StatePtr &state) override;

};


#endif //CHESSPROJECT_KING_H
