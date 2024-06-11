#ifndef CHESSPROJECT_ROOK_H
#define CHESSPROJECT_ROOK_H

#include "Unit.h"

class Rook : public Unit{
public:
    std::vector<Move> getLegalMoves() const override;

};


#endif //CHESSPROJECT_ROOK_H
