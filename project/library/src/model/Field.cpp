#include "model/Field.h"

#include <utility>

Field::Field(PositionPtr position, UnitPtr unit) : position(std::move(position)), unit(std::move(unit)) {}
Field::~Field() = default;

PositionPtr Field::getPosition() {
    return position;
}

UnitPtr Field::getUnit() {
    return unit;
}

void Field::setUnit(UnitPtr newUnit) {
    Field::unit = std::move(newUnit);
}

bool Field::isOccupiedByEnemy(PlayerColor color) {
    if(isOccupied()){
        return getUnit()->getColor() != color;
    }
    return false;
}

bool Field::isOccupiedByEnemy(const UnitPtr& allyUnit) {
    return isOccupiedByEnemy(allyUnit->getColor());
}

bool Field::isOccupiedByAlly(PlayerColor color) {
    if(isOccupied()){
        return getUnit()->getColor() == color;
    }
    return false;
}

bool Field::isOccupiedByAlly(const UnitPtr& allyUnit) {
    return isOccupiedByAlly(allyUnit->getColor());
}

bool Field::isOccupied() {
    return getUnit() != nullptr;
}

Field::Field(PositionPtr position) : position(std::move(position)) {

}



