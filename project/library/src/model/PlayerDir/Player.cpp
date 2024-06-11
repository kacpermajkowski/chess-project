#include "model/PlayerDir/Player.h"

Player::Player(PlayerColor color) : color(color) {};
Player::~Player() {};

PlayerColor Player::getColor() const {
    return color;
}


