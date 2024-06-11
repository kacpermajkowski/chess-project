#ifndef CHESSPROJECT_FIELD_H
#define CHESSPROJECT_FIELD_H

#include "Position.h"
#include "UnitDir/Unit.h"

class Field {

private:
    PositionPtr position;
    UnitPtr unit;
public:
    Field(Position *position, Unit *unit);
    virtual ~Field();

    PositionPtr getPosition() const;
    UnitPtr getUnit() const;

    bool getPromotionField(PlayerColor color) const;

    bool isOccupied() const;

    void setUnit(UnitPtr unit);
};


#endif //CHESSPROJECT_FIELD_H
