#ifndef CHESSPROJECT_UNIT_H
#define CHESSPROJECT_UNIT_H

#include <vector>
#include "typedefs.h"
#include "model/move/Move.h"
#include "model/move/MoveVector.h"

class Unit {
private:
    PlayerColor color;
public:
    explicit Unit(PlayerColor color);
    virtual ~Unit();

    PlayerColor getColor() const;

    virtual std::vector<MovePtr> getLegalMoves(StatePtr state) const;
    virtual std::vector<std::vector<MoveVectorPtr>> getPossibleMoves() const = 0;
    virtual std::vector<MovePtr> getAttackingMoves(StatePtr state) const = 0;


};


#endif //CHESSPROJECT_UNIT_H
