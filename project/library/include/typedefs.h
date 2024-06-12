#ifndef CHESSPROJECT_TYPEDEFS_H
#define CHESSPROJECT_TYPEDEFS_H

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

typedef Unit* UnitPtr;
typedef Player* PlayerPtr;
typedef Board* BoardPtr;
typedef Field* FieldPtr;
typedef Move* MovePtr;
typedef State* StatePtr;
typedef Position* PositionPtr;
typedef UI* UIPtr;
typedef MoveVector* MoveVectorPtr;
typedef Action* ActionPtr

enum ActionType{
    NONE,
    TAKE,
    CASTLE,
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
