#include <cstdlib>
#include "model/PlayerDir/ComputerPlayer.h"

ComputerPlayer::ComputerPlayer(PlayerColor color) : Player(color) {
    srand(time(NULL));
}

MovePtr ComputerPlayer::makeAMove(std::vector<MovePtr> legalMoves) {
    int moveNumber = (rand()%legalMoves.size());
    return legalMoves[moveNumber];
}
