#ifndef CHESSPROJECT_HUMANPLAYER_H
#define CHESSPROJECT_HUMANPLAYER_H

#include "Player.h"

class HumanPlayer : public Player{
public:
    explicit HumanPlayer(Color color);
    ~HumanPlayer() override;

    Color getColor() const override;
    void makeAMove(Move move) override;
};


#endif //CHESSPROJECT_HUMANPLAYER_H
