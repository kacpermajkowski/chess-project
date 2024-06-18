#ifndef CHESSPROJECT_QUEEN_H
#define CHESSPROJECT_QUEEN_H

#include "Unit.h"

/**
 * @brief Queen class represents a queen unit
 */
class Queen : public Unit{
public:
    /**
     * @brief Constructor for creating a Queen object with a specified color
     * @param color The color of the queen (WHITE or BLACK)
     */
    explicit Queen(PlayerColor color);

    /**
     * @brief Retrieves the possible move vectors for the queen
     *
     * The queen can move horizontally, vertically, or diagonally across any number of squares
     *
     * @return Vector of vectors of MoveVectorPtr objects representing possible move vectors
     */
    std::vector<std::vector<MoveVectorPtr>> getBranchesOfPossibleMoveVectors();

    /**
     * @brief Calculates legal moves for the queen based on the current game state
     *
     * Overrides the base class method to compute legal moves specific to the queen
     *
     * @param state Pointer to the current game state
     * @return Vector of MovePtr objects representing legal moves for the queen
     */
    std::vector<MovePtr> getLegalMoves(const StatePtr &state) override;

};


#endif //CHESSPROJECT_QUEEN_H
