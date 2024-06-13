#include "model/UnitDir/Pawn.h"
#include "model/State.h"

std::vector<std::vector<MoveVectorPtr>> Pawn::getPossibleMoves() {
    std::vector<std::vector<MoveVectorPtr>> moves;
    if(getColor() == WHITE){
        moves.push_back(std::vector<MoveVectorPtr> {
                std::make_shared<MoveVector>(1,0),
                std::make_shared<MoveVector>(2,0)
        });
        moves.push_back(std::vector<MoveVectorPtr> {std::make_shared<MoveVector>(1,-1)});
        moves.push_back(std::vector<MoveVectorPtr> {std::make_shared<MoveVector>(1,1)});
    } else if(getColor() == BLACK){
        moves.push_back(std::vector<MoveVectorPtr> {
                std::make_shared<MoveVector>(-1,0),
                std::make_shared<MoveVector>(-2,0)
        });
        moves.push_back(std::vector<MoveVectorPtr> {std::make_shared<MoveVector>(-1,-1)});
        moves.push_back(std::vector<MoveVectorPtr> {std::make_shared<MoveVector>(-1,1)});
    }
    return moves;
}

std::vector<MovePtr> Pawn::getLegalMoves(StatePtr state) {
    std::vector<MovePtr> preLegalMoves = Unit::getLegalMoves(state);
    std::vector<MovePtr> legalMoves;
    for(MovePtr move : preLegalMoves)
    {
        if(move->getTargetField()->getPosition()->getLetterIndex() != move->getCurrentField()->getPosition()->getLetterIndex()){
            if(move->getTargetField()->isOccupied()){
                if(move->getTargetField()->getUnit()->getColor() != getColor()){
                    legalMoves.push_back(move);
                }
            }
        } else {
            if(!move->getTargetField()->isOccupied()){
                legalMoves.push_back(move);
            }
        }
    }

    return legalMoves;
}

std::vector<MovePtr> Pawn::getAttackingMoves(StatePtr state) {
    std::vector<MovePtr> preLegalMoves = Pawn::getLegalMoves(state);
    std::vector<MovePtr> legalMoves;
    for(MovePtr move : preLegalMoves) {
        if(move->getTargetField()->getPosition()->getLetterIndex() != move->getCurrentField()->getPosition()->getLetterIndex()){
            legalMoves.push_back(move);
        }
    }
    return legalMoves;
}

Pawn::Pawn(PlayerColor color) : Unit(color) {
    promotionRow = color == WHITE ? _8 : _1;
}
