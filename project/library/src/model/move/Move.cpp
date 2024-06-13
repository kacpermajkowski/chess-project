#include <stdexcept>
#include "model/move/Move.h"

Move::~Move() {}

const UnitPtr Move::getMovedUnit() const {
    return movedUnit;
}


Move::Move(FieldPtr currentField, FieldPtr targetField)
{
    if(currentField != nullptr && targetField != nullptr){
        if(!currentField->isOccupied()){
            throw std::invalid_argument("Current field for a move cannot be empty");
        }
        this->movedUnit = currentField->getUnit();
        this->currentField = currentField;
        this->targetField = targetField;
    } else throw std::invalid_argument("Pointers to both fields have to be valid");
}

const FieldPtr Move::getCurrentField() const {
    return currentField;
}

const FieldPtr Move::getTargetField() const {
    return targetField;
}

const ActionPtr Move::getAction() const {
    return action;
}

void Move::setAction(const ActionPtr action) {
    Move::action = action;
}

