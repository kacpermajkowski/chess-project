#ifndef CHESSPROJECT_PLAYER_H
#define CHESSPROJECT_PLAYER_H


#include "enum.h"
#include "model/Move.h"

class Player {
private:
    Color color;

public:
    explicit Player(Color color);
    virtual ~Player();

    virtual Color getColor() const;
    virtual void makeAMove(Move move);
};


#endif //CHESSPROJECT_PLAYER_H
