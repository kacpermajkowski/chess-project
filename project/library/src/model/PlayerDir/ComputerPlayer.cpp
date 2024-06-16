#include <cstdlib>
#include "model/PlayerDir/ComputerPlayer.h"
#include "model/exceptions/NoMoveToChooseFromException.h"
#include "model/exceptions/StateIntegrityException.h"

ComputerPlayer::ComputerPlayer(PlayerColor color) : Player(color) {
    srand(time(NULL));
}

MovePtr ComputerPlayer::chooseAMove(std::vector<MovePtr> legalMoves) {
    if(!legalMoves.empty()) {
        int moveNumber = (rand() % legalMoves.size());
        return legalMoves[moveNumber];
    } throw StateIntegrityException("There should be at least one legal move if the game has not concluded yet.");
}
