#ifndef CHESSPROJECT_PLAYER_H
#define CHESSPROJECT_PLAYER_H


#include "typedefs.h"
#include "model/move/Move.h"

class Player {
private:
    PlayerColor color;

public:
    explicit Player(PlayerColor color);
    virtual ~Player();

    PlayerColor getColor() const;
    virtual void makeAMove(Move move) const = 0;
};


#endif //CHESSPROJECT_PLAYER_H
