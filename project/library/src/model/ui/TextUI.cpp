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
#include "../src/model/util/util.cpp"

#include <locale>
#include <codecvt>
#include <string>
#include <map>

wchar_t* concatenate(const wchar_t* str1, const wchar_t* str2) {
    // Calculate the length of the concatenated string
    size_t len1 = wcslen(str1);
    size_t len2 = wcslen(str2);
    size_t totalLen = len1 + len2;

    // Allocate memory for the new string
    // +1 for the null terminator
    wchar_t* result = new wchar_t[totalLen + 1];

    // Copy the first string to the result
    wcscpy(result, str1);

    // Concatenate the second string to the result
    wcscat(result, str2);

    return result;
}

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

    // ANSI escape codes for colors
    const wchar_t * RESET = L"\033[0m";
    const wchar_t * BLACK_BG = L"\033[44m";
    const wchar_t * WHITE_BG = L"\033[47m";

    const wchar_t * WHITE_FG = L"\033[97m";
    const wchar_t * BLACK_FG = L"\033[30m";

    std::wcout << std::endl;
    for(int rows = 7; rows >= 0; rows--){
        std::wcout << (wchar_t)(L'1'+rows) << L" ";
        for(int column = 0; column <= 7; column++){
            if((rows + column) % 2 == 0){
                std::wcout << BLACK_BG;
            } else{
                std::wcout << WHITE_BG;
            }

            std::wcout << L"  ";
            FieldPtr f = state->getBoard()->getField(std::make_shared<Position>(LetterIndex(column), NumberIndex(rows)));
            if (f->getUnit() != nullptr) {
                UnitPtr currentUnit = f->getUnit();
                //Font color
                std::wcout << ((currentUnit->getColor() == BLACK) ? BLACK_FG : WHITE_FG);
                //Icon
                if (isTypeOf<King>(currentUnit))
                    std::wcout << ((currentUnit->getColor() == BLACK) ? blackKing : whiteKing);
                else if (isTypeOf<Queen>(currentUnit))
                    std::wcout << ((currentUnit->getColor() == BLACK) ? blackQueen : whiteQueen);
                else if (isTypeOf<Rook>(currentUnit))
                    std::wcout << ((currentUnit->getColor() == BLACK) ? blackRook : whiteRook);
                else if (isTypeOf<Bishop>(currentUnit))
                    std::wcout << ((currentUnit->getColor() == BLACK) ? blackBishop : whiteBishop);
                else if (isTypeOf<Knight>(currentUnit))
                    std::wcout << ((currentUnit->getColor() == BLACK) ? blackKnight : whiteKnight);
                else if (isTypeOf<Pawn>(currentUnit))
                    std::wcout << ((currentUnit->getColor() == BLACK) ? blackPawn : whitePawn);
            } else std::wcout << L"   ";

            std::wcout << L"  " << RESET;
        }
        std::wcout << std::endl;
    }
    std::wcout << L"  " << L"    A      B      C      D      E      F      G      H"<< std::endl;

//    std::wcout << std::endl;
//    wchar_t unitSymbol = L' ';
//    for (int rows = 7; rows >= 0; rows--) {
//        for (int line = 0; line <= 2; line++) {
//            for (int column = 0; column <= 7; column++) {
//
//                wchar_t block = ((rows + column) % 2 == 0) ? blackSquare : whiteSquare;
//
//                if (line == 1) {
//                    FieldPtr f = state->getBoard()->getField(std::make_shared<Position>(LetterIndex(column), NumberIndex(rows)));
//                    if (f->getUnit() != nullptr) {
//                        UnitPtr currentUnit = f->getUnit();
//                        unitSymbol = blackBishop;
//                        if (typeid(*currentUnit) == typeid(King))
//                            unitSymbol = currentUnit->getColor() == WHITE ? blackKing : whiteKing;
//                        else if (typeid(*currentUnit) == typeid(Queen))
//                            unitSymbol = currentUnit->getColor() == WHITE ? blackQueen : whiteQueen;
//                        else if (typeid(*currentUnit) == typeid(Rook))
//                            unitSymbol = currentUnit->getColor() == WHITE ? blackRook : whiteRook;
//                        else if (typeid(*currentUnit) == typeid(Bishop))
//                            unitSymbol = currentUnit->getColor() == WHITE ? blackBishop : whiteBishop;
//                        else if (typeid(*currentUnit) == typeid(Knight))
//                            unitSymbol = currentUnit->getColor() == WHITE ? blackKnight : whiteKnight;
//                        else if (typeid(*currentUnit) == typeid(Pawn))
//                            unitSymbol = currentUnit->getColor() == WHITE ? blackPawn : whitePawn;
//                    } else unitSymbol = block;
//                    std::wcout << block << L' ' << unitSymbol << L' ' << block << L' ';
//                } else {
//                    std::wcout << block << L' ' << block << L' ' << block << L' ';
//                }
//            }
//            std::wcout << std::endl;
//        }
//    }
}

void TextUI::endGameScreen(StatePtr state) {
    std::map<Conclusion, wchar_t*> conclusionNames {
            {IN_PROGRESS, L"In Progress"},
            {DRAW, L"Draw"},
            {STALEMATE, L"Stalemate"},
            {WHITE_WINS, L"White Won"},
            {BLACK_WINS, L"Black Won"},
            {FIFTY_MOVES_DRAW, L"Draw by 50 moves rule"},
            {INSUFFICIENT_MATERIAL_DRAW, L"Draw by insufficient material"},
            {AGREED_DRAW, L"Draw by agreement"}
    };

    std::wcout << L"The game has ended.\nConclusion: ";
    std::wcout << (conclusionNames[state->getConclusion()]);
}
