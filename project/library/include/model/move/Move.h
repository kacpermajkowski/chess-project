#ifndef CHESSPROJECT_MOVE_H
#define CHESSPROJECT_MOVE_H

#include "model/Position.h"

class Move {
private:
    PositionPtr startingPosition;
    PositionPtr targetPosition;
    UnitPtr movedUnit;
    UnitPtr takenUnit = nullptr;
    MoveType type = REGULAR;
public:
    Move(UnitPtr movedUnit, PositionPtr targetPosition, PositionPtr startingPosition);
    virtual ~Move();

    UnitPtr const getMovedUnit() const;

    UnitPtr const getTakenUnit() const;

    PositionPtr getStartingPosition() const;
    PositionPtr getTargetPosition() const;

    void setTakenUnit(const UnitPtr takenUnit);

    void setType(MoveType type);

};


#endif //CHESSPROJECT_MOVE_H
