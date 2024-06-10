#ifndef CHESSPROJECT_UNIT_H
#define CHESSPROJECT_UNIT_H

#include <vector>
#include "enum.h"
#include "model/Move.h"

class Unit {
private:
    Color color;
public:
    explicit Unit(Color color);
    virtual ~Unit();

    virtual Color getColor() const;

    virtual std::vector<Move> getLegalMoves();
};


#endif //CHESSPROJECT_UNIT_H
