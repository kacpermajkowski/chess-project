#ifndef CHESSPROJECT_ENUM_H
#define CHESSPROJECT_ENUM_H

enum Color{
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
        A,
        B,
        C,
        D,
        E,
        F,
        G,
        H
};

enum NumberIndex{
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8
};


enum GameType{
    PVP,
    PVE,
    EVE
};

#endif //CHESSPROJECT_ENUM_H
