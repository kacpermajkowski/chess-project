#include <stdexcept>
#include "model/Game.h"
#include "model/PlayerDir/HumanPlayer.h"

Game::~Game() {}

StatePtr Game::getState() const {
    return state;
}

UIPtr Game::getUI() const {
    return ui;
}

Game::Game(PlayerPtr firstPlayer, PlayerPtr secondPlayer, UIPtr ui) {
    state = new State();
    this->ui = ui;
    if(firstPlayer->getColor() != secondPlayer->getColor()){
        this->firstPlayer = firstPlayer;
        this->secondPlayer = secondPlayer;
    } else throw std::invalid_argument("Players must have opposing colors.");

}

PlayerPtr Game::getPlayer(PlayerColor color) const {
    if(firstPlayer->getColor() == color)
        return firstPlayer;
    else
        return secondPlayer;
BoardPtr Game::getBoard() const {
    return nullptr;
}


