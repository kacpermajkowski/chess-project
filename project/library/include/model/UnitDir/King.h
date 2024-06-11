#ifndef CHESSPROJECT_KING_H
#define CHESSPROJECT_KING_H

#include "Unit.h"

class King : public Unit{
public:
    std::vector<Move> getLegalMoves() const override;
};


#endif //CHESSPROJECT_KING_H
