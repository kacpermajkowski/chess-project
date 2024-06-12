#include "model/move/Move.h"

Move::Move(UnitPtr movedUnit, PositionPtr targetPosition, PositionPtr startingPosition)
        : startingPosition(startingPosition),
          targetPosition(targetPosition) {}

Move::~Move() {}

PositionPtr Move::getStartingPosition() const {
    return startingPosition;
}

PositionPtr Move::getTargetPosition() const {
    return targetPosition;
}

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
