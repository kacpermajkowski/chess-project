#ifndef CHESSPROJECT_STATE_H
#define CHESSPROJECT_STATE_H

#include <vector>
#include "model/move/Move.h"
#include "typedefs.h"
#include "Board.h"

class State {
private:
    std::vector<MovePtr> moveHistory;
    unsigned int fiftyMoveRuleCounter = 0;
    Conclusion conclusion = IN_PROGRESS;
    PlayerColor turn = WHITE;
    bool check = false;
    std::vector<UnitPtr> takenPieces;
    BoardPtr board;

public:

    explicit State();
    virtual ~State();

    void conclude(Conclusion conclusion);
    void registerMove(MovePtr move);
    std::vector<MovePtr> getLegalMoves(PlayerColor color) const;
    std::vector<MovePtr> getLegalMoves() const;

    bool isCheck() const;
    Conclusion getConclusion() const;
    PlayerColor getTurn() const;
    BoardPtr getBoard() const;
    const std::vector<UnitPtr> & getTakenPieces() const;
    unsigned int getMovesWithoutCapture() const;
    const std::vector<MovePtr> & getMoveHistory() const;

    bool isAttacked(FieldPtr field);
    bool hasConcluded() const;


};


#endif //CHESSPROJECT_STATE_H
