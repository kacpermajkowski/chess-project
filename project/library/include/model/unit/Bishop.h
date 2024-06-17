#ifndef CHESSPROJECT_BISHOP_H
#define CHESSPROJECT_BISHOP_H

#include "Unit.h"

/**
 * @brief Bishop class represents a bishop unit
 */
class Bishop : public Unit{
public:
    /**
     * @brief Constructor for creating a Bishop object with a specified color
     * @param color The color of the bishop (WHITE or BLACK)
     */
    explicit Bishop(PlayerColor color);

    /**
     * @brief Retrieves the possible move vectors for the bishop
     *
     * The bishop can move diagonally across any number of squares in four directions:
     * top-right, top-left, bottom-right, and bottom-left
     *
     * @return Vector of vectors of MoveVectorPtr objects representing possible move vectors
     */
    std::vector<std::vector<MoveVectorPtr>> getBranchesOfPossibleMoveVectors();

    /**
     * @brief Calculates legal moves for the bishop based on the current game state
     *
     * Overrides the base class method to compute legal moves specific to the bishop
     *
     * @param state Pointer to the current game state
     * @return Vector of MovePtr objects representing legal moves for the bishop
     */
    std::vector<MovePtr> getLegalMoves(const StatePtr &state) override;

};


#endif //CHESSPROJECT_BISHOP_H
