#include <stdexcept>
#include <iostream>
#include "model/UnitDir/Unit.h"
#include "model/State.h"
#include "../src/model/util/util.cpp"

Unit::Unit(PlayerColor color) : color(color) {};
Unit::~Unit() = default;

PlayerColor Unit::getColor() {
    return color;
}

std::vector<MovePtr> Unit::getLegalMoves(const StatePtr &state) {
    std::vector<MovePtr> legalMoves;
    if(state->isCheck(color)){
        legalMoves = getCheckBreakingMoves(state);
    } else {
        legalMoves = getLegalMovesNoCheck(state);
    }

    return legalMoves;
}

std::vector<MovePtr> Unit::getLegalMovesNoCheck(const StatePtr& state) {
    std::vector<MovePtr> legalMoves;

    FieldPtr currentField = getCurrentField(state);
    PositionPtr currentPosition = currentField->getPosition();

    //Dla każdej gałęzi ruchów (gałąź ruchu to jeden kierunek, np. wieża może się poruszać w górę, dół, lewo, prawo)
    for(const std::vector<MoveVectorPtr>& moveVectorsBranch : getPossibleMoves()){
        // Dla każdego ruchu w zadanej gałęzi
        for(const MoveVectorPtr& moveVector : moveVectorsBranch){

            //Tworzymy nową pozycję po przesunięciu o wektor ruchu
            PositionPtr targetPosition = currentPosition->applyMoveVector(moveVector);
            //Jeżeli pozycja istnieje na planszy, czyli nie równa się nullptr
            if(targetPosition == nullptr) continue;

            //Jeżeli pole nie jest zajęte, to możemy się tam ruszyć
            FieldPtr targetField = state->getBoard()->getField(targetPosition);
            if(!targetField->isOccupied()){
                legalMoves.push_back(std::make_shared<Move>(currentField, targetField));
                continue;
            }
            //Jeżeli jest zajęte, ale przez przeciwnika, to możemy się tam ruszyć i zbić
            else if(targetField->isOccupiedByEnemy(shared_from_this())){
                if(!isTypeOf<King>(targetField->getUnit())){
                    try{
                        //TODO: catch exception from Action
                        std::shared_ptr<Move> move = std::make_shared<Move>(currentField, targetField);
                        move->setAction(std::make_shared<Action>(CAPTURE, targetField));
                        legalMoves.push_back(move);
                        break;
                    } catch (std::invalid_argument& e ){
                        std::wcout << e.what() << " <-- unit.getLegalMovesNoCheck()";
                    }
                }
            }

            //W każdym przypadku, jeżeli pole jest zajęte, to nie możemy już poruszyć się
            //na pola znajdujące się za nim, więc przerywamy badanie gałęzi.
            if(targetField->isOccupied()){
                break;
            }
        }
    }
    return legalMoves;
}

std::vector<MovePtr> Unit::getCheckBreakingMoves(const StatePtr& state) {
    return std::vector<MovePtr>();
}

FieldPtr Unit::getCurrentField(const StatePtr& state) {
    return state->getBoard()->getField(shared_from_this());
}

std::vector<MovePtr> Unit::getAttackCoverage(StatePtr state) {
    return Unit::getLegalMovesNoCheck(state);
}


