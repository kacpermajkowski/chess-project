//chessProject

#include <iostream>
#include "../../library/include/typedefs.h"
#include "../../library/include/model/Game.h"
#include "../../library/include/model/PlayerDir/HumanPlayer.h"
#include "../../library/include/model/PlayerDir/ComputerPlayer.h"
#include "../../library/include/model/ui/TextUI.h"
#include "model/exceptions/StateIntegrityException.h"

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
        std::vector<MovePtr> legalMoves = game.getState()->getLegalMoves(currentPlayer->getColor());

        MovePtr move = currentPlayer->chooseAMove(legalMoves);
        game.getState()->makeAMove(move);
    }
    textUI->endGameScreen(game.getState());

    return 0;
}