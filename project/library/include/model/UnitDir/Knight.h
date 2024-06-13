#ifndef CHESSPROJECT_KNIGHT_H
#define CHESSPROJECT_KNIGHT_H

#include "Unit.h"

class Knight : public Unit{
public:

    explicit Knight(PlayerColor color);

    std::vector<std::vector<MoveVectorPtr>> getPossibleMoves();

    std::vector<MovePtr> getLegalMoves(StatePtr state) override;

    std::vector<MovePtr> getPossibleFutureAttacks(StatePtr state) override;
};


#endif //CHESSPROJECT_KNIGHT_H
