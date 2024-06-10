#include "model/Move.h"

Move::Move(Position *startingPosition, Position *targetPosition) : startingPosition(startingPosition),
                                                                   targetPosition(targetPosition) {}

Move::~Move() {}

Position *Move::getStartingPosition() const {
    return startingPosition;
}

Position *Move::getTargetPosition() const {
    return targetPosition;
}
