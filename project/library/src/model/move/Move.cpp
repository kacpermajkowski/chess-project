#include "model/move/Move.h"

Move::~Move() {}

const UnitPtr Move::getMovedUnit() const {
    return movedUnit;
}

const UnitPtr Move::getTakenUnit() const {
    return takenUnit;
}

void Move::setTakenUnit(const UnitPtr takenUnit) {
    Move::takenUnit = takenUnit;
}

void Move::setType(MoveType type) {
    Move::type = type;
}

Move::Move(const UnitPtr movedUnit, const FieldPtr startingPosition, const FieldPtr targetPosition) :
    movedUnit(movedUnit),
    startingPosition(startingPosition),
    targetPosition(targetPosition)
{

}

const FieldPtr Move::getStartingPosition() const {
    return startingPosition;
}

const FieldPtr Move::getTargetPosition() const {
    return targetPosition;
}
