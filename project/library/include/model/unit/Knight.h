#ifndef CHESSPROJECT_KNIGHT_H
#define CHESSPROJECT_KNIGHT_H

#include "Unit.h"

/**
 * @brief Knight class represents a knight unit
 */
class Knight : public Unit{
public:
    /**
     * @brief Constructor for creating a Knight object with a specified color
     * @param color The color of the knight (WHITE or BLACK)
     */
    explicit Knight(PlayerColor color);

    /**
     * @brief Retrieves the possible move vectors for the knight
     *
     * The knight moves in an "L" shape: two squares in one direction and then one square perpendicular,
     * making it the only piece able to jump over others
     *
     * @return Vector of vectors of MoveVectorPtr objects representing possible move vectors
     */
    std::vector<std::vector<MoveVectorPtr>> getBranchesOfPossibleMoveVectors();

    /**
     * @brief Calculates legal moves for the knight based on the current game state
     *
     * Overrides the base class method to compute legal moves specific to the knight
     *
     * @param state Pointer to the current game state
     * @return Vector of MovePtr objects representing legal moves for the knight
     */
    std::vector<MovePtr> getLegalMoves(const StatePtr &state) override;

};


#endif //CHESSPROJECT_KNIGHT_H
