#ifndef CHESSPROJECT_UI_H
#define CHESSPROJECT_UI_H

#include "model/Game.h"

class UI {
public:
    virtual void update(State state) = 0;
    virtual void endGameScreen(State state) = 0;
    virtual PromotionType getTypeOfPromotion() = 0;
};


#endif //CHESSPROJECT_UI_H
