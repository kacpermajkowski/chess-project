#ifndef CHESSPROJECT_GAME_H
#define CHESSPROJECT_GAME_H

#include "PlayerDir/Player.h"
#include "State.h"
#include "typedefs.h"
#include "model/ui/UI.h"

class Game {
private:
    PlayerPtr firstPlayer;
    PlayerPtr secondPlayer;
    StatePtr state;
    UIPtr ui;

public:
    Game(PlayerPtr firstPlayer, PlayerPtr secondPlayer, UIPtr ui);
    virtual ~Game();

    PlayerPtr getPlayer(PlayerColor color) const;

    StatePtr getState() const;

    UIPtr getUI() const;
};


#endif //CHESSPROJECT_GAME_H
