#ifndef CHESSPROJECT_BOARD_H
#define CHESSPROJECT_BOARD_H

#include <vector>
#include "Field.h"

class Board {
private:
    std::vector<FieldPtr> fields;

public:
    explicit Board();
    virtual ~Board();

    FieldPtr getField(PositionPtr position) const;
    FieldPtr getField(UnitPtr unit) const;
};


#endif //CHESSPROJECT_BOARD_H
