#include "model/UnitDir/Unit.h"
#include "model/State.h"

Unit::Unit(PlayerColor color) : color(color) {};
Unit::~Unit() {};

PlayerColor Unit::getColor() const {
    return color;
}

std::vector<MovePtr> Unit::getLegalMoves(const StatePtr state) {
    std::vector<MovePtr> legalMoves;
    if(state->isCheck()){
        legalMoves = getCheckBreakingMoves(state);
    } else {
        legalMoves = getLegalMovesNoCheck(state);
    }

    return legalMoves;
}

std::vector<MovePtr> Unit::getLegalMovesNoCheck(const StatePtr state) {
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

            //Jeżeli pole nie jest zajęte, to możemy się tam ruszyć
            FieldPtr targetField = state->getBoard()->getField(targetPosition);
            if(!targetField->isOccupied()){
                legalMoves.push_back(std::make_shared<Move>(shared_from_this(), currentField, targetField));
            }

            //Jeżeli jest zajęte, ale przez przeciwnika, to możemy się tam ruszyć i zbić
            if(targetField->isOccupiedByEnemy(shared_from_this())){
                std::shared_ptr<Move> move = std::make_shared<Move>(shared_from_this(), currentField, targetField);
                move->setAction(std::make_shared<Action>(CAPTURE, targetField));
                legalMoves.push_back(move);
            }

            //W każdym przypadku, jeżeli pole jest zajęte, to nie możemy już poruszyć się
            //na pola znajdujące się za nim, więc przerywamy badanie gałęzi.
            if(targetField->isOccupied()) break;
        }
    }
    return legalMoves;
}

std::vector<MovePtr> Unit::getCheckBreakingMoves(const StatePtr state) const {
    return std::vector<MovePtr>();
}

FieldPtr Unit::getCurrentField(const StatePtr state) {
    return state->getBoard()->getField(shared_from_this());
}


