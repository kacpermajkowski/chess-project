#ifndef CHESSPROJECT_KNIGHT_H
#define CHESSPROJECT_KNIGHT_H

#include "Unit.h"

class Knight : public Unit{
public:
    std::vector<Move> getLegalMoves() const override;
};


#endif //CHESSPROJECT_KNIGHT_H
