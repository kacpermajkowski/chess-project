#ifndef CHESSPROJECT_UNIT_H
#define CHESSPROJECT_UNIT_H

#include <vector>
#include "typedefs.h"
#include "model/move/Move.h"
#include "model/move/MoveVector.h"

class Unit : public std::enable_shared_from_this<Unit>{
private:
    PlayerColor color;
public:
    explicit Unit(PlayerColor color);
    virtual ~Unit();

    PlayerColor getColor();

    virtual std::vector<MovePtr> getLegalMoves(const StatePtr &state);
    virtual std::vector<std::vector<MoveVectorPtr>> getPossibleMoves() = 0;
    virtual std::vector<MovePtr> getPossibleAttacks(StatePtr state) = 0;

private:
    std::vector<MovePtr> getLegalMovesNoCheck(const StatePtr& state);
    std::vector<MovePtr> getCheckBreakingMoves(StatePtr state);

protected:
    FieldPtr getCurrentField(StatePtr state);
};


#endif //CHESSPROJECT_UNIT_H
