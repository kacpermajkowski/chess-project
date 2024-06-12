#include "model/Game.h"

Game::Game(GameType gameType, UIPtr ui) {

}

Game::~Game() {}

StatePtr Game::getState() const {
    return state;
}

UIPtr Game::getUi() const {
    return ui;
}

BoardPtr Game::getBoard() const {
    return nullptr;
}

PlayerPtr Game::getPlayer(PlayerColor color) const {
    return nullptr;
}


