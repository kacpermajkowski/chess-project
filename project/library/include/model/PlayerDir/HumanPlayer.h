#ifndef CHESSPROJECT_HUMANPLAYER_H
#define CHESSPROJECT_HUMANPLAYER_H

#include "Player.h"

class HumanPlayer : public Player{
public:
    explicit HumanPlayer(PlayerColor color);

    void makeAMove(Move move) const override;
};


#endif //CHESSPROJECT_HUMANPLAYER_H
