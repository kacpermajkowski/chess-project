#include "model/Board.h"

Board::Board(const std::vector<Field> &fields) : fields(fields) {};
Board::~Board() {}

Field *Board::getField(Position position) const {
    return nullptr;
}


