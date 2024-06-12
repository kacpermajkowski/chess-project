#include "model/UnitDir/King.h"
#include "model/State.h"

std::vector<std::vector<MoveVectorPtr>> King::getPossibleMoves() const {
    std::vector<std::vector<MoveVectorPtr>> moves;
    for(int i = -1; i <=1; i++){
        for(int j = -1; j <=1; j++){
            if(!(i == 0 && j == 0)) {
                moves.push_back(std::vector<MoveVectorPtr> {new MoveVector(i, j)});
            }
        }
    }
    return moves;
}

std::vector<MovePtr> King::getLegalMoves(StatePtr state) const {
    std::vector<MovePtr> legalMoves;
    if(!state->isCheck()) {
        FieldPtr field = state->getBoard()->getField((UnitPtr) this);
        PositionPtr curPos = field->getPosition();
        for (std::vector<MoveVectorPtr> branch: getPossibleMoves()) {
            for (MoveVectorPtr mvp: branch) {
                PositionPtr newPos = curPos->applyMoveVector(mvp);
                if(newPos != nullptr){
                    FieldPtr tryToMoveField = state->getBoard()->getField(newPos);
                    if(state->isAttacked(tryToMoveField)) break;
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
}

std::vector<MovePtr> King::getLegalAttackingMoves(StatePtr state) const {
    std::vector<MovePtr> legalMoves;
    if(!state->isCheck()) {
        FieldPtr field = state->getBoard()->getField((UnitPtr) this);
        PositionPtr curPos = field->getPosition();
        for (std::vector<MoveVectorPtr> branch: getPossibleMoves()) {
            for (MoveVectorPtr mvp: branch) {
                PositionPtr newPos = curPos->applyMoveVector(mvp);
                if (newPos != nullptr) {
                    FieldPtr tryToMoveField = state->getBoard()->getField(newPos);
                    if(tryToMoveField->getUnit() != nullptr && tryToMoveField->getUnit()->getColor() == this->getColor())
                        break;
                    else legalMoves.push_back(new Move((UnitPtr)this, newPos, curPos));
                }
            }
        }
    }
    return legalMoves;
}
