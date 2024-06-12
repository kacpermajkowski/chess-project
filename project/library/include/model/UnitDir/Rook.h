#ifndef CHESSPROJECT_ROOK_H
#define CHESSPROJECT_ROOK_H

#include "Unit.h"

class Rook : public Unit{
public:

    explicit Rook(PlayerColor color);

    std::vector<std::vector<MoveVectorPtr>> getPossibleMoves() const;

    std::vector<MovePtr> getAttackingMoves(StatePtr state) const override;

    std::vector<MovePtr> getLegalMoves(StatePtr state) const override;

};


#endif //CHESSPROJECT_ROOK_H
