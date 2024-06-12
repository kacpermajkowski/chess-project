#include "model/Field.h"

Field::Field(const PositionPtr &position, const UnitPtr &unit) : position(position), unit(unit) {}
Field::~Field() {}

PositionPtr Field::getPosition() const {
    return position;
}

UnitPtr Field::getUnit() const {
    return unit;
}

void Field::setUnit(UnitPtr unit) {
    Field::unit = unit;
}

bool Field::isOccupiedByEnemy(PlayerColor color) const {
    return getUnit()->getColor() != color;
}

bool Field::isOccupiedByEnemy(UnitPtr unit) const {
    return isOccupiedByEnemy(unit->getColor());
}

bool Field::isOccupiedByAlly(PlayerColor color) const {
    return getUnit()->getColor() == color;
}

bool Field::isOccupiedByAlly(UnitPtr unit) const {
    return isOccupiedByAlly(unit->getColor());
}

bool Field::isOccupied() const {
    return false;
}



