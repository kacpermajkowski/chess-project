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
    UIPtr ui = std::make_shared<TextUI>();

    wcout << L"Wybierz, kto będzie grał białymi (1 - człowiek, 2 - komputer): ";
    PlayerPtr firstPlayer = ui->getPlayerByUserChoice(WHITE);
    wcout << L"Wybierz, kto będzie grał czarnymi (1 - człowiek, 2 - komputer): ";
    PlayerPtr secondPlayer = ui->getPlayerByUserChoice(BLACK);

    GamePtr game = make_shared<Game>(firstPlayer, secondPlayer, ui);
    game->run();

    return 0;
}