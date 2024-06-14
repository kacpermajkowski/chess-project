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
    if(isOccupied()){
        return getUnit()->getColor() != color;
    }
    return false;
}

bool Field::isOccupiedByEnemy(UnitPtr unit) {
    return isOccupiedByEnemy(unit->getColor());
}

bool Field::isOccupiedByAlly(PlayerColor color) {
    if(isOccupied()){
        return getUnit()->getColor() == color;
    }
    return false;
}

bool Field::isOccupiedByAlly(UnitPtr unit) {
    return isOccupiedByAlly(unit->getColor());
}

bool Field::isOccupied() {
    return getUnit() != nullptr;
}

Field::Field(PositionPtr position) : position(std::move(position)) {

}



