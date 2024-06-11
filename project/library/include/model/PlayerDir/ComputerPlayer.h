#ifndef CHESSPROJECT_COMPUTERPLAYER_H
#define CHESSPROJECT_COMPUTERPLAYER_H


#include "Player.h"

class ComputerPlayer : public Player{
public:
    explicit ComputerPlayer(PlayerColor color);

    void makeAMove(Move move) const override;
};


#endif //CHESSPROJECT_COMPUTERPLAYER_H
