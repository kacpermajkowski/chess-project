#ifndef CHESSPROJECT_PAWN_H
#define CHESSPROJECT_PAWN_H

#include "Unit.h"

/**
 * @brief Pawn class represents a pawn unit

 */
class Pawn : public Unit{
private:
    NumberIndex promotionRow = _8; // Default promotion row for pawns
public:
    /**
     * @brief Constructor for creating a Pawn object with a specified color
     * @param color The color of the pawn (WHITE or BLACK)
     */
    explicit Pawn(PlayerColor color);

    /**
     * @brief Retrieves the possible move vectors for the pawn
     *
     * The pawn can move forward one or two squares on its first move, capture diagonally,
     * and perform en passant captures
     *
     * @return Vector of vectors of MoveVectorPtr objects representing possible move vectors
     */
    std::vector<std::vector<MoveVectorPtr>> getBranchesOfPossibleMoveVectors() override;

    /**
     * @brief Calculates legal moves for the pawn based on the current game state
     *
     * Overrides the base class method to compute legal moves specific to the pawn,
     * including standard moves, captures, and en passant captures
     *
     * @param state Pointer to the current game state
     * @return Vector of MovePtr objects representing legal moves for the pawn
     */
    std::vector<MovePtr> getLegalMoves(const StatePtr &state) override;

    /**
     * @brief Calculates attack coverage moves for the pawn based on the current game state
     *
     * Overrides the base class method to compute attack coverage specific to the pawn,
     * which includes diagonal captures
     *
     * @param state Pointer to the current game state
     * @return Vector of MovePtr objects representing attack coverage moves for the pawn
     */
    std::vector<MovePtr> getAttackCoverage(const StatePtr &state) override;
};


#endif //CHESSPROJECT_PAWN_H
