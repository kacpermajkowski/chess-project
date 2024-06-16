#include <list>
#include "model/unit/King.h"
#include "model/State.h"
#include "model/unit/Rook.h"
#include "../src/model/util/util.cpp"

King::King(PlayerColor color) : Unit(color) {}

std::vector<std::vector<MoveVectorPtr>> King::getBranchesOfPossibleMoveVectors() {
    std::vector<std::vector<MoveVectorPtr>> moves;
    for(int i = -1; i <=1; i++){
        for(int j = -1; j <=1; j++){
            if(!(i == 0 && j == 0)) {
                moves.push_back(std::vector<MoveVectorPtr> {std::make_shared<MoveVector>(i, j)});
            }
        }
    }
    return moves;
}

std::vector<MovePtr> King::getLegalMoves(const StatePtr &state) {
    std::vector<MovePtr> preLegalMoves = Unit::getLegalMovesAssumeNoCheck(state);
    std::vector<MovePtr> legalMoves;

    //TODO: Add castling
    for(const MovePtr& move : preLegalMoves){
        if(!state->isAttacked(move->getTargetField(), getColor()))
            legalMoves.push_back(move);
    }

    if(!state->hasMoved(shared_from_this())){
        if(!state->isCheck(getColor())) {
            for (const auto &rookField: state->getBoard()->getFields()) {
                UnitPtr unit = rookField->getUnit();
                if (unit == nullptr) continue;
                if (unit->getColor() != this->getColor()) continue;
                if (!isTypeOf<Rook>(unit)) continue;
                if (state->hasMoved(unit)) continue;
                BoardPtr board = state->getBoard();
                std::list<FieldPtr> fieldsBetweenKingAndRook;
                CastleType castleType;
                if (rookField->getPosition()->getLetterIndex() == A) {
                    castleType = LONG_CASTLE;
                    fieldsBetweenKingAndRook = std::list<FieldPtr>{
                            board->getField(std::make_shared<Position>(B, rookField->getPosition()->getNumberIndex())),
                            board->getField(std::make_shared<Position>(C, rookField->getPosition()->getNumberIndex())),
                            board->getField(std::make_shared<Position>(D, rookField->getPosition()->getNumberIndex()))
                    };
                } else if (rookField->getPosition()->getLetterIndex() == H) {
                    castleType = SHORT_CASTLE;
                    fieldsBetweenKingAndRook = std::list<FieldPtr>{
                            board->getField(std::make_shared<Position>(F, rookField->getPosition()->getNumberIndex())),
                            board->getField(std::make_shared<Position>(G, rookField->getPosition()->getNumberIndex()))
                    };
                }
                bool isCastlePossible = true;
                for(auto fieldBetween : fieldsBetweenKingAndRook){
                    if(fieldBetween->isOccupied()) isCastlePossible = false;
                    if(state->isAttacked(fieldBetween, getColor())) isCastlePossible = false;
                    if(isCastlePossible == false) break;
                }
                if(isCastlePossible){
                    FieldPtr currentField = state->getBoard()->getField(shared_from_this());
                    FieldPtr targetField;
                    LetterIndex targetColumn;
                    if(castleType == LONG_CASTLE){
                        targetColumn = C;
                    } else {
                        targetColumn = G;
                    }
                    targetField = state->getBoard()->getField(std::make_shared<Position>(targetColumn, currentField->getPosition()->getNumberIndex()));
                    MovePtr move = std::make_shared<Move>(currentField, targetField);
                    ActionPtr action = std::make_shared<Action>(CASTLE, rookField);
                    move->setAction(action);
                    legalMoves.push_back(move);
                }
            }
        }
    }

    return legalMoves;
}

