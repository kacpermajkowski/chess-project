#include "model/move/Move.h"

Move::~Move() {}

const UnitPtr Move::getMovedUnit() const {
    return movedUnit;
}


Move::Move(const UnitPtr movedUnit, const FieldPtr currentField, const FieldPtr targetField) :
        movedUnit(movedUnit),
        currentField(currentField),
        targetField(targetField)
{

}

const FieldPtr Move::getStartingPosition() const {
    return currentField;
}

const FieldPtr Move::getTargetPosition() const {
    return targetField;
}

const ActionPtr Move::getAction() const {
    return action;
}

void Move::setAction(const ActionPtr action) {
    Move::action = action;
}

