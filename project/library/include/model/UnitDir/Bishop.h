#ifndef CHESSPROJECT_BISHOP_H
#define CHESSPROJECT_BISHOP_H

#include "Unit.h"

class Bishop : public Unit{
public:
    std::vector<std::vector<MoveVectorPtr>> getPossibleMoves() const;

    std::vector<MovePtr> getLegalMoves(StatePtr state) const override;

    std::vector<MovePtr> getAttackingMoves(StatePtr state) const override;
};


#endif //CHESSPROJECT_BISHOP_H
