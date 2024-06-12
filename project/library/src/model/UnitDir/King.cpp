#include "model/UnitDir/King.h"
#include "model/State.h"

King::King(PlayerColor color) : Unit(color) {}

std::vector<std::vector<MoveVectorPtr>> King::getPossibleMoves() const {
    std::vector<std::vector<MoveVectorPtr>> moves;
    for(int i = -1; i <=1; i++){
        for(int j = -1; j <=1; j++){
            if(!(i == 0 && j == 0)) {
                moves.push_back(std::vector<MoveVectorPtr> {std::make_shared<MoveVector>(i, j)});
            }
        }
    }
    return moves;
}

std::vector<MovePtr> King::getLegalMoves(const StatePtr state) {
    std::vector<MovePtr> preLegalMoves = Unit::getLegalMoves(state);
    std::vector<MovePtr> legalMoves;

    for(MovePtr move : preLegalMoves){
        if(!state->isAttacked(move->getTargetField()))
            legalMoves.push_back(move);
    }

    return legalMoves;
}

std::vector<MovePtr> King::getAttackingMoves(StatePtr state) {
    return King::getLegalMoves(state);
}
