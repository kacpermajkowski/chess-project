#ifndef CHESSPROJECT_ROOK_H
#define CHESSPROJECT_ROOK_H

#include "Unit.h"

/**
 * @brief Rook class represents a rook unit
 */
class Rook : public Unit{
public:
    /**
     * @brief Constructor for creating a Rook object with a specified color
     * @param color The color of the rook (WHITE or BLACK)
     */
    explicit Rook(PlayerColor color);

    /**
     * @brief Retrieves the possible move vectors for the rook
     *
     * The rook can move horizontally or vertically across any number of squares
     *
     * @return Vector of vectors of MoveVectorPtr objects representing possible move vectors
     */
    std::vector<std::vector<MoveVectorPtr>> getBranchesOfPossibleMoveVectors() override;

    /**
     * @brief Calculates legal moves for the rook based on the current game state
     *
     * Overrides the base class method to compute legal moves specific to the rook
     *
     * @param state Pointer to the current game state
     * @return Vector of MovePtr objects representing legal moves for the rook
     */
    std::vector<MovePtr> getLegalMoves(const StatePtr &state) override;
};


#endif //CHESSPROJECT_ROOK_H
