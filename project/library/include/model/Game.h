#ifndef CHESSPROJECT_GAME_H
#define CHESSPROJECT_GAME_H

#include "PlayerDir/Player.h"
#include "State.h"
#include "typedefs.h"
#include "model/ui/UI.h"

class Game {
private:
    PlayerPtr whitePlayer;
    PlayerPtr blackPlayer;
    StatePtr state;
    UIPtr ui;

public:
    Game(GameType gameType, UIPtr ui);
    virtual ~Game();

    PlayerPtr getPlayer(PlayerColor color) const;

    StatePtr getState() const;

    UIPtr getUi() const;

    BoardPtr getBoard() const;
};


#endif //CHESSPROJECT_GAME_H
