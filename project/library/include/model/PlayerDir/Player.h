#ifndef CHESSPROJECT_PLAYER_H
#define CHESSPROJECT_PLAYER_H


#include "typedefs.h"
#include "model/move/Move.h"

class Player : public std::enable_shared_from_this<Player>{
private:
    PlayerColor color;

public:
    explicit Player(PlayerColor color);
    virtual ~Player();

    PlayerColor getColor() const;
    virtual MovePtr chooseAMove(const GamePtr &game) = 0;
};


#endif //CHESSPROJECT_PLAYER_H
