#ifndef CHESSPROJECT_ROOK_H
#define CHESSPROJECT_ROOK_H

#include "Unit.h"

class Rook : public Unit{
public:
    std::vector<std::vector<MoveVectorPtr>> getPossibleMoves() const;

    std::vector<MovePtr> getLegalAttackingMoves(StatePtr state) const override;

    std::vector<MovePtr> getLegalMoves(StatePtr state) const override;

};


#endif //CHESSPROJECT_ROOK_H
