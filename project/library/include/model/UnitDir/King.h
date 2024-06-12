#ifndef CHESSPROJECT_KING_H
#define CHESSPROJECT_KING_H

#include "Unit.h"

class King : public Unit{
public:
    std::vector<std::vector<MoveVectorPtr>> getPossibleMoves() const;

    std::vector<MovePtr> getLegalMoves(StatePtr state) const override;

    std::vector<MovePtr> getLegalAttackingMoves(StatePtr state) const override;
};


#endif //CHESSPROJECT_KING_H
