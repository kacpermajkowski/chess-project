#include <cstdlib>
#include "model/PlayerDir/ComputerPlayer.h"

ComputerPlayer::ComputerPlayer(PlayerColor color) : Player(color) {
    srand(time(NULL));
}

MovePtr ComputerPlayer::makeAMove(std::vector<MovePtr> legalMoves) {
    if(legalMoves.size() > 0) {
        int moveNumber = (rand() % legalMoves.size());
        return legalMoves[moveNumber];
    } //TODO: Else conclude;
    return nullptr;
}
