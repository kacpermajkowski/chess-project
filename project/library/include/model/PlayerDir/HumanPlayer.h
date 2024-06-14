#ifndef CHESSPROJECT_HUMANPLAYER_H
#define CHESSPROJECT_HUMANPLAYER_H

#include "Player.h"

class HumanPlayer : public Player{
public:
    explicit HumanPlayer(PlayerColor color);

    MovePtr chooseAMove(std::vector<MovePtr> legalMoves) override;
};


#endif //CHESSPROJECT_HUMANPLAYER_H
