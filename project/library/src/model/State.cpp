#include "model/State.h"
#include <typeinfo>
#include <stdexcept>
#include <iostream>
#include <utility>
#include <algorithm>
#include "model/UnitDir/Pawn.h"
#include "model/UnitDir/King.h"
#include "model/exceptions/GameAlreadyFinishedException.h"

State::State() {
    board = std::make_shared<Board>();
}
State::State(std::shared_ptr<Board> board){
    this->board = std::move(board);
}
State::~State() = default;

void State::moveUnitBetweenFields() {
    MovePtr move = getLastMove();
    move->getTargetField()->setUnit(move->getMovedUnit());
    move->getCurrentField()->setUnit(nullptr);
}

void State::captureUnitFromField(const FieldPtr& actionField) {
    takenPieces.push_back(actionField->getUnit());
    actionField->setUnit(nullptr);
}

void State::performAction() {
    MovePtr move = getLastMove();
    ActionPtr action = move->getAction();
    if(action == nullptr)
        return;

    if (action->getType() == CAPTURE)
        captureUnitFromField(action->getActionField());
    //TODO: Castling and promotion
}

void State::changeTurn() {
    turn = turn == WHITE ? BLACK : WHITE;
}

bool State::isFiftyMoveRuleDraw() {
    MovePtr move = getLastMove();

    bool fiftyMoveDraw = false;
    fiftyMoveRuleCounter++;

    if(areSameType(move->getMovedUnit(), std::make_shared<Pawn>(WHITE)))
        fiftyMoveRuleCounter = 0;
    if(move->getAction() != nullptr)
        if(move->getAction()->getType() == CAPTURE)
            fiftyMoveRuleCounter = 0;

    if(fiftyMoveRuleCounter >= 50){
        fiftyMoveDraw = true;
    }

    return fiftyMoveDraw;
}

void State::concludeIfApplicable() {
    if(isFiftyMoveRuleDraw()){
        conclude(FIFTY_MOVES_DRAW);
    } else if (isCheckmate()){
        if(getTurn() == WHITE)
            conclude(WHITE_WINS);
        else
            conclude(BLACK_WINS);
    } else if(isStalemate()){
        conclude(STALEMATE);
    } else if(isInsufficientMaterial()){
        conclude(INSUFFICIENT_MATERIAL_DRAW);
    } else if(isDrawByRepetition()){
        conclude(REPETITION_DRAW);
    }

    //TODO: Insufficient Material Conclusion
}

void State::makeAMove(const MovePtr& move) {
    //IMPORTANT: Execution order of sub-methods is critical to proper functioning
    //O) if game is concluded , like bro really? pls why are you even calling this method
    //1) push Move to history, as methods operate on a last move from history
    //2) move unit between fields, as if it's a pawn promotion, it'll be later overwritten by a new Unit
    //3) perform action
    //4) after all of that, we can check final state of the board, so now we check for conclusions
    //5) because determining whose turn it is, is important to checking conclusions, we do it after
    //6) essa?
    if(hasConcluded()){
        throw GameAlreadyFinishedException("Cannot register a move in a game that has concluded");
    }

    moveHistory.push_back(move);

    moveUnitBetweenFields();
    performAction();

    concludeIfApplicable();
    if(hasConcluded()) return;

    changeTurn();
}

bool State::isDrawByRepetition() {
    //TODO: Implement draw by repetition check
    return false;
}

bool State::isInsufficientMaterial() {
    //TODO: Implement insufficient material check
    return false;
}

bool State::isStalemate() {
    FieldPtr stalematedKingField = board->getKingField(getTurn() == WHITE ? BLACK : WHITE);
    if(stalematedKingField->getUnit()->getLegalMoves(shared_from_this()).empty()){
        if(!isAttacked(stalematedKingField, stalematedKingField->getUnit()->getColor())){
            return true;
        }
    }
    return false;
}

bool State::isCheckmate() {
    return isStalemate() && isAttacked(board->getKingField(getTurn() == WHITE ? WHITE : BLACK));
}

void State::conclude(Conclusion conclusion) {
    if(this->conclusion != IN_PROGRESS)
        throw GameAlreadyFinishedException("Cannot conclude a game that has already ended");
    this->conclusion = conclusion;
}

bool State::isAttacked(const FieldPtr& field, PlayerColor defender) {
    if(field == nullptr){
        throw std::invalid_argument("Field cannot be of value nullptr");
    }

    for(const FieldPtr& potentialAttacker : getBoard()->getFields()){
        if(potentialAttacker->getUnit() != nullptr) {
            if (potentialAttacker->getUnit()->getColor() != defender) {
                std::vector<MovePtr> potentialAttacks = potentialAttacker->getUnit()->getPossibleFutureAttacks(
                        shared_from_this());
                for (const MovePtr& potentialAttack: potentialAttacks) {
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

MovePtr State::getLastMove() {
    return moveHistory.back();
}

bool State::hasConcluded() const {
    return conclusion != IN_PROGRESS;
}

bool State::hasMoved(UnitPtr unit) {
    return std::any_of(moveHistory.begin(), moveHistory.end(),[&unit](MovePtr move){
        return move->getMovedUnit() == unit;
    });
}


