#include <cstdlib>
#include "model/PlayerDir/ComputerPlayer.h"
#include "model/exceptions/NoMoveToChooseFromException.h"

ComputerPlayer::ComputerPlayer(PlayerColor color) : Player(color) {
    srand(time(NULL));
}

MovePtr ComputerPlayer::chooseAMove(std::vector<MovePtr> legalMoves) {
    if(legalMoves.size() > 0) {
        int moveNumber = (rand() % legalMoves.size());
        return legalMoves[moveNumber];
    } throw NoMoveToChooseFromException();
}
