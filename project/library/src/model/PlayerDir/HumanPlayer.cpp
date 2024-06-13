#include <cstdlib>
#include "model/PlayerDir/HumanPlayer.h"

HumanPlayer::HumanPlayer(PlayerColor color) : Player(color) {}

MovePtr HumanPlayer::makeAMove(std::vector<MovePtr> legalMoves) {
    //TODO: Get input from player;
    if(legalMoves.size() > 0){
        int moveNumber = (rand()%legalMoves.size());
        return legalMoves[moveNumber];
    } //TODO: else throw
    //TODO: If legal moves is 0 then conclude stalemate
    return nullptr;
}

