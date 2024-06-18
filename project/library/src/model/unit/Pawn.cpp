#include <iostream>
#include "model/unit/Pawn.h"
#include "model/State.h"
#include "../src/model/util/util.cpp"

std::vector<std::vector<MoveVectorPtr>> Pawn::getBranchesOfPossibleMoveVectors() {
    std::vector<std::vector<MoveVectorPtr>> moves;
    if(getColor() == WHITE){
        moves.push_back(std::vector<MoveVectorPtr> {
                std::make_shared<MoveVector>(0,1),
                std::make_shared<MoveVector>(0,2)
        });
        moves.push_back(std::vector<MoveVectorPtr> {std::make_shared<MoveVector>(-1,1)});
        moves.push_back(std::vector<MoveVectorPtr> {std::make_shared<MoveVector>(1,1)});
    } else if(getColor() == BLACK){
        moves.push_back(std::vector<MoveVectorPtr> {
                std::make_shared<MoveVector>(0,-1),
                std::make_shared<MoveVector>(0,-2)
        });
        moves.push_back(std::vector<MoveVectorPtr> {std::make_shared<MoveVector>(1,-1)});
        moves.push_back(std::vector<MoveVectorPtr> {std::make_shared<MoveVector>(-1,-1)});
    }
    return moves;
}

std::vector<MovePtr> Pawn::getLegalMoves(const StatePtr &state) {
    std::vector<MovePtr> legalMoves;

    FieldPtr currentField = getCurrentField(state);
    PositionPtr currentPosition = currentField->getPosition();

    //Dla każdej gałęzi ruchów (gałąź ruchu to jeden kierunek, np. wieża może się poruszać w górę, dół, lewo, prawo)
    for(std::vector<MoveVectorPtr> moveVectorsBranch : getBranchesOfPossibleMoveVectors()){
        // Dla każdego ruchu w zadanej gałęzi
        for(MoveVectorPtr moveVector : moveVectorsBranch){

            //Jeżeli pozycja istnieje na planszy, czyli nie równa się nullptr
            PositionPtr targetPosition = currentPosition->applyMoveVector(moveVector);
            if(targetPosition == nullptr) continue;

            FieldPtr targetField = state->getBoard()->getField(targetPosition);
            //Jeżeli pion idzie do przodu
            if(targetPosition->getLetterIndex() == currentPosition->getLetterIndex()){
                if(!targetField->isOccupied()){
                    int moveRowOffset = currentPosition->getNumberIndex() - targetPosition->getNumberIndex();
                    if(moveRowOffset == 2 || moveRowOffset == -2){
                        if(!state->hasMoved(shared_from_this())){
                            legalMoves.push_back(std::make_shared<Move>(currentField, targetField));
                        }
                    } else {
                        legalMoves.push_back(std::make_shared<Move>(currentField, targetField));
                    }
                    continue;
                } else break;
            }
            //Jeżeli pion idzie na boki (bicia)
            else {
                //Jeżeli bijemy tam gdzie idziemy
                if(targetField->getUnit() != nullptr){
                    if(targetField->isOccupiedByEnemy(shared_from_this())) {
                        if(!isTypeOf<King>(targetField->getUnit())){
                            MovePtr move = std::make_shared<Move>(currentField, targetField);
                            move->setAction(std::make_shared<Action>(CAPTURE, targetField));
                            legalMoves.push_back(move);
                        }
                    }
                }
                //Jeżeli nie bijemy tam, gdzie idziemy, to sprawdzamy, czy ma miejsce bicie w przelocie
                else {
                    int enPassantRowOffset = (getColor() == WHITE ? -1: 1);
                    MovePtr lastMoveInGame = state->getLastMove();
                    if(lastMoveInGame != nullptr) {
                        if (isTypeOf<Pawn>(lastMoveInGame->getMovedUnit())) {
                            if (lastMoveInGame->getMovedUnit()->getColor() != getColor()) {
                                PositionPtr enemyPawnPos = lastMoveInGame->getTargetField()->getPosition();
                                if (enemyPawnPos->getNumberIndex() == (getColor() == WHITE ? _5 : _4)) {
                                    if (enemyPawnPos->getLetterIndex() == targetPosition->getLetterIndex()) {
                                        if (targetPosition->getNumberIndex() + enPassantRowOffset ==
                                            enemyPawnPos->getNumberIndex()) {
                                            MovePtr move = std::make_shared<Move>(currentField, targetField);
                                            move->setAction(std::make_shared<Action>(CAPTURE,
                                                                                     lastMoveInGame->getTargetField()));
                                            legalMoves.push_back(move);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return legalMoves;
//    std::vector<MovePtr> preLegalMoves = Unit::getLegalMoves(state);
//    std::vector<MovePtr> legalMoves;
//    for(MovePtr move : preLegalMoves)
//    {
//        if(move->getTargetField()->getPosition()->getLetterIndex() != move->getCurrentField()->getPosition()->getLetterIndex()){
//            if(move->getTargetField()->isOccupied()){
//                if(move->getTargetField()->getUnit()->getColor() != getColor()){
//                    legalMoves.push_back(move);
//                }
//            }
//        } else {
//            if(!move->getTargetField()->isOccupied()){
//                legalMoves.push_back(move);
//            }
//        }
//    }
//
//    return legalMoves;
}

std::vector<MovePtr> Pawn::getAttackCoverage(const StatePtr &state) {
    std::vector<MovePtr> generalizedAttackCoverage = Unit::getAttackCoverage(state);
    std::vector<MovePtr> pawnAttackCoverage;
    for(const MovePtr& move : generalizedAttackCoverage) {
        if(move->getTargetField()->getPosition()->getLetterIndex() != move->getCurrentField()->getPosition()->getLetterIndex()){
            pawnAttackCoverage.push_back(move);
        }
    }
    return pawnAttackCoverage;
}

Pawn::Pawn(PlayerColor color) : Unit(color) {
    promotionRow = color == WHITE ? _8 : _1;
}
