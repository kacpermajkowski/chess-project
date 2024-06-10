#ifndef CHESSPROJECT_BISHOP_H
#define CHESSPROJECT_BISHOP_H

#include "Unit.h"

class Bishop : public Unit{
public:
    std::vector<Move> getLegalMoves() override;
};


#endif //CHESSPROJECT_BISHOP_H
