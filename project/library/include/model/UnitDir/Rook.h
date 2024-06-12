#ifndef CHESSPROJECT_ROOK_H
#define CHESSPROJECT_ROOK_H

#include "Unit.h"

class Rook : public Unit{
public:
    std::vector<std::vector<MoveVectorPtr>> getPossibleMoves() const;

    std::vector<MovePtr> getAttackingMoves(StatePtr state) override;

    std::vector<MovePtr> getLegalMoves(const StatePtr state) override;

};


#endif //CHESSPROJECT_ROOK_H
