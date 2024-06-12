#ifndef CHESSPROJECT_MOVE_H
#define CHESSPROJECT_MOVE_H

#include "model/Position.h"

class Move {
private:
    FieldPtr startingPosition;
    FieldPtr targetPosition;
    UnitPtr movedUnit;
    UnitPtr takenUnit = nullptr;
    MoveType type = REGULAR;
public:
    Move(const UnitPtr movedUnit, const FieldPtr startingPosition, const FieldPtr targetPosition);

    virtual ~Move();

    UnitPtr const getMovedUnit() const;

    UnitPtr const getTakenUnit() const;

    const FieldPtr getStartingPosition() const;

    const FieldPtr getTargetPosition() const;

    void setTakenUnit(const UnitPtr takenUnit);

    void setType(MoveType type);

};


#endif //CHESSPROJECT_MOVE_H
