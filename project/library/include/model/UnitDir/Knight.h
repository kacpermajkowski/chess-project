#ifndef CHESSPROJECT_KNIGHT_H
#define CHESSPROJECT_KNIGHT_H

#include "Unit.h"

class Knight : public Unit{
public:

    explicit Knight(PlayerColor color);

    std::vector<std::vector<MoveVectorPtr>> getPossibleMoves() const;

    std::vector<MovePtr> getLegalMoves(const StatePtr state) override;

    std::vector<MovePtr> getAttackingMoves(StatePtr state) override;
};


#endif //CHESSPROJECT_KNIGHT_H
