#ifndef CHESSPROJECT_ROOK_H
#define CHESSPROJECT_ROOK_H

#include "Unit.h"

class Rook : public Unit{
public:

    explicit Rook(PlayerColor color);

    std::vector<std::vector<MoveVectorPtr>> getPossibleMoves() override;

    std::vector<MovePtr> getLegalMoves(const StatePtr &state) override;

};


#endif //CHESSPROJECT_ROOK_H
