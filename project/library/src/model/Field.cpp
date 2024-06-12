#include "model/Field.h"

Field::Field(PositionPtr position, UnitPtr unit) {}
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

