#ifndef CHESSPROJECT_BISHOP_H
#define CHESSPROJECT_BISHOP_H

#include "Unit.h"

class Bishop : public Unit{
public:

    explicit Bishop(PlayerColor color) override;

    std::vector<std::vector<MoveVectorPtr>> getPossibleMoves() const;

    std::vector<MovePtr> getLegalMoves(const StatePtr state) override;

    std::vector<MovePtr> getAttackingMoves(StatePtr state) override;
};


#endif //CHESSPROJECT_BISHOP_H
