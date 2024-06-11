#ifndef CHESSPROJECT_UNIT_H
#define CHESSPROJECT_UNIT_H

#include <vector>
#include "typedefs.h"
#include "model/Move.h"

class Unit {
private:
    PlayerColor color;
public:
    explicit Unit(PlayerColor color);
    virtual ~Unit();

    PlayerColor getColor() const;

    virtual std::vector<Move> getLegalMoves() const = 0;
};


#endif //CHESSPROJECT_UNIT_H
