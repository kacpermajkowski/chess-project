#include "model/UnitDir/Rook.h"
#include "model/State.h"

Rook::Rook(PlayerColor color) : Unit(color) {}

std::vector<std::vector<MoveVectorPtr>> Rook::getPossibleMoves() const {
    std::vector<std::vector<MoveVectorPtr>> moves;

    std::vector<MoveVectorPtr> down;
    std::vector<MoveVectorPtr> left;
    std::vector<MoveVectorPtr> up;
    std::vector<MoveVectorPtr> right;

    for(int i = 1; i <=7; i++) {
        up.push_back(std::make_shared<MoveVector>(i, 0));
        right.push_back(std::make_shared<MoveVector>(0, i));
        down.push_back(std::make_shared<MoveVector>((0-i), 0));
        left.push_back(std::make_shared<MoveVector>(0, (0-i)));
    }

    moves.push_back(up);
    moves.push_back(left);
    moves.push_back(right);
    moves.push_back(down);

    return moves;
}

std::vector<MovePtr> Rook::getLegalMoves(const StatePtr state) {
    //TODO: Add castling
    return Unit::getLegalMoves(state);
}

std::vector<MovePtr> Rook::getAttackingMoves(StatePtr state) {
    return getLegalMoves(state);
}
