#ifndef CHESSPROJECT_FIELD_H
#define CHESSPROJECT_FIELD_H

#include "Position.h"
#include "UnitDir/Unit.h"

class Field : public std::enable_shared_from_this<Field>{

private:
    PositionPtr position;
    UnitPtr unit;
public:

    Field(const PositionPtr &position, const UnitPtr &unit);
    virtual ~Field();


    PositionPtr getPosition() const;
    UnitPtr getUnit() const;

    bool getPromotionField(PlayerColor color) const;

    bool isOccupied() const;
    bool isOccupiedByEnemy(PlayerColor color) const;
    bool isOccupiedByEnemy(UnitPtr unit) const;
    bool isOccupiedByAlly(PlayerColor color) const;
    bool isOccupiedByAlly(UnitPtr unit) const;


    void setUnit(UnitPtr unit);
};


#endif //CHESSPROJECT_FIELD_H
