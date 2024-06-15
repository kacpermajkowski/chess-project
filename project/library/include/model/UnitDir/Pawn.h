#ifndef CHESSPROJECT_PAWN_H
#define CHESSPROJECT_PAWN_H

#include "Unit.h"

class Pawn : public Unit{
private:
    NumberIndex promotionRow = _8;
public:
    explicit Pawn(PlayerColor color);

    std::vector<std::vector<MoveVectorPtr>> getPossibleMoves() override;

    std::vector<MovePtr> getLegalMoves(const StatePtr &state) override;

    std::vector<MovePtr> getPossibleAttacks(StatePtr state) override;
};


#endif //CHESSPROJECT_PAWN_H
