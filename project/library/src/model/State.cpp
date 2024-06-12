#include "model/State.h"

State::State(BoardPtr board) : board(board) {}
State::~State() {}

const std::vector<MovePtr> & State::getMoveHistory() const {
    return moveHistory;
}

unsigned int State::getMovesWithoutCapture() const {
    return movesWithoutCapture;
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
    moveHistory.push_back(move);
}

void State::conclude(Conclusion conclusion) {
    if(this->conclusion == IN_PROGRESS)
        this->conclusion = conclusion;
}

bool State::isAttacked(FieldPtr field) {
    //TODO: make
    return false;
}

