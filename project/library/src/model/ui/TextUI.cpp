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
#include "model/PlayerDir/HumanPlayer.h"
#include "model/PlayerDir/ComputerPlayer.h"

#include <locale>
#include <codecvt>
#include <string>
#include <map>

using namespace std;

void TextUI::update(StatePtr state) {
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

    wcout << endl;
    for(int rows = 7; rows >= 0; rows--){
        wcout << (wchar_t)(L'1'+rows) << L" ";
        for(int column = 0; column <= 7; column++){
            if((rows + column) % 2 == 0){
                wcout << BLACK_BG;
            } else{
                wcout << WHITE_BG;
            }

            wcout << L"  ";
            FieldPtr f = state->getBoard()->getField(make_shared<Position>(LetterIndex(column), NumberIndex(rows)));
            if (f->getUnit() != nullptr) {
                UnitPtr currentUnit = f->getUnit();
                //Font color
                wcout << ((currentUnit->getColor() == BLACK) ? BLACK_FG : WHITE_FG);
                //Icon
                if (isTypeOf<King>(currentUnit))
                    wcout << ((currentUnit->getColor() == BLACK) ? blackKing : whiteKing);
                else if (isTypeOf<Queen>(currentUnit))
                    wcout << ((currentUnit->getColor() == BLACK) ? blackQueen : whiteQueen);
                else if (isTypeOf<Rook>(currentUnit))
                    wcout << ((currentUnit->getColor() == BLACK) ? blackRook : whiteRook);
                else if (isTypeOf<Bishop>(currentUnit))
                    wcout << ((currentUnit->getColor() == BLACK) ? blackBishop : whiteBishop);
                else if (isTypeOf<Knight>(currentUnit))
                    wcout << ((currentUnit->getColor() == BLACK) ? blackKnight : whiteKnight);
                else if (isTypeOf<Pawn>(currentUnit))
                    wcout << ((currentUnit->getColor() == BLACK) ? blackPawn : whitePawn);
            } else wcout << L"   ";

            wcout << L"  " << RESET;
        }
        wcout << endl;
    }
    wcout << L"  " << L"    A      B      C      D      E      F      G      H"<< endl;
}

void TextUI::endGameScreen(StatePtr state) {
    map<Conclusion, wchar_t*> conclusionNames {
            {IN_PROGRESS, L"In Progress"},
            {DRAW, L"Draw"},
            {STALEMATE, L"Stalemate"},
            {WHITE_WINS, L"White Won"},
            {BLACK_WINS, L"Black Won"},
            {FIFTY_MOVES_DRAW, L"Draw by 50 moves rule"},
            {INSUFFICIENT_MATERIAL_DRAW, L"Draw by insufficient material"},
            {AGREED_DRAW, L"Draw by agreement"}
    };

    wcout << L"The game has ended.\nConclusion: ";
    wcout << (conclusionNames[state->getConclusion()]);
}

wchar_t TextUI::getFromUser(wchar_t begin, wchar_t end){
    wchar_t input;
    while(true){
        wcin >> input;
        if(input < begin || input > end){
            wcout << "Nieprawidlowa wartosc. Wybierz ponownie: ";
        } else break;
    }
    return input;
}

PlayerPtr TextUI::getPlayerByUserChoice(PlayerColor color){
    switch(getFromUser(L'1', L'2')){
        case L'1':
            return make_shared<HumanPlayer>(color);
        case L'2':
            return make_shared<ComputerPlayer>(color);
    }
    throw invalid_argument("Input validation has failed and player type input was out of range");
}

TextUI::TextUI() {
    locale::global(locale("en_US.UTF-8"));
    wcout.imbue(locale());
}
