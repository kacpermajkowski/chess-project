#include <stdexcept>
#include <utility>
#include <iostream>
#include "model/Game.h"
#include "model/player/HumanPlayer.h"

Game::~Game() {}

StatePtr Game::getState() const {
    return state;
}

UIPtr Game::getUI() const {
    return ui;
}

Game::Game(PlayerPtr firstPlayer, PlayerPtr secondPlayer, UIPtr ui) {
    state = std::make_shared<State>();
    this->ui = std::move(ui);
    if(firstPlayer != nullptr && secondPlayer != nullptr) {
        if (firstPlayer->getColor() != secondPlayer->getColor()) {
            this->firstPlayer = firstPlayer;
            this->secondPlayer = secondPlayer;
        } else throw std::invalid_argument("Players must have opposing colors.");
    } else throw std::invalid_argument("Pointers to both players have to be valid.");
}

void Game::run(){
    while (!getState()->hasConcluded()){
        ui->update(state);

        PlayerPtr currentPlayer = firstPlayer->getColor() == state->getTurn() ? firstPlayer : secondPlayer;
        MovePtr move = currentPlayer->chooseAMove(shared_from_this());
        getState()->makeAMove(move);
    }
    ui->endGameScreen(getState());
}

PlayerPtr Game::getPlayer(PlayerColor color) const {
    if (firstPlayer->getColor() == color)
        return firstPlayer;
    else
        return secondPlayer;
}

