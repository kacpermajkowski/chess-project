#ifndef CHESSPROJECT_BISHOP_H
#define CHESSPROJECT_BISHOP_H

#include "Unit.h"

class Bishop : public Unit{
public:

    explicit Bishop(PlayerColor color);

    std::vector<std::vector<MoveVectorPtr>> getPossibleMoves();

    std::vector<MovePtr> getLegalMoves(StatePtr state) override;

    std::vector<MovePtr> getPossibleAttacks(StatePtr state) override;
};


#endif //CHESSPROJECT_BISHOP_H
