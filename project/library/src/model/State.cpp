#include "model/State.h"
#include <typeinfo>
#include "model/UnitDir/Pawn.h"

State::State() {
    board = new Board();
}
State::~State() {}

const std::vector<MovePtr> & State::getMoveHistory() const {
    return moveHistory;
}

unsigned int State::getMovesWithoutCapture() const {
    return fiftyMoveRuleCounter;
}

Conclusion State::getConclusion() const {
    return conclusion;
}

PlayerColor State::getTurn() const {
    return turn;
}

const std::vector<UnitPtr> & State::getTakenPieces() const {
    return takenPieces;
}

BoardPtr State::getBoard() const {
    return board;
}

void State::registerMove(MovePtr move) {
    if(hasConcluded() == false){
        fiftyMoveRuleCounter++;
        if(typeid(move->getMovedUnit()) == typeid(Pawn))
            fiftyMoveRuleCounter = 0;

        ActionPtr action = move->getAction();
        if(action != nullptr){
            if(action->getType() == CAPTURE){
                FieldPtr actionField = action->getActionField();
                takenPieces.push_back(actionField->getUnit());
                actionField->setUnit(nullptr);
                fiftyMoveRuleCounter = 0;
            }
            //TODO: Castling
        }
        move->getTargetField()->setUnit(move->getMovedUnit());
        move->getCurrentField()->setUnit(nullptr);
        //TODO: Checkmate and conclusion

        turn = turn == WHITE ? BLACK : WHITE;
        moveHistory.push_back(move);
        if(fiftyMoveRuleCounter >= 50)
            conclude(FIFTY_MOVES_DRAW);
    } //TODO: else throw custom exception
}

void State::conclude(Conclusion conclusion) {
    if(this->conclusion == IN_PROGRESS)
        this->conclusion = conclusion;
}

bool State::isAttacked(FieldPtr field) {
    for(FieldPtr potentialAttacker : getBoard()->getFields()){
        std::vector<MovePtr> potentialAttacks = potentialAttacker->getUnit()->getLegalMoves(this);
        for(MovePtr potentialAttack : potentialAttacks){
            if(potentialAttack->getTargetField() == field)
                return true;
        }
    }
    return false;
}

std::vector<MovePtr> State::getLegalMoves() const {
    return getLegalMoves(getTurn());
}

std::vector<MovePtr> State::getLegalMoves(PlayerColor color) const {
    std::vector<MovePtr> allLegalMoves;
    for(FieldPtr field : getBoard()->getFields()){
       if(field->isOccupiedByAlly(color)){
           std::vector<MovePtr> figureLegalMoves = field->getUnit()->getLegalMoves((StatePtr)this);
           allLegalMoves.insert(std::end(allLegalMoves), std::begin(figureLegalMoves), std::end(figureLegalMoves));
       }
    }
    return allLegalMoves;
}

bool State::isCheck() const {
    //TODO: Is there a check in game
    return false;
}

bool State::hasConcluded() const {
    return conclusion != IN_PROGRESS;
}

