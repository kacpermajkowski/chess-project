#include "model/Position.h"

Position::Position(LetterIndex letterIndex, NumberIndex numberIndex) : letterIndex(letterIndex),
                                                                       numberIndex(numberIndex) {}

Position::~Position() {

}

LetterIndex Position::getLetterIndex() const {
    return letterIndex;
}

NumberIndex Position::getNumberIndex() const {
    return numberIndex;
}

Position *Position::applyMoveVector(MoveVectorPtr vector) const {
    int newColumn = letterIndex + vector->getColumnOffset();
    int newRow = numberIndex + vector->getRowOffset();
    if(newColumn >= 0 && newColumn <= 7){
        if(newRow >= 0 && newRow <=7){
            return new Position(LetterIndex(newColumn), NumberIndex(newRow));
        }
    }
    return nullptr;
}

