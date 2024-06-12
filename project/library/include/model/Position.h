#ifndef CHESSPROJECT_POSITION_H
#define CHESSPROJECT_POSITION_H

#include "typedefs.h"
#include "model/move/MoveVector.h"

class Position : public std::enable_shared_from_this<Position>{
private:
    LetterIndex letterIndex;
    NumberIndex numberIndex;
public:
    Position(LetterIndex letterIndex, NumberIndex numberIndex);
    virtual ~Position();

    PositionPtr applyMoveVector(MoveVectorPtr vector) const;

    LetterIndex getLetterIndex() const;
    NumberIndex getNumberIndex() const;
};




#endif //CHESSPROJECT_POSITION_H
