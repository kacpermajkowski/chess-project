#ifndef CHESSPROJECT_FIELD_H
#define CHESSPROJECT_FIELD_H

#include "Position.h"
#include "UnitDir/Unit.h"

class Field : public std::enable_shared_from_this<Field>{

private:
    PositionPtr position;
    UnitPtr unit = nullptr;
public:
    explicit Field(PositionPtr position);

    Field(PositionPtr position, UnitPtr unit);
    virtual ~Field();

    PositionPtr getPosition();
    UnitPtr getUnit();

    bool isOccupied();
    bool isOccupiedByEnemy(PlayerColor color);
    bool isOccupiedByEnemy(const UnitPtr& allyUnit);
    bool isOccupiedByAlly(PlayerColor color);
    bool isOccupiedByAlly(const UnitPtr& allyUnit);

    void setUnit(UnitPtr newUnit);
};


#endif //CHESSPROJECT_FIELD_H
