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

    PlayerPtr firstPlayer = std::make_shared<ComputerPlayer>(WHITE);
    PlayerPtr secondPlayer = std::make_shared<HumanPlayer>(BLACK);

    Game game(firstPlayer, secondPlayer, textUI);


    textUI->update(game.getState());


//    while(!game.getState()->hasConcluded()){
//
//    }

    return 0;
}