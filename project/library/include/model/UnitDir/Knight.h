#ifndef CHESSPROJECT_KNIGHT_H
#define CHESSPROJECT_KNIGHT_H

#include "Unit.h"

class Knight : public Unit{
public:
    std::vector<std::vector<MoveVectorPtr>> getPossibleMoves() const;

    std::vector<MovePtr> getLegalMoves(StatePtr state) const override;

    std::vector<MovePtr> getLegalAttackingMoves(StatePtr state) const override;
};


#endif //CHESSPROJECT_KNIGHT_H
