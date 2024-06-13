#include "model/State.h"
#include <typeinfo>
#include <stdexcept>
#include <iostream>
#include "model/UnitDir/Pawn.h"
#include "model/UnitDir/King.h"

State::State() {
    board = std::make_shared<Board>();
}
State::State(std::shared_ptr<Board> board){
    this->board = board;
}
State::~State() {}

const std::vector<MovePtr> & State::getMoveHistory() const {
    return moveHistory;
}

unsigned int State::getFiftyMovesRuleCounter() const {
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
        if(typeid(*(move->getMovedUnit())) == typeid(Pawn))
            fiftyMoveRuleCounter = 0;
        ActionPtr action = move->getAction();
        if(action != nullptr) {
            if (action->getType() == CAPTURE) {
                fiftyMoveRuleCounter = 0;

                std::shared_ptr<Field> actionField = action->getActionField();
                takenPieces.push_back(actionField->getUnit());
                actionField->setUnit(nullptr);
            }
            //TODO: Castling
        }
        move->getTargetField()->setUnit(move->getMovedUnit());
        move->getCurrentField()->setUnit(nullptr);
//        //TODO: Checkmate and conclusion

        turn = turn == WHITE ? BLACK : WHITE;
        moveHistory.push_back(move);
        if(fiftyMoveRuleCounter >= 50)
            conclude(FIFTY_MOVES_DRAW);
    } else throw std::invalid_argument("Cannot register a move in a game that has concluded");
}

void State::conclude(Conclusion conclusion) {
    if(this->conclusion == IN_PROGRESS)
        this->conclusion = conclusion;
}

bool State::isAttacked(FieldPtr field, PlayerColor defender) {
    for(FieldPtr potentialAttacker : getBoard()->getFields()){
        if(potentialAttacker->getUnit() != nullptr) {
            if (potentialAttacker->getUnit()->getColor() != defender) {
                std::vector<MovePtr> potentialAttacks = potentialAttacker->getUnit()->getPossibleFutureAttacks(
                        shared_from_this());
                for (MovePtr potentialAttack: potentialAttacks) {
                    if (potentialAttack->getTargetField() == field)
                        return true;
                }
            }
        }
    }
    return false;
}

std::vector<MovePtr> State::getLegalMoves() {
    return getLegalMoves(getTurn());
}

std::vector<MovePtr> State::getLegalMoves(PlayerColor color) {
    std::vector<MovePtr> allLegalMoves;
    for(FieldPtr field : getBoard()->getFields()){
       if(field->isOccupiedByAlly(color)){
           std::vector<MovePtr> figureLegalMoves = field->getUnit()->getLegalMoves(shared_from_this());
           allLegalMoves.insert(std::end(allLegalMoves), std::begin(figureLegalMoves), std::end(figureLegalMoves));
       }
    }
    return allLegalMoves;
}

bool State::isCheck() {
    for(const FieldPtr& field : board->getFields()){
        UnitPtr unit = field->getUnit();
        if(typeid(unit) == typeid(King)){
            if(unit->getColor() == turn){
                return isAttacked(field, turn);
            }
        }
    }
    return false;
}

bool State::hasConcluded() const {
    return conclusion != IN_PROGRESS;
}

MovePtr State::getLastMove() {
    return moveHistory.back();
}

bool State::hasMoved(UnitPtr unit) {
    for(MovePtr move : moveHistory){
        if(move->getMovedUnit() == unit)
            return true;
    }
    return false;
}

