#include "model/UnitDir/Knight.h"
#include "model/State.h"

Knight::Knight(PlayerColor color) : Unit(color) {}

std::vector<std::vector<MoveVectorPtr>> Knight::getPossibleMoves() {
    return std::vector<std::vector<MoveVectorPtr>>{
            std::vector<MoveVectorPtr> {std::make_shared<MoveVector>(2, 1)},
            std::vector<MoveVectorPtr> {std::make_shared<MoveVector>(1, 2)},
            std::vector<MoveVectorPtr> {std::make_shared<MoveVector>(-1, 2)},
            std::vector<MoveVectorPtr> {std::make_shared<MoveVector>(-2, 1)},
            std::vector<MoveVectorPtr> {std::make_shared<MoveVector>(-2, -1)},
            std::vector<MoveVectorPtr> {std::make_shared<MoveVector>(-1, -2)},
            std::vector<MoveVectorPtr> {std::make_shared<MoveVector>(1, -2)},
            std::vector<MoveVectorPtr> {std::make_shared<MoveVector>(2, -1)}
    };
}

std::vector<MovePtr> Knight::getLegalMoves(StatePtr state) {
    return Unit::getLegalMoves(state);
}

std::vector<MovePtr> Knight::getPossibleFutureAttacks(StatePtr state) {
    return getLegalMoves(state);
}
