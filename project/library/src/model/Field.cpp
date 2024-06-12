#include "model/Field.h"


Field::Field(Position *position, Unit *unit) : position(position), unit(unit) {}
Field::~Field() {}

Position *Field::getPosition() const {
    return position;
}

Unit *Field::getUnit() const {
    return unit;
}

void Field::setUnit(Unit *unit) {
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

