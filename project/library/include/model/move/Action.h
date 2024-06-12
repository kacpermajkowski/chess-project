//
// Created by user on 12.06.2024.
//

#ifndef CHESSPROJECT_ACTION_H
#define CHESSPROJECT_ACTION_H


#include "typedefs.h"

class Action {
private:
    ActionType type;
    FieldPtr actionField;

public:
    Action(ActionType type, const FieldPtr actionField);

    ActionType getType() const;

    const Field *getActionField() const;
};


#endif //CHESSPROJECT_ACTION_H
