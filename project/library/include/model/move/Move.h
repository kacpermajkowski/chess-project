#ifndef CHESSPROJECT_MOVE_H
#define CHESSPROJECT_MOVE_H

#include "model/Position.h"
#include "model/Field.h"
#include "Action.h"

/**
 * @brief Move class represents a move made by a unit on the chessboard
 *
 * A Move object defines the initial and target positions of a move,
 * the unit being moved, and any actions associated with the move, such as captures or special moves
 */
class Move : public std::enable_shared_from_this<Move> {
private:
    FieldPtr currentField; ///< The field from which the move starts
    FieldPtr targetField; ///< The field to which the move is directed
    UnitPtr movedUnit; ///< The unit being moved
    ActionPtr action = nullptr; ///< The action associated with the move, if any
public:
    /**
     * @brief Constructs a Move object given the starting and target fields
     * @param currentField The field from which the move starts
     * @param targetField The field to which the move is directed
     */
    Move(const FieldPtr currentField, const FieldPtr targetField);

    virtual ~Move();

    /**
     * @return A pointer to the Unit being moved.
     */
    const UnitPtr getMovedUnit() const;

    /**
     * @return A pointer to the starting Field of the move
     */
    const FieldPtr getCurrentField() const;

    /**
     * @return A pointer to the target Field of the move
     */
    const FieldPtr getTargetField() const;

    /**
     * @return A pointer to the Action associated with the move
     */
    const ActionPtr getAction() const;

    /**
     * @brief Sets the action associated with the move
     * @param action The action to be associated with the move
     */
    void setAction(const ActionPtr action);

};


#endif //CHESSPROJECT_MOVE_H
