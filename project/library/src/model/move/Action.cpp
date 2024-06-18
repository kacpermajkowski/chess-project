//
// Created by user on 12.06.2024.
//

#include <stdexcept>
#include "model/move/Action.h"
#include "model/Field.h"

Action::Action(ActionType type, const FieldPtr& actionField) : type(type) {
    if(actionField != nullptr){
        this->actionField = actionField;
        if(!actionField->isOccupied()){
            throw std::invalid_argument("Action field must be occupied");
        }
    } else throw std::invalid_argument("Action must have a field which it affects");
}

ActionType Action::getType() const {
    return type;
}

FieldPtr Action::getActionField() {
    return actionField;
}
