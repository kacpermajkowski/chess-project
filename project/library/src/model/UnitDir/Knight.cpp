#include "model/UnitDir/Knight.h"
#include "model/State.h"

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
    std::vector<MovePtr> legalMoves;
    if(!state->isCheck()){
        FieldPtr field = state->getBoard()->getField((UnitPtr)this);
        PositionPtr curPos = field->getPosition();
        for(std::vector<MoveVectorPtr> branch : getPossibleMoves()){
            for(MoveVectorPtr mvp : branch){
                PositionPtr newPos = curPos->applyMoveVector(mvp);
                if(newPos != nullptr){
                    FieldPtr tryToMoveField = state->getBoard()->getField(newPos);
                    if(!tryToMoveField->isOccupied()){
                        legalMoves.push_back(new Move((UnitPtr)this, newPos, curPos));
                    } else {
                        if(tryToMoveField->getUnit()->getColor() != this->getColor()){
                            MovePtr move = new Move((UnitPtr)this, newPos, curPos);
                            move->setTakenUnit(tryToMoveField->getUnit());
                            move->setType(REGULAR_TAKE);
                            legalMoves.push_back(move);
                        }
                        break;
                    }
                }
            }
        }
    }

    return legalMoves;

    return legalMoves;
}

std::vector<MovePtr> Knight::getLegalAttackingMoves(StatePtr state) const {
    return getLegalMoves(state);
}
