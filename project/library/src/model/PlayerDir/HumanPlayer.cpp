#include <cstdlib>
#include <iostream>
#include "model/PlayerDir/HumanPlayer.h"
#include "model/exceptions/StateIntegrityException.h"

using namespace std;

HumanPlayer::HumanPlayer(PlayerColor color) : Player(color) {}

LetterIndex getLetterIndexFrom(wchar_t c){
    switch(c){
        case L'A':
            return A;
        case L'B':
            return B;
        case L'C':
            return C;
        case L'D':
            return D;
        case L'E':
            return E;
        case L'F':
            return F;
        case L'G':
            return G;
        case L'H':
            return H;
        default:
            throw invalid_argument("Provided wchar_t does not correspond to any LetterIndex");
    }
}

NumberIndex getNumberIndexFrom(wchar_t c){
    switch(c){
        case L'1':
            return _1;
        case L'2':
            return _2;
        case L'3':
            return _3;
        case L'4':
            return _4;
        case L'5':
            return _5;
        case L'6':
            return _6;
        case L'7':
            return _7;
        case L'8':
            return _8;
        default:
            throw invalid_argument("Provided wchar_t does not correspond to any NumberIndex");
    }
}

wchar_t getFromUser(wchar_t begin, wchar_t end){
    wchar_t input;
    while(true){
        wcin >> input;
        if(input < begin || input > end){
            wcout << endl << "Nieprawidłowa wartość. Wybierz ponownie: ";
        } else break;
    }
    wcout << endl;
    return input;
}

MovePtr HumanPlayer::chooseAMove(std::vector<MovePtr> legalMoves) {
    //TODO: Get input from player;
    if(!legalMoves.empty()){
        while(true){
            std::wcout << std::endl << L"Wybierz kolumne, z której chcesz się ruszyć: (A-H): ";
            wchar_t moveFromColumn = getFromUser(L'A', L'H');
            LetterIndex moveFromColumnIndex = getLetterIndexFrom(moveFromColumn);

            std::wcout << L"Wybierz rząd, z którego chcesz się ruszyć: (1-8): ";
            wchar_t moveFromRow = getFromUser(L'1', L'8');
            NumberIndex moveFromRowIndex = getNumberIndexFrom(moveFromRow);

            PositionPtr from = make_shared<Position>(moveFromColumnIndex, moveFromRowIndex);


            std::wcout << L"Wybierz kolumne, do której chcesz się ruszyć: (A-H): ";
            wchar_t moveToColumn = getFromUser(L'A', L'H');
            LetterIndex moveToColumnIndex = getLetterIndexFrom(moveToColumn);

            std::wcout << L"Wybierz rząd, do którego chcesz się ruszyć: (1-8): ";
            wchar_t moveToRow = getFromUser(L'1', L'8');
            NumberIndex moveToRowIndex = getNumberIndexFrom(moveToRow);

            PositionPtr to = make_shared<Position>(moveToColumnIndex, moveToRowIndex);

            for(auto move : legalMoves){
                PositionPtr targetPostion = move->getTargetField()->getPosition();
                PositionPtr currentPostion = move->getCurrentField()->getPosition();
                if(currentPostion->equals(from) && targetPostion->equals(to))
                    return move;
            }

            std::wcout << L"Podany ruch nie jest dozwolony. Wybierz inny. ";
        }
    } throw StateIntegrityException("There should be at least one legal move if the game has not concluded yet.");
}



