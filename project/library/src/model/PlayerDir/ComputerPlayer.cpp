#include "model/PlayerDir/ComputerPlayer.h"

ComputerPlayer::ComputerPlayer(Color color) : Player(color) {};
ComputerPlayer::~ComputerPlayer() {}

Color ComputerPlayer::getColor() const {
    return Player::getColor();
}

void ComputerPlayer::makeAMove(Move move) {
    //wylosowanie ruchu sposrod mozliwych
    //wywolanie Board.makeMove
};

