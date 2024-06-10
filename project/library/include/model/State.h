#ifndef CHESSPROJECT_STATE_H
#define CHESSPROJECT_STATE_H

#include <vector>
#include "Move.h"
#include "enum.h"
#include "Board.h"

class State {
private:
    std::vector<Move*> moveHistory;
    unsigned int movesWithoutCapture;
    Conclusion conclusion;
    Color turn;
    bool isCheck;
    std::vector<Unit*> takenPieces;
    Board* board;

public:

    explicit State(Board *board);
    virtual ~State();

    const std::vector<Move *> &getMoveHistory() const;

    unsigned int getMovesWithoutCapture() const;

    Conclusion getConclusion() const;

    Color getTurn() const;

    bool getIsCheck() const;

    const std::vector<Unit *> &getTakenPieces() const;

    Board *getBoard() const;

    void registerMove(Move* move);

    // isAttacked(Field* field);
};


#endif //CHESSPROJECT_STATE_H
