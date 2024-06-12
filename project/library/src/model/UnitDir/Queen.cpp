#include "model/UnitDir/Queen.h"
#include "model/State.h"

Queen::Queen(PlayerColor color) : Unit(color) {}

std::vector<std::vector<MoveVectorPtr>> Queen::getPossibleMoves() const {
    std::vector<std::vector<MoveVectorPtr>> moves;

    std::vector<MoveVectorPtr> topRight;
    std::vector<MoveVectorPtr> topLeft;
    std::vector<MoveVectorPtr> bottomRight;
    std::vector<MoveVectorPtr> bottomLeft;
    std::vector<MoveVectorPtr> down;
    std::vector<MoveVectorPtr> left;
    std::vector<MoveVectorPtr> up;
    std::vector<MoveVectorPtr> right;

    for(int i = 1; i <=7; i++) {
        topRight.push_back(std::make_shared<MoveVector>(i, i));
        topLeft.push_back(std::make_shared<MoveVector>(i, (0-i)));
        bottomRight.push_back(std::make_shared<MoveVector>((0-i), i));
        bottomLeft.push_back(std::make_shared<MoveVector>((0-i), (0-i)));
        up.push_back(std::make_shared<MoveVector>(i, 0));
        right.push_back(std::make_shared<MoveVector>(0, i));
        down.push_back(std::make_shared<MoveVector>((0-i), 0));
        left.push_back(std::make_shared<MoveVector>(0, (0-i)));
    }

    moves.push_back(topRight);
    moves.push_back(topLeft);
    moves.push_back(bottomRight);
    moves.push_back(bottomLeft);
    moves.push_back(up);
    moves.push_back(left);
    moves.push_back(right);
    moves.push_back(down);

    return moves;
}

std::vector<MovePtr> Queen::getLegalMoves(const StatePtr state) {
    return Unit::getLegalMoves(state);

}

std::vector<MovePtr> Queen::getAttackingMoves(StatePtr state) {
    return getLegalMoves(state);
}
