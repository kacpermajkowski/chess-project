#include "model/UnitDir/Unit.h"
#include "model/State.h"

Unit::Unit(PlayerColor color) : color(color) {};
Unit::~Unit() {};

PlayerColor Unit::getColor() const {
    return color;
}

std::vector<MovePtr> Unit::getLegalMoves(StatePtr state) const {
    std::vector<MovePtr> legalMoves;
    if(state->isCheck()){
        legalMoves = getCheckBreakingMoves(state);
    } else {
        legalMoves = getLegalMovesNoCheck(state);
    }

    return legalMoves;
}

std::vector<MovePtr> Unit::getLegalMovesNoCheck(StatePtr state) const{
    std::vector<MovePtr> legalMoves;

    FieldPtr field = getCurrentField(state);
    PositionPtr currentPosition = field->getPosition();

    //Dla każdej gałęzi ruchów (gałąź ruchu to jeden kierunek, np. wieża może się poruszać w górę, dół, lewo, prawo)
    for(std::vector<MoveVectorPtr> moveVectorsBranch : getPossibleMoves()){
        // Dla każdego ruchu w zadanej gałęzi
        for(MoveVectorPtr moveVector : moveVectorsBranch){

            //Jeżeli pozycja istnieje na planszy, czyli nie równa się nullptr
            PositionPtr targetPosition = currentPosition->applyMoveVector(moveVector);
            if(targetPosition == nullptr) continue;

            //Jeżeli pole nie jest zajęte, to możemy się tam ruszyć
            FieldPtr targetField = state->getBoard()->getField(targetPosition);
            if(!targetField->isOccupied()){
                legalMoves.push_back(new Move((UnitPtr)this, field, targetField));
            }

            //Jeżeli jest zajęte, ale przez przeciwnika, to możemy się tam ruszyć i zbić
            if(targetField->isOccupiedByEnemy((UnitPtr) this)){
                MovePtr move = new Move((UnitPtr)this, field, targetField);
                move->setAction(new Action(TAKE, targetField));
                legalMoves.push_back(move);
            }

            //W każdym przypadku, jeżeli pole jest zajęte, to nie możemy już poruszyć się
            //na pola znajdujące się za nim, więc przerywamy badanie gałęzi.
            if(targetField->isOccupied()) break;
        }
    }
    return legalMoves;
}

std::vector<MovePtr> Unit::getCheckBreakingMoves(StatePtr state) const {
    return std::vector<MovePtr>();
}

FieldPtr Unit::getCurrentField(StatePtr state) const{
    return state->getBoard()->getField((UnitPtr)this);
}


