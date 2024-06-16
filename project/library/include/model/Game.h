#ifndef CHESSPROJECT_GAME_H
#define CHESSPROJECT_GAME_H

#include "player/Player.h"
#include "State.h"
#include "typedefs.h"
#include "model/ui/UI.h"

class Game : public std::enable_shared_from_this<Game>{
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

    void run();
};


#endif //CHESSPROJECT_GAME_H
