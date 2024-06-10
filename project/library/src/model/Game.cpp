#include "model/Game.h"

Game::Game(GameType gameType, UI *ui) : gameType(gameType), ui(ui) {}
Game::~Game() {}

State *Game::getState() const {
    return state;
}

UI *Game::getUi() const {
    return ui;
}

Board *Game::getBoard() const {
    return nullptr;
}


