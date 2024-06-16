#ifndef CHESSPROJECT_TEXTUI_H
#define CHESSPROJECT_TEXTUI_H

#include "UI.h"
#include "typedefs.h"

class TextUI : public UI{
public:
    TextUI();

    void update(StatePtr state) override;

    void endGameScreen(StatePtr state) override;

    wchar_t getFromUser(wchar_t begin, wchar_t end) override;

    PlayerPtr getPlayerByUserChoice(PlayerColor color) override;
};


#endif //CHESSPROJECT_TEXTUI_H
