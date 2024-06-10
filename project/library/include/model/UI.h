#ifndef CHESSPROJECT_UI_H
#define CHESSPROJECT_UI_H

#include "Game.h"

class UI {
public:
    void update(State state);
    void endGameScreen(State state);
    PromotionType getTypeOfPromotion();
};


#endif //CHESSPROJECT_UI_H
