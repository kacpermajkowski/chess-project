#ifndef CHESSPROJECT_GAME_H
#define CHESSPROJECT_GAME_H

#include "PlayerDir/Player.h"
#include "State.h"
#include "enum.h"
#include "UI.h"

class Game {
private:
    Player* whitePlayer;
    Player* blackPlayer;
    State* state;
    UI* ui;

public:
    Game(GameType gameType, UI *ui);
    virtual ~Game();

    Player* getPlayer(Color color) const;

    State *getState() const;

    UI *getUi() const;

    Board* getBoard() const;

    bool hasEnded();

    void makeAMove();

    Player* getCurrentPlayer() const;
};


#endif //CHESSPROJECT_GAME_H
