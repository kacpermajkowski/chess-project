#include <iostream>
#include "model/UnitDir/Pawn.h"
#include "model/State.h"

std::vector<std::vector<MoveVectorPtr>> Pawn::getPossibleMoves() {
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
    for(std::vector<MoveVectorPtr> moveVectorsBranch : getPossibleMoves()){
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
                        //Jeżeli pole jest zajęte, to nie możemy już poruszyć się
                        //na nie ani pola znajdujące się za nim, więc przerywamy badanie gałęzi.
                    }
                    continue;
                } else break;
            }
            //Jeżeli pion idzie na boki (bicia)
            else {
                //Jeżeli bijemy tam gdzie idziemy
                if(targetField->getUnit() != nullptr){
                    MovePtr move = std::make_shared<Move>(currentField, targetField);
                    move->setAction(std::make_shared<Action>(CAPTURE, targetField));
                    legalMoves.push_back(move);
                }
                //Jeżeli nie bijemy tam, gdzie idziemy, to sprawdzamy, czy ma miejsce bicie w przelocie
                else {
                    int enPassantRowOffset = (getColor() == WHITE) ? -1 : 1;

                    FieldPtr actionField = state->getBoard()->getField(
                            std::make_shared<Position>(
                                    currentPosition->getLetterIndex(),
                                    NumberIndex(currentPosition->getNumberIndex()+enPassantRowOffset)
                            )
                    );
                    //Jeżeli pod polem, na store się ruszamy jest niepuste pole
                    if(actionField != nullptr){
                        if(actionField->isOccupied()){
                            UnitPtr actionUnit = actionField->getUnit();
                            //Jezeli jest to wrogi pion
                            if(actionUnit->getColor() != getColor()){
                                //Jeżeli pod polem znajduje się pion
                                if(typeid(actionUnit) == typeid(Pawn)){
                                    //Jeżeli pion poruszył się w poprzednim ruchu
                                    if(state->getLastMove()->getMovedUnit() == actionUnit){
                                        PositionPtr startPos = state->getLastMove()->getCurrentField()->getPosition();
                                        int moveRowOffset = startPos->getNumberIndex() - actionField->getPosition()->getNumberIndex();
                                        if(moveRowOffset == 2 || moveRowOffset == -2){
                                            //TODO: catch exception from Action
                                            try {
                                                MovePtr move = std::make_shared<Move>(currentField, targetField);
                                                move->setAction(std::make_shared<Action>(CAPTURE, actionField));
                                                legalMoves.push_back(move);
                                            } catch (std::invalid_argument& e ){
                                                std::wcout << e.what();
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

std::vector<MovePtr> Pawn::getAttackCoverage(StatePtr state) {
    std::vector<MovePtr> preLegalMoves = Unit::getLegalMovesNoCheck(state);
    std::vector<MovePtr> legalMoves;
    for(const MovePtr& move : preLegalMoves) {
        if(move->getTargetField()->getPosition()->getLetterIndex() != move->getCurrentField()->getPosition()->getLetterIndex()){
            legalMoves.push_back(move);
        }
    }
    return legalMoves;
}

Pawn::Pawn(PlayerColor color) : Unit(color) {
    promotionRow = color == WHITE ? _8 : _1;
}
