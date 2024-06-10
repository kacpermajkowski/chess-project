#ifndef CHESSPROJECT_MOVE_H
#define CHESSPROJECT_MOVE_H

#include "Position.h"

class Move {
private:
    Position *startingPosition;
    Position *targetPosition;
    Color moverColor;
public:
    Move(Position *startingPosition, Position *targetPosition);
    virtual ~Move();

    Position *getStartingPosition() const;

    Position *getTargetPosition() const;

};


#endif //CHESSPROJECT_MOVE_H
