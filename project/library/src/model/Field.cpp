#include "model/Field.h"

Field::Field(const PositionPtr &position, const UnitPtr &unit) : position(position), unit(unit) {}
Field::~Field() {}

PositionPtr Field::getPosition() {
    return position;
}

UnitPtr Field::getUnit() {
    return unit;
}

void Field::setUnit(UnitPtr unit) {
    Field::unit = unit;
}

bool Field::isOccupiedByEnemy(PlayerColor color) {
    if(getUnit() != nullptr){
        return getUnit()->getColor() != color;
    } else return false;
}

bool Field::isOccupiedByEnemy(UnitPtr unit) {
    return isOccupiedByEnemy(unit->getColor());
}

bool Field::isOccupiedByAlly(PlayerColor color) {
    return getUnit()->getColor() == color;
}

bool Field::isOccupiedByAlly(UnitPtr unit) {
    return isOccupiedByAlly(unit->getColor());
}

bool Field::isOccupied() {
    return getUnit() != nullptr;
}



