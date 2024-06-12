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
    std::vector<MovePtr> legalMoves;
    if(!state->isCheck()){
        FieldPtr field = state->getBoard()->getField((UnitPtr)this);
        PositionPtr curPos = field->getPosition();
        for(std::vector<MoveVectorPtr> branch : getPossibleMoves()){
            for(MoveVectorPtr mvp : branch){
                PositionPtr newPos = curPos->applyMoveVector(mvp);
                if(newPos != nullptr){
                    FieldPtr tryToMoveField = state->getBoard()->getField(newPos);
                    if(mvp->getColumnOffset() == 0){
                        if(!tryToMoveField->isOccupied()){
                            legalMoves.push_back(new Move((UnitPtr)this, newPos, curPos));
                        } else break;
                    } else {
                        if(tryToMoveField->isOccupied()){
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
    }

    return legalMoves;
}

std::vector<MovePtr> Pawn::getLegalAttackingMoves(StatePtr state) const {
    std::vector<MovePtr> legalMoves;
    if(!state->isCheck()){
        FieldPtr field = state->getBoard()->getField((UnitPtr)this);
        PositionPtr curPos = field->getPosition();
        for(std::vector<MoveVectorPtr> branch : getPossibleMoves()){
            for(MoveVectorPtr mvp : branch){
                if(mvp->getColumnOffset() != 0){
                    PositionPtr newPos = curPos->applyMoveVector(mvp);
                    if(newPos != nullptr){
                        FieldPtr tryToMoveField = state->getBoard()->getField(newPos);
                        if(tryToMoveField->isOccupied()){
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
    }

    return legalMoves;

}
