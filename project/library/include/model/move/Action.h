//
// Created by user on 12.06.2024.
//

#ifndef CHESSPROJECT_ACTION_H
#define CHESSPROJECT_ACTION_H


#include "typedefs.h"

/**
 * @brief Action class represents an action that can be performed during a move
 *
 * Actions are tied to moves and define what specific action occurs as a result of the move,
 * such as capturing an opponent's piece or promoting a pawn
 */
class Action : public std::enable_shared_from_this<Action> {
private:
    ActionType type; ///< The type of action (e.g., CAPTURE, PROMOTION, etc.)
    FieldPtr actionField; ///< The field on which the action takes place

public:
    /**
     * @brief Constructs an Action object with a specified type and associated field
     * @param type The type of the action (e.g., CAPTURE, PROMOTION)
     * @param actionField The field where the action will be applied
     */
    Action(ActionType type, const FieldPtr& actionField);

    /**
     * @return The ActionType representing the type of action
     */
    ActionType getType() const;

    /**
     * @return Pointer to the Field where the action occurs
     */
    FieldPtr getActionField();
};


#endif //CHESSPROJECT_ACTION_H
