#ifndef CHESSPROJECT_UNIT_H
#define CHESSPROJECT_UNIT_H

#include <vector>
#include "typedefs.h"
#include "model/move/Move.h"
#include "model/move/MoveVector.h"
/**
 * @brief Unit class represents an abstract unit with a specific color on the board
 * This class serves as the base class for all types of units in the game
 */
class Unit : public std::enable_shared_from_this<Unit>{
private:
    PlayerColor color; ///< The color of the unit
public:
    /**
     * @brief Constructor for creating a Unit object with a specified color
     * @param color The color of the unit (WHITE or BLACK)
     */
    explicit Unit(PlayerColor color);
    virtual ~Unit();

    /**
     * @return The PlayerColor representing the color of the unit
     */
    PlayerColor getColor();

    /**
     * @brief Calculates legal moves for the unit based on the current game state
     * @param state Pointer to the current game state
     * @return Vector of MovePtr objects representing legal moves for the unit
     */
    virtual std::vector<MovePtr> getLegalMoves(const StatePtr &state);

    /**
    * @brief Abstract method to get branches of possible move vectors for the unit
    * @return Vector of vectors of MoveVectorPtr objects representing move vector branches
    */
    virtual std::vector<std::vector<MoveVectorPtr>> getBranchesOfPossibleMoveVectors() = 0;

    /**
    * @brief Calculates attack coverage moves for the unit based on the current game state
    * @param state Pointer to the current game state
    * @return Vector of MovePtr objects representing attack coverage moves for the unit
    */
    virtual std::vector<MovePtr> getAttackCoverage(const StatePtr &state);

    /**
     * @brief Calculates check-breaking moves for the unit
     * @param state Pointer to the current game state
     * @return Vector of MovePtr objects representing check-breaking moves for the unit
     */
    std::vector<MovePtr> getCheckBreakingMoves(const StatePtr& state);

    /**
     * @param state Pointer to the current game state.
     * @return Pointer to the Field object representing the current field of the unit.
     */
    FieldPtr getCurrentField(const StatePtr& state);

    /**
     * @brief Calculates legal moves assuming no check for the unit based on the current game state
     * @param state Pointer to the current game state
     * @return Vector of MovePtr objects representing legal moves assuming no check for the unit
     */
    std::vector<MovePtr> getLegalMovesAssumeNoCheck(const StatePtr& state);

    /**
     * @brief Generates branches of positions reachable by the unit based on the current game state
     * @param state Pointer to the current game state
     * @return Vector of vectors of PositionPtr objects representing position branches
     */
    std::vector<std::vector<PositionPtr>> generatePositionBranches(const StatePtr &state);

    /**
     * @brief Generates move branches including occupied fields based on the current game state
     * @param state Pointer to the current game state
     * @return Vector of vectors of MovePtr objects representing move branches including occupied fields
     */
    std::vector<std::vector<MovePtr>> getMoveBranchesIncludeOccupiedFields(const StatePtr &state);
};


#endif //CHESSPROJECT_UNIT_H
