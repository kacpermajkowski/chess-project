#ifndef CHESSPROJECT_STATE_H
#define CHESSPROJECT_STATE_H

#include <vector>
#include "model/move/Move.h"
#include "typedefs.h"
#include "Board.h"

class State : public std::enable_shared_from_this<State> {
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
    std::vector<MovePtr> getLegalMoves(PlayerColor color);
    std::vector<MovePtr> getLegalMoves();

    bool isCheck();
    Conclusion getConclusion() const;
    PlayerColor getTurn() const;
    BoardPtr getBoard() const;
    const std::vector<UnitPtr> & getTakenPieces() const;
    unsigned int getFiftyMovesRuleCounter() const;
    const std::vector<MovePtr> & getMoveHistory() const;
    MovePtr getLastMove();
    bool hasMoved(UnitPtr unit);

    bool isAttacked(FieldPtr field, PlayerColor defender);
    bool hasConcluded() const;


    State(std::shared_ptr<Board> board);
};


#endif //CHESSPROJECT_STATE_H
