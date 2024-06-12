#include "model/UnitDir/Pawn.h"
#include "model/State.h"

std::vector<std::vector<MoveVectorPtr>> Pawn::getPossibleMoves() const {
    std::vector<std::vector<MoveVectorPtr>> moves;
    if(getColor() == WHITE){
        moves.push_back(std::vector<MoveVectorPtr> {
            new MoveVector(1,0),
            new MoveVector(2,0)
        });
        moves.push_back(std::vector<MoveVectorPtr> {new MoveVector(1,-1)});
        moves.push_back(std::vector<MoveVectorPtr> {new MoveVector(1,1)});
    } else if(getColor() == BLACK){
        moves.push_back(std::vector<MoveVectorPtr> {
            new MoveVector(-1,0),
            new MoveVector(-2,0)
        });
        moves.push_back(std::vector<MoveVectorPtr> {new MoveVector(-1,-1)});
        moves.push_back(std::vector<MoveVectorPtr> {new MoveVector(-1,1)});
    }
    return moves;
}

std::vector<MovePtr> Pawn::getLegalMoves(StatePtr state) const {
    std::vector<MovePtr> preLegalMoves = Unit::getLegalMoves(state);
    std::vector<MovePtr> legalMoves;
    for(MovePtr move : preLegalMoves)
    {
        if(move->getTargetPosition()->getPosition()->getLetterIndex() != move->getStartingPosition()->getPosition()->getLetterIndex()){
            if(move->getTargetPosition()->isOccupied()){
                if(move->getTargetPosition()->getUnit()->getColor() != getColor()){
                    legalMoves.push_back(move);
                }
            }
        } else {
            if(!move->getTargetPosition()->isOccupied()){
                legalMoves.push_back(move);
            }
        }
    }

    return legalMoves;
}

std::vector<MovePtr> Pawn::getAttackingMoves(StatePtr state) const {
    std::vector<MovePtr> preLegalMoves = Pawn::getLegalMoves(state);
    std::vector<MovePtr> legalMoves;
    for(MovePtr move : preLegalMoves) {
        if(move->getTargetPosition()->getPosition()->getLetterIndex() != move->getStartingPosition()->getPosition()->getLetterIndex()){
            legalMoves.push_back(move);
        }
    }
    return legalMoves;
}
