#ifndef CHESSPROJECT_QUEEN_H
#define CHESSPROJECT_QUEEN_H

#include "Unit.h"

class Queen : public Unit{
public:
    std::vector<Move> getLegalMoves() const override;
};


#endif //CHESSPROJECT_QUEEN_H
