#ifndef CHESSPROJECT_BOARD_H
#define CHESSPROJECT_BOARD_H

#include <vector>
#include "Field.h"

class Board {
private:
    Field fields[8][8];

public:
    explicit Board();
    virtual ~Board();

    FieldPtr getField(Position position) const;
};


#endif //CHESSPROJECT_BOARD_H
