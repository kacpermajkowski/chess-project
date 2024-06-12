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

    virtual std::vector<MovePtr> getLegalMoves(const StatePtr state) const;
    virtual std::vector<std::vector<MoveVectorPtr>> getPossibleMoves() const = 0;
    virtual std::vector<MovePtr> getAttackingMoves(const StatePtr state) const = 0;

private:
    std::vector<MovePtr> getLegalMovesNoCheck(const StatePtr state) const;
    std::vector<MovePtr> getCheckBreakingMoves(const StatePtr state) const;

    FieldPtr getCurrentField(const StatePtr state) const;
};


#endif //CHESSPROJECT_UNIT_H
