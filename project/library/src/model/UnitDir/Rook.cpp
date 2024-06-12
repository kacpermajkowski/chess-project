#include "model/UnitDir/Rook.h"
#include "model/State.h"

std::vector<std::vector<MoveVectorPtr>> Rook::getPossibleMoves() const {
    std::vector<std::vector<MoveVectorPtr>> moves;

    std::vector<MoveVectorPtr> down;
    std::vector<MoveVectorPtr> left;
    std::vector<MoveVectorPtr> up;
    std::vector<MoveVectorPtr> right;

    for(int i = 1; i <=7; i++) {
        up.push_back(new MoveVector(i, 0));
        right.push_back(new MoveVector(0, i));
        down.push_back(new MoveVector((0-i), 0));
        left.push_back(new MoveVector(0, (0-i)));
    }

    moves.push_back(up);
    moves.push_back(left);
    moves.push_back(right);
    moves.push_back(down);

    return moves;
}

std::vector<MovePtr> Rook::getLegalMoves(StatePtr state) const {
    //TODO: Add castling
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
}

std::vector<MovePtr> Rook::getLegalAttackingMoves(StatePtr state) const {
    return getLegalMoves(state);
}
