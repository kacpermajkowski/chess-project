#include "model/UnitDir/Unit.h"

Unit::Unit(PlayerColor color) : color(color) {};
Unit::~Unit() {};

PlayerColor Unit::getColor() const {
    return color;
}
