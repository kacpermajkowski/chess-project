#include "model/UnitDir/Bishop.h"
#include "model/State.h"

std::vector<std::vector<MoveVectorPtr>> Bishop::getPossibleMoves() const {
    std::vector<std::vector<MoveVectorPtr>> moves;

    std::vector<MoveVectorPtr> topRight;
    std::vector<MoveVectorPtr> topLeft;
    std::vector<MoveVectorPtr> bottomRight;
    std::vector<MoveVectorPtr> bottomLeft;

    for(int i = 1; i <=7; i++) {
        topRight.push_back(new MoveVector(i, i));
        topLeft.push_back(new MoveVector(i, (0-i)));
        bottomRight.push_back(new MoveVector((0-i), i));
        bottomLeft.push_back(new MoveVector((0-i), (0-i)));
    }

    moves.push_back(topRight);
    moves.push_back(topLeft);
    moves.push_back(bottomRight);
    moves.push_back(bottomLeft);

    return moves;
}

std::vector<MovePtr> Bishop::getLegalMoves(StatePtr state) const {
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

std::vector<MovePtr> Bishop::getLegalAttackingMoves(StatePtr state) const {
    return getLegalMoves(state);
}
