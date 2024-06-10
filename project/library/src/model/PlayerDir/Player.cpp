#include "model/PlayerDir/Player.h"

Player::Player(Color color) : color(color) {};
Player::~Player() {};

Color Player::getColor() const {
    return color;
}

void Player::makeAMove(Move move) {

}

