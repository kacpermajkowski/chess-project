#include "model/PlayerDir/HumanPlayer.h"

HumanPlayer::HumanPlayer(Color color) : Player(color) {};
HumanPlayer::~HumanPlayer() {}

Color HumanPlayer::getColor() const {
    return Player::getColor();
}

void HumanPlayer::makeAMove(Move move) {
    //pobranie ruchu od gracza
    //wywolanie Board.makeMove
};

