#include "model/UnitDir/Bishop.h"
#include "model/State.h"

Bishop::Bishop(PlayerColor color) : Unit(color) {}

std::vector<std::vector<MoveVectorPtr>> Bishop::getBranchesOfPossibleMoveVectors() {
    std::vector<std::vector<MoveVectorPtr>> moves;

    std::vector<MoveVectorPtr> topRight;
    std::vector<MoveVectorPtr> topLeft;
    std::vector<MoveVectorPtr> bottomRight;
    std::vector<MoveVectorPtr> bottomLeft;

    for(int i = 1; i <=7; i++) {
        topRight.push_back(std::make_shared<MoveVector>(i, i));
        topLeft.push_back(std::make_shared<MoveVector>(i, (0-i)));
        bottomRight.push_back(std::make_shared<MoveVector>((0-i), i));
        bottomLeft.push_back(std::make_shared<MoveVector>((0-i), (0-i)));
    }

    moves.push_back(topRight);
    moves.push_back(topLeft);
    moves.push_back(bottomRight);
    moves.push_back(bottomLeft);

    return moves;
}

std::vector<MovePtr> Bishop::getLegalMoves(const StatePtr &state) {
    return Unit::getLegalMoves(state);
}

