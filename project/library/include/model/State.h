#ifndef CHESSPROJECT_STATE_H
#define CHESSPROJECT_STATE_H

#include <vector>
#include "model/move/Move.h"
#include "typedefs.h"
#include "Board.h"

class StateFriend;

class State : public std::enable_shared_from_this<State> {
private:

    std::vector<MovePtr> moveHistory;
    unsigned int fiftyMoveRuleCounter = 0;
    Conclusion conclusion = IN_PROGRESS;
    PlayerColor turn = WHITE;
    std::vector<UnitPtr> takenPieces;
    BoardPtr board;

public:

    explicit State();
    virtual ~State();

    void conclude(Conclusion conclusion);
    void makeAMove(const MovePtr& move);
    std::vector<MovePtr> getLegalMoves(PlayerColor color);
    std::vector<MovePtr> getLegalMoves();

    bool isCheck(PlayerColor kingColor);
    bool isCheck();
    Conclusion getConclusion() const;
    PlayerColor getTurn() const;
    BoardPtr getBoard() const;
    const std::vector<UnitPtr> & getTakenPieces() const;
    unsigned int getFiftyMovesRuleCounter() const;
    const std::vector<MovePtr> & getMoveHistory() const;
    MovePtr getLastMove();
    bool hasMoved(UnitPtr unit);

    bool isAttacked(const FieldPtr& field, PlayerColor defender);
    bool hasConcluded() const;


    explicit State(std::shared_ptr<Board> board);
private:
    void moveUnitBetweenFields();

    void performAction();

    void changeTurn();

    bool isFiftyMoveRuleDraw();

    void concludeIfApplicable();

    bool isDrawByRepetition();

    bool isInsufficientMaterial();

    bool isStalemate();

    bool isCheckmate();

    void captureUnitFromField(const FieldPtr& sharedPtr);

    void moveRookToCastle(const ActionPtr& action);

    static bool isRookInFieldValidToCastle(const FieldPtr& field);

    FieldPtr getRookCastleTargetField(const FieldPtr& rookField);

    static CastleType getCastleTypeByColumn(LetterIndex column);

    static void promotePawn(const MovePtr& move);

    friend StateFriend;
};


#endif //CHESSPROJECT_STATE_H
