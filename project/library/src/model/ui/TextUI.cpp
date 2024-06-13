#include <iostream>
#include <typeinfo>
#include "model/ui/TextUI.h"

#include "model/UnitDir/King.h"
#include "model/UnitDir/Queen.h"
#include "model/UnitDir/Rook.h"
#include "model/UnitDir/Bishop.h"
#include "model/UnitDir/Knight.h"
#include "model/UnitDir/Pawn.h"
#include "model/State.h"


#include <locale>
#include <codecvt>
#include <string>

void TextUI::update(StatePtr state) {
    std::locale::global(std::locale("en_US.UTF-8")); //nw czy w dobrym miejscu
    std::wcout.imbue(std::locale());

    wchar_t blackSquare = L'⛆'; //9926
    wchar_t whiteSquare = L'⛚'; //9946

    wchar_t whiteKing = L'♔';
    wchar_t whiteQueen = L'♕';
    wchar_t whiteRook = L'♖';
    wchar_t whiteBishop = L'♗';
    wchar_t whiteKnight = L'♘';
    wchar_t whitePawn = L'♙';
    wchar_t blackKing = L'♚';
    wchar_t blackQueen = L'♛';
    wchar_t blackRook = L'♜';
    wchar_t blackBishop = L'♝';
    wchar_t blackKnight = L'♞';
    wchar_t blackPawn = L'♟';

    std::wcout << std::endl;
    wchar_t unitSymbol = L' ';
    for (int rows = 7; rows >= 0; rows--) {
        for (int line = 0; line <= 2; line++) {
            for (int column = 0; column <= 7; column++) {

                wchar_t block = ((rows + column) % 2 == 0) ? blackSquare : whiteSquare;

                if (line == 1) {
                    FieldPtr f = state->getBoard()->getField(std::make_shared<Position>(LetterIndex(column), NumberIndex(rows)));
                    if (f->getUnit() != nullptr) {
                        UnitPtr currentUnit = f->getUnit();
                        unitSymbol = blackBishop;
                        if (typeid(*currentUnit) == typeid(King))
                            unitSymbol = currentUnit->getColor() == WHITE ? blackKing : whiteKing;
                        else if (typeid(*currentUnit) == typeid(Queen))
                            unitSymbol = currentUnit->getColor() == WHITE ? blackQueen : whiteQueen;
                        else if (typeid(*currentUnit) == typeid(Rook))
                            unitSymbol = currentUnit->getColor() == WHITE ? blackRook : whiteRook;
                        else if (typeid(*currentUnit) == typeid(Bishop))
                            unitSymbol = currentUnit->getColor() == WHITE ? blackBishop : whiteBishop;
                        else if (typeid(*currentUnit) == typeid(Knight))
                            unitSymbol = currentUnit->getColor() == WHITE ? blackKnight : whiteKnight;
                        else if (typeid(*currentUnit) == typeid(Pawn))
                            unitSymbol = currentUnit->getColor() == WHITE ? blackPawn : whitePawn;
                    } else unitSymbol = block;
                    std::wcout << block << L' ' << unitSymbol << L' ' << block << L' ';
                } else {
                    std::wcout << block << L' ' << block << L' ' << block << L' ';
                }
            }
            std::wcout << std::endl;
        }
    }
}

void TextUI::endGameScreen(StatePtr state) {
    std::wcout << L"End game screen";
}
