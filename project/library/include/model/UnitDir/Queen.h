#ifndef CHESSPROJECT_QUEEN_H
#define CHESSPROJECT_QUEEN_H

#include "Unit.h"

class Queen : public Unit{
public:
    std::vector<std::vector<MoveVectorPtr>> getPossibleMoves() const;

    std::vector<MovePtr> getLegalMoves(StatePtr state) const override;

    std::vector<MovePtr> getLegalAttackingMoves(StatePtr state) const override;
};


#endif //CHESSPROJECT_QUEEN_H
