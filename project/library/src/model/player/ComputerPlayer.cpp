#include <cstdlib>
#include "model/player/ComputerPlayer.h"
#include "model/exceptions/NoMoveToChooseFromException.h"
#include "model/exceptions/StateIntegrityException.h"
#include "model/Game.h"

ComputerPlayer::ComputerPlayer(PlayerColor color) : Player(color) {
    srand(time(nullptr));
}

MovePtr ComputerPlayer::chooseAMove(const GamePtr &game) {
    std::vector<MovePtr> legalMoves = game->getState()->getLegalMoves(getColor());
    if(!legalMoves.empty()) {
        int moveNumber = (rand() % legalMoves.size());
        return legalMoves[moveNumber];
    } throw StateIntegrityException("There should be at least one legal move if the game has not concluded yet.");
}
