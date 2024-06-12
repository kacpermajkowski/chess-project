#ifndef CHESSPROJECT_STATE_H
#define CHESSPROJECT_STATE_H

#include <vector>
#include "model/move/Move.h"
#include "typedefs.h"
#include "Board.h"

class State {
private:
    std::vector<MovePtr> moveHistory;
    unsigned int movesWithoutCapture;
    Conclusion conclusion = IN_PROGRESS;
    PlayerColor turn;
    bool check;
    std::vector<UnitPtr> takenPieces;
    BoardPtr board;

public:

    explicit State(BoardPtr board);
    virtual ~State();

    std::vector<MovePtr> getLegalMoves() const;
    void conclude(Conclusion conclusion);
    void registerMove(MovePtr move);

    bool isCheck() const;
    Conclusion getConclusion() const;
    PlayerColor getTurn() const;
    BoardPtr getBoard() const;
    const std::vector<UnitPtr> &getTakenPieces() const;
    unsigned int getMovesWithoutCapture() const;
    const std::vector<MovePtr> &getMoveHistory() const;

    bool isAttacked(FieldPtr field);
    bool hasConcluded() const;
};


#endif //CHESSPROJECT_STATE_H
