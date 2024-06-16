#include <cstdlib>
#include "model/PlayerDir/HumanPlayer.h"
#include "model/exceptions/StateIntegrityException.h"

HumanPlayer::HumanPlayer(PlayerColor color) : Player(color) {}

MovePtr HumanPlayer::chooseAMove(std::vector<MovePtr> legalMoves) {
    //TODO: Get input from player;
    if(!legalMoves.empty()){
        int moveNumber = (rand()%legalMoves.size());
        return legalMoves[moveNumber];
    } throw StateIntegrityException("There should be at least one legal move if the game has not concluded yet.");
}

