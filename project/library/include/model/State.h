#ifndef CHESSPROJECT_STATE_H
#define CHESSPROJECT_STATE_H

#include <vector>
#include "model/move/Move.h"
#include "typedefs.h"
#include "Board.h"

class StateFriend; // Forward declaration of friend class

/**
 * @class State
 * @brief Represents the current state of a chess game, including board configuration,
 *        move history, captured pieces, and game status
 */
class State : public std::enable_shared_from_this<State> {
private:

    std::vector<MovePtr> moveHistory;       ///< History of moves made in the game
    unsigned int fiftyMoveRuleCounter = 0;  ///< Counter for the 50-move draw rule
    Conclusion conclusion = IN_PROGRESS;    ///< Current conclusion status of the game
    PlayerColor turn = WHITE;               ///< Current turn's player color
    std::vector<UnitPtr> takenPieces;       ///< Pieces captured during the game
    BoardPtr board;                         ///< Pointer to the game board

public:

    /**
     * @brief Default constructor, initializes a default board
     */
    explicit State();
    virtual ~State();

    /**
    * @brief Constructor with a specified board configuration
    * @param board Shared pointer to a Board object
    */
    explicit State(std::shared_ptr<Board> board);

    /**
     * @brief Concludes the game with a given conclusion, only if current conclusion is IN_PROGRESS
     * @param conclusion Conclusion of the game (e.g., DRAW, WHITE_WINS)
     *
     */
    void conclude(Conclusion conclusion);
    /**
     * @brief Executes a move in the game
     * @param move Pointer to a Move object representing the move to be executed
     */
    void makeAMove(const MovePtr& move);
    /**
     * @param color PlayerColor of the player for whom legal moves are to be retrieved
     * @return Vector of pointers to Move objects representing legal moves
     */
    std::vector<MovePtr> getLegalMoves(PlayerColor color);
    /**
     * @brief Retrieves legal moves for the current turn's player
     * @return Vector of pointers to Move objects representing legal moves
     */
    std::vector<MovePtr> getLegalMoves();

    /**
     * @brief Checks if a player's king of a specified color is in check
     * @param kingColor PlayerColor of the king to check
     * @return True if the king is in check, false otherwise
     */
    bool isCheck(PlayerColor kingColor);
    /**
     * @brief Checks if the current turn's player is in check
     * @return True if the current player is in check, false otherwise
     */
    bool isCheck();
    /**
     * @return Conclusion enumeration representing the current game conclusion
     */
    Conclusion getConclusion() const;
    /**
     * @return PlayerColor of the current turn
     */
    PlayerColor getTurn() const;
    /**
     * @return Shared pointer to a Board object
     */
    BoardPtr getBoard() const;
    /**
     * @brief Retrieves the vector of units captured during the game
     * @return Vector of shared pointers to Unit objects representing captured pieces
     */
    const std::vector<UnitPtr> & getTakenPieces() const;
    /**
     * @brief Retrieves the counter for the 50-move draw rule.
     * @return Unsigned integer representing the number of moves since the last pawn move or capture
     */
    unsigned int getFiftyMovesRuleCounter() const;
    /**
     * @brief Retrieves the vector of moves made during the game
     * @return Vector of pointers to Move objects representing the move history
     */
    const std::vector<MovePtr> & getMoveHistory() const;
    /**
     * @brief Retrieves the last move made in the game
     * @return Pointer to a Move object representing the last move made
     */
    MovePtr getLastMove();
    /**
     * @brief Checks if a specific unit has been moved during the game
     * @param unit Pointer to a Unit object to check
     * @return True if the unit has been moved, false otherwise
     */
    bool hasMoved(UnitPtr unit);

    /**
     * @brief Checks if a field is attacked by an opponent player
     * @param field Pointer to a Field object representing the field to check
     * @param defender PlayerColor of the player defending the field
     * @return True if the field is attacked, false otherwise
     */
    bool isAttacked(const FieldPtr& field, PlayerColor defender);
    /**
     * @brief Checks if the game has concluded (if the conclusion is different than IN_PROGRESS)
     * @return True if the game has concluded, false otherwise
     */
    bool hasConcluded() const;

private:
    // Private methods for internal game state manipulation and checks

    /**
     * @brief Moves a unit between fields after a move is made
     */
    void moveUnitBetweenFields();

    /**
     * @brief Performs an action associated with the last move made
     */
    void performAction();

    /**
     * @brief Changes the turn to the next player
     */
    void changeTurn();

    /**
     * @brief Checks if the game should end in a draw due to the 50-move rule
     * @return True if the game should end, false otherwise
     */
    bool isFiftyMoveRuleDraw();

    /**
     * @brief Concludes the game if applicable based on game rules such as checkmate or stalemate
     */
    void concludeIfApplicable();

    /**
     * Method is not yet implemented
     *
     * @brief Checks if the game should end in a draw due to repetition
     * @return True if the game should end, false otherwise
     */
    bool isDrawByRepetition();

    /**
     * Method is not yet implemented
     *
     * @brief Checks if the game should end in a draw due to insufficient material
     * @return True if the game should end, false otherwise
     */
    bool isInsufficientMaterial();

    /**
     * @return True if the game has ended in a stalemate, false otherwise
     */
    bool isStalemate();

    /**
     * @return True if the game has ended in checkmate, false otherwise
     */
    bool isCheckmate();

    /**
     * @brief Captures a unit from a field during the game
     * @param move Pointer to a Move object that causes the capture of the unit
     */
    void captureUnit(const MovePtr &move);

    /**
     * @brief Moves a rook as part of castling
     * @param action Pointer to an Action object representing the castling action
     */
    void moveRookToCastle(const ActionPtr& action);

    /**
     * @brief Checks if a rook is in a valid position to perform castling
     * @param field Pointer to a Field object representing the rook's current position
     * @return True if the rook is in a valid position to castle, false otherwise
     */
    static bool isRookInFieldValidToCastle(const FieldPtr& field);

    /**
     * @brief Determines the target field for castling based on the rook's position
     * @param rookField Pointer to a Field object representing the rook's current position
     * @return Pointer to a Field object representing the target field for castling
     */
    FieldPtr getRookCastleTargetField(const FieldPtr& rookField);

    /**
     * @brief Determines the type of castling based on the column of the rook's position
     * @param column LetterIndex representing the column of the rook's position
     * @return CastleType representing the type of castling (SHORT_CASTLE or LONG_CASTLE)
     */
    static CastleType getCastleTypeByColumn(LetterIndex column);

    /**
     * Method is not yet completely implemented
     *
     * @brief Promotes a pawn to another piece during the game
     * @param move Pointer to a Move object representing the promotion move
     */
    static void promotePawn(const MovePtr& move);

    /**
     *
     * @brief
     * @param move Pointer to a Move object
     */
    static bool isPawnPromotion(const MovePtr& move);

    friend StateFriend; ///< Friend class declaration
};


#endif //CHESSPROJECT_STATE_H
