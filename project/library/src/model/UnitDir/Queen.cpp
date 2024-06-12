#include "model/UnitDir/Queen.h"
#include "model/State.h"

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
        topRight.push_back(new MoveVector(i, i));
        topLeft.push_back(new MoveVector(i, (0-i)));
        bottomRight.push_back(new MoveVector((0-i), i));
        bottomLeft.push_back(new MoveVector((0-i), (0-i)));
        up.push_back(new MoveVector(i, 0));
        right.push_back(new MoveVector(0, i));
        down.push_back(new MoveVector((0-i), 0));
        left.push_back(new MoveVector(0, (0-i)));
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

std::vector<MovePtr> Queen::getLegalMoves(StatePtr state) const {
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

std::vector<MovePtr> Queen::getLegalAttackingMoves(StatePtr state) const {
    return getLegalMoves(state);
}
