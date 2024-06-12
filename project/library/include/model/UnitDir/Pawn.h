#ifndef CHESSPROJECT_PAWN_H
#define CHESSPROJECT_PAWN_H

#include "Unit.h"

class Pawn : public Unit{
public:
    std::vector<std::vector<MoveVectorPtr>> getPossibleMoves() const;

    std::vector<MovePtr> getLegalMoves(StatePtr state) const override;

    std::vector<MovePtr> getAttackingMoves(StatePtr state) const override;
};


#endif //CHESSPROJECT_PAWN_H
