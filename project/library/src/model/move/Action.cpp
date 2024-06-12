//
// Created by user on 12.06.2024.
//

#include "model/move/Action.h"

Action::Action(ActionType type, const FieldPtr actionField) : type(type), actionField(actionField) {}

ActionType Action::getType() const {
    return type;
}

const FieldPtr Action::getActionField() {
    return actionField;
}
