//chessProject

#include <iostream>
#include "../../library/include/typedefs.h"
#include "../../library/include/model/Game.h"
#include "../../library/include/model/PlayerDir/HumanPlayer.h"
#include "../../library/include/model/PlayerDir/ComputerPlayer.h"
#include "../../library/include/model/ui/TextUI.h"

using namespace std;

int main(){

    UIPtr textUI = std::make_shared<TextUI>();

    //TODO: Select player types
    PlayerPtr firstPlayer = std::make_shared<ComputerPlayer>(WHITE);
    PlayerPtr secondPlayer = std::make_shared<HumanPlayer>(BLACK);

    Game game(firstPlayer, secondPlayer, textUI);

    while (!game.getState()->hasConcluded()){
        textUI->update(game.getState());
        PlayerPtr currentPlayer = firstPlayer->getColor() == game.getState()->getTurn() ? firstPlayer : secondPlayer;
//        MovePtr move = currentPlayer->makeAMove(game.getState()->getLegalMoves(game.getState()->getTurn()));
//        game.getState()->registerMove(move);
        getchar();
    }
    textUI->endGameScreen(game.getState());

    return 0;
}