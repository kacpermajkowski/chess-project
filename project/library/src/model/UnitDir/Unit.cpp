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
        legalMoves = getLegalMovesAssumeNoCheck(state);
    }

    return legalMoves;
}

std::vector<MovePtr> Unit::getLegalMovesAssumeNoCheck(const StatePtr& state) {
    FieldPtr currentField = getCurrentField(state);
    PositionPtr currentPosition = currentField->getPosition();

    std::vector<std::vector<MovePtr>> moveBranches = getMoveBranchesIncludeOccupiedFields(state);

    std::vector<MovePtr> legalMoves;
    for(const auto& moveBranch : moveBranches){
        for(const auto& move : moveBranch){
            if(!move->getTargetField()->isOccupiedByAlly(color)){
                legalMoves.push_back(move);
            }
        }
    }
    return legalMoves;
}

std::vector<std::vector<PositionPtr>> Unit::generatePositionBranches(const StatePtr &state)
{
    FieldPtr currentField = getCurrentField(state);
    PositionPtr currentPosition = currentField->getPosition();

    std::vector<std::vector<PositionPtr>> positionBranches;

    //Dla każdej gałęzi ruchów (gałąź ruchu to jeden kierunek, np. wieża może się poruszać w górę, dół, lewo, prawo)
    for(const std::vector<MoveVectorPtr>& moveVectorsBranch : getBranchesOfPossibleMoveVectors()){
        std::vector<PositionPtr> positionBranch;
        // Dla każdego ruchu w zadanej gałęzi
        for(const MoveVectorPtr& moveVector : moveVectorsBranch) {
            //Tworzymy nową pozycję po przesunięciu o wektor ruchu
            PositionPtr targetPosition = currentPosition->applyMoveVector(moveVector);
            if(targetPosition != nullptr)
                positionBranch.push_back(targetPosition);
        }
        positionBranches.push_back(positionBranch);
    }

    return positionBranches;
}

std::vector<MovePtr> Unit::getCheckBreakingMoves(const StatePtr& state) {
    return std::vector<MovePtr>();
}

FieldPtr Unit::getCurrentField(const StatePtr& state) {
    return state->getBoard()->getField(shared_from_this());
}

std::vector<MovePtr> Unit::getAttackCoverage(const StatePtr &state) {
    std::vector<MovePtr> attackCoverage;

    for(const auto& moveBranch : getMoveBranchesIncludeOccupiedFields(state)){
        for(const auto& move : moveBranch){
            attackCoverage.push_back(move);
        }
    }

    return attackCoverage;
}

std::vector<std::vector<MovePtr>>
Unit::getMoveBranchesIncludeOccupiedFields(const StatePtr &state) {
    std::vector<std::vector<MovePtr>> moveBranches;

    FieldPtr currentField = getCurrentField(state);

    for(const auto& positionBranch : generatePositionBranches(state)){
        std::vector<MovePtr> moveBranch;
        for(const auto& targetPosition : positionBranch){
            FieldPtr targetField = state->getBoard()->getField(targetPosition);

            if(targetField->isOccupiedByEnemy(shared_from_this())){
                if(!isTypeOf<King>(targetField->getUnit())){
                    std::shared_ptr<Move> move = std::make_shared<Move>(currentField, targetField);
                    move->setAction(std::make_shared<Action>(CAPTURE, targetField));
                    moveBranch.push_back(move);
                }
            } else {
                moveBranch.push_back(std::make_shared<Move>(currentField, targetField));
            }

            if(targetField->isOccupied()){
                break;
            }
        }
        moveBranches.push_back(moveBranch);
    }

    return moveBranches;
}



