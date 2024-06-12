#ifndef CHESSPROJECT_KING_H
#define CHESSPROJECT_KING_H

#include "Unit.h"

class King : public Unit{
public:

    explicit King(PlayerColor color);

    std::vector<std::vector<MoveVectorPtr>> getPossibleMoves() const;

    std::vector<MovePtr> getLegalMoves(StatePtr state) const override;

    std::vector<MovePtr> getAttackingMoves(StatePtr state) const override;
};


#endif //CHESSPROJECT_KING_H
