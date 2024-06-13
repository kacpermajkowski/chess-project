#ifndef CHESSPROJECT_TEXTUI_H
#define CHESSPROJECT_TEXTUI_H

#include "UI.h"
#include "typedefs.h"

class TextUI : public UI{
public:
    void update(StatePtr state) override;
};


#endif //CHESSPROJECT_TEXTUI_H
