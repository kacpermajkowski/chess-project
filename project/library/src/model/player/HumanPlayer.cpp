#include <cstdlib>
#include <iostream>
#include <limits>
#include "model/player/HumanPlayer.h"
#include "model/exceptions/StateIntegrityException.h"
#include "model/Game.h"
#include <map>

using namespace std;

HumanPlayer::HumanPlayer(PlayerColor color) : Player(color) {
    srand(time(nullptr));
}

LetterIndex getLetterIndexFrom(wchar_t c){
    switch(c){
        case L'A':
        case L'a':
            return A;
        case L'B':
        case L'b':
            return B;
        case L'C':
        case L'c':
            return C;
        case L'D':
        case L'd':
            return D;
        case L'E':
        case L'e':
            return E;
        case L'F':
        case L'f':
            return F;
        case L'G':
        case L'g':
            return G;
        case L'H':
        case L'h':
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

MovePtr HumanPlayer::chooseAMove(const GamePtr &game) {
    UIPtr ui = game->getUI();
    vector<MovePtr> legalMoves = game->getState()->getLegalMoves();
    if(!legalMoves.empty()){
        while(true){
            int moveNumber = (rand() % legalMoves.size());
            wchar_t fromLetter = L'A' + legalMoves[moveNumber]->getCurrentField()->getPosition()->getLetterIndex();
            wchar_t fromNumber = L'1' + legalMoves[moveNumber]->getCurrentField()->getPosition()->getNumberIndex();
            wchar_t toLetter = L'A' + legalMoves[moveNumber]->getTargetField()->getPosition()->getLetterIndex();
            wchar_t toNumber = L'1' + legalMoves[moveNumber]->getTargetField()->getPosition()->getNumberIndex();

            wcout << endl << L"Grasz jako " << (getColor() == WHITE ? L"BIAŁE" : L"CZARNE") << endl;
            wcout << L"Wybierz ruch (np. " << fromLetter << fromNumber << toLetter << toNumber << L"): ";

            map<wchar_t,wchar_t> letterRanges = map<wchar_t,wchar_t>{{L'a', L'h'}, {L'A', L'H'}};
            LetterIndex moveFromColumnIndex = getLetterIndexFrom(ui->getFromUser(letterRanges));
            NumberIndex moveFromRowIndex = getNumberIndexFrom(ui->getFromUser(L'1', L'8'));
            LetterIndex moveToColumnIndex = getLetterIndexFrom(ui->getFromUser(letterRanges));
            NumberIndex moveToRowIndex = getNumberIndexFrom(ui->getFromUser(L'1', L'8'));

            wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
            wcout << endl;

            PositionPtr from = make_shared<Position>(moveFromColumnIndex, moveFromRowIndex);
            PositionPtr to = make_shared<Position>(moveToColumnIndex, moveToRowIndex);

            for(auto move : legalMoves){
                PositionPtr targetPosition = move->getTargetField()->getPosition();
                PositionPtr currentPosition = move->getCurrentField()->getPosition();
                if(currentPosition->equals(from) && targetPosition->equals(to))
                    return move;
            }

            wcout << L"Podany ruch nie jest dozwolony. Wybierz inny. ";
        }
    } throw StateIntegrityException("There should be at least one legal move if the game has not concluded yet.");
}



