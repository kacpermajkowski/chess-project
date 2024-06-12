#include "model/Move.h"

Move::Move(PositionPtr startingPosition, PositionPtr targetPosition) {}

Move::~Move() {}

PositionPtr Move::getStartingPosition() const {
    return startingPosition;
}

PositionPtr Move::getTargetPosition() const {
    return targetPosition;
}
