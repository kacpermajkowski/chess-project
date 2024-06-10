#ifndef CHESSPROJECT_FIELD_H
#define CHESSPROJECT_FIELD_H

#include "Position.h"
#include "UnitDir/Unit.h"

class Field {

private:
    Position* position;
    Unit* unit;
    bool isPromotionField;

public:
    Field(Position *position, Unit *unit);
    virtual ~Field();

    Position *getPosition() const;

    Unit *getUnit() const;

    bool getPromotionField(Color color) const;

    bool isOccupied() const;

    void setUnit(Unit *unit);
};


#endif //CHESSPROJECT_FIELD_H
