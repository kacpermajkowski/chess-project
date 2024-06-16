#ifndef CHESSPROJECT_UI_H
#define CHESSPROJECT_UI_H

#include "typedefs.h"
#include <memory>


class UI : public std::enable_shared_from_this<UI>{
public:
    virtual void update(StatePtr state) = 0;

    virtual void endGameScreen(StatePtr state) = 0;

    virtual wchar_t getFromUser(wchar_t begin, wchar_t end) = 0;
    //virtual PromotionType getTypeOfPromotion() = 0;
    virtual PlayerPtr getPlayerByUserChoice(PlayerColor color) = 0;
};


#endif //CHESSPROJECT_UI_H
