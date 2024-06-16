#ifndef CHESSPROJECT_COMPUTERPLAYER_H
#define CHESSPROJECT_COMPUTERPLAYER_H


#include "Player.h"

class ComputerPlayer : public Player{
public:
    explicit ComputerPlayer(PlayerColor color);

    MovePtr chooseAMove(const GamePtr &game) override;
};


#endif //CHESSPROJECT_COMPUTERPLAYER_H
