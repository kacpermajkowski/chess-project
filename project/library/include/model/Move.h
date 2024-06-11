#ifndef CHESSPROJECT_MOVE_H
#define CHESSPROJECT_MOVE_H

#include "Position.h"

class Move {
private:
    PositionPtr startingPosition;
    PositionPtr targetPosition;
    PlayerColor moverColor;
public:
    Move(PositionPtr startingPosition, PositionPtr targetPosition);
    virtual ~Move();

    PositionPtr getStartingPosition() const;

    PositionPtr getTargetPosition() const;

};


#endif //CHESSPROJECT_MOVE_H
