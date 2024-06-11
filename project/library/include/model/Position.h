#ifndef CHESSPROJECT_POSITION_H
#define CHESSPROJECT_POSITION_H

#include "typedefs.h"

class Position {
private:
    LetterIndex letterIndex;
    NumberIndex numberIndex;
public:
    Position(LetterIndex letterIndex, NumberIndex numberIndex);
    virtual ~Position();

    LetterIndex getLetterIndex() const;
    NumberIndex getNumberIndex() const;
};




#endif //CHESSPROJECT_POSITION_H
