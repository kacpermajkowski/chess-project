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

