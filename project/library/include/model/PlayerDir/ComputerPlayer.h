#ifndef CHESSPROJECT_COMPUTERPLAYER_H
#define CHESSPROJECT_COMPUTERPLAYER_H


#include "Player.h"

class ComputerPlayer : public Player{
public:
    explicit ComputerPlayer(Color color);
    ~ComputerPlayer() override;

    Color getColor() const override;
    void makeAMove(Move move) override;
};


#endif //CHESSPROJECT_COMPUTERPLAYER_H
