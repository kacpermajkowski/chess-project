#ifndef CHESSPROJECT_BISHOP_H
#define CHESSPROJECT_BISHOP_H

#include "Unit.h"

class Bishop : public Unit{
public:

    explicit Bishop(PlayerColor color);

    std::vector<std::vector<MoveVectorPtr>> getBranchesOfPossibleMoveVectors();

    std::vector<MovePtr> getLegalMoves(const StatePtr &state) override;

};


#endif //CHESSPROJECT_BISHOP_H
