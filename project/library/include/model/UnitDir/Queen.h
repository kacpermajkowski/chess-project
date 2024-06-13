#ifndef CHESSPROJECT_QUEEN_H
#define CHESSPROJECT_QUEEN_H

#include "Unit.h"

class Queen : public Unit{
public:

    explicit Queen(PlayerColor color);

    std::vector<std::vector<MoveVectorPtr>> getPossibleMoves();

    std::vector<MovePtr> getLegalMoves(StatePtr state) override;

    std::vector<MovePtr> getPossibleFutureAttacks(StatePtr state) override;
};


#endif //CHESSPROJECT_QUEEN_H
