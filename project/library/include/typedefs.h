#ifndef CHESSPROJECT_TYPEDEFS_H
#define CHESSPROJECT_TYPEDEFS_H

#include <memory>

// Forward declarations for classes used in shared pointers
class Unit;
class Position;
class State;
class Player;
class Board;
class Field;
class Move;
class UI;
class MoveVector;
class Action;
class Game;

// Shared pointer typedefs for various classes
typedef std::shared_ptr<Unit> UnitPtr;
typedef std::shared_ptr<Player> PlayerPtr;
typedef std::shared_ptr<Board> BoardPtr;
typedef std::shared_ptr<Field> FieldPtr;
typedef std::shared_ptr<Move> MovePtr;
typedef std::shared_ptr<State> StatePtr;
typedef std::shared_ptr<Position> PositionPtr;
typedef std::shared_ptr<UI> UIPtr;
typedef std::shared_ptr<MoveVector> MoveVectorPtr;
typedef std::shared_ptr<Action> ActionPtr;
typedef std::shared_ptr<Game> GamePtr;


// Enum defining different types of actions
enum ActionType{
    CAPTURE,
    CASTLE
};

// Enum defining types of castle moves
enum CastleType{
    SHORT_CASTLE,
    LONG_CASTLE
};

// Enum defining player colors
enum PlayerColor{
    BLACK,
    WHITE
};

// Enum defining types of promotion during a pawn promotion
enum PromotionType{
    KNIGHT,
    ROOK,
    QUEEN,
    BISHOP
};

// Enum defining different game conclusions
enum Conclusion{
    IN_PROGRESS,
    DRAW,
    STALEMATE,
    WHITE_WINS,
    BLACK_WINS,
    FIFTY_MOVES_DRAW,
    INSUFFICIENT_MATERIAL_DRAW,
    REPETITION_DRAW,
    AGREED_DRAW
};

// Enum defining letter indices for chess board columns
enum LetterIndex{
    A = 0,
    B = 1,
    C = 2,
    D = 3,
    E = 4,
    F = 5,
    G = 6,
    H = 7
};

// Enum defining number indices for chess board rows
enum NumberIndex{
    _1 = 0,
    _2 = 1,
    _3 = 2,
    _4 = 3,
    _5 = 4,
    _6 = 5,
    _7 = 6,
    _8 = 7
};


#endif //CHESSPROJECT_TYPEDEFS_H
