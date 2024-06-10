#ifndef CHESSPROJECT_BOARD_H
#define CHESSPROJECT_BOARD_H

#include <vector>
#include "Field.h"

class Board {
private:
    std::vector<Field*> fields;

public:
    explicit Board(const std::vector<Field> &fields);
    virtual ~Board();

    Field* getField(Position position) const;
};


#endif //CHESSPROJECT_BOARD_H
