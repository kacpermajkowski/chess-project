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
