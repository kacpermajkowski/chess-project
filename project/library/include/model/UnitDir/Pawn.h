#ifndef CHESSPROJECT_PAWN_H
#define CHESSPROJECT_PAWN_H

#include "Unit.h"

class Pawn : public Unit{
public:
    std::vector<Move> getLegalMoves() override;
};


#endif //CHESSPROJECT_PAWN_H
