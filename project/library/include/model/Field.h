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

    Field(const PositionPtr &position, const UnitPtr &unit);
    virtual ~Field();

    PositionPtr getPosition();
    UnitPtr getUnit();

    bool isOccupied();
    bool isOccupiedByEnemy(PlayerColor color);
    bool isOccupiedByEnemy(UnitPtr unit);
    bool isOccupiedByAlly(PlayerColor color);
    bool isOccupiedByAlly(UnitPtr unit);

    void setUnit(UnitPtr unit);
};


#endif //CHESSPROJECT_FIELD_H
