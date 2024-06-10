#include "model/UnitDir/Unit.h"

Unit::Unit(Color color) : color(color) {};
Unit::~Unit() {};

Color Unit::getColor() const {
    return color;
}

std::vector<Move> Unit::getLegalMoves() {
    return std::vector<Move>();
}