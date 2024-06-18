#ifndef CHESSPROJECT_TYPEDEFS_H
#define CHESSPROJECT_TYPEDEFS_H

#include <memory>

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


enum ActionType{
    CAPTURE,
    CASTLE
};

enum CastleType{
    SHORT_CASTLE,
    LONG_CASTLE
};

enum PlayerColor{
    BLACK,
    WHITE
};

enum PromotionType{
    KNIGHT,
    ROOK,
    QUEEN,
    BISHOP
};

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


enum GameType{
    PVP,
    PVE,
    EVE
};

#endif //CHESSPROJECT_TYPEDEFS_H
