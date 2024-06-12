#include "model/UnitDir/Knight.h"
#include "model/State.h"

Knight::Knight(PlayerColor color) : Unit(color) {}

std::vector<std::vector<MoveVectorPtr>> Knight::getPossibleMoves() const {
    return std::vector<std::vector<MoveVectorPtr>>{
            std::vector<MoveVectorPtr> {new MoveVector(2, 1)},
            std::vector<MoveVectorPtr> {new MoveVector(1, 2)},
            std::vector<MoveVectorPtr> {new MoveVector(-1, 2)},
            std::vector<MoveVectorPtr> {new MoveVector(-2, 1)},
            std::vector<MoveVectorPtr> {new MoveVector(-2, -1)},
            std::vector<MoveVectorPtr> {new MoveVector(-1, -2)},
            std::vector<MoveVectorPtr> {new MoveVector(1, -2)},
            std::vector<MoveVectorPtr> {new MoveVector(2, -1)}
    };
}

std::vector<MovePtr> Knight::getLegalMoves(StatePtr state) const {
    return Unit::getLegalMoves(state);
}

std::vector<MovePtr> Knight::getAttackingMoves(StatePtr state) const {
    return getLegalMoves(state);
}
