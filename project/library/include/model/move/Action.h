//
// Created by user on 12.06.2024.
//

#ifndef CHESSPROJECT_ACTION_H
#define CHESSPROJECT_ACTION_H


#include "typedefs.h"

class Action : public std::enable_shared_from_this<Action> {
private:
    ActionType type;
    FieldPtr actionField;

public:
    Action(ActionType type, FieldPtr actionField);

    ActionType getType() const;

    FieldPtr getActionField();
};


#endif //CHESSPROJECT_ACTION_H
