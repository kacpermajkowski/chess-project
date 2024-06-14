#include <map>
#include <utility>
#include "model/Board.h"
#include "model/UnitDir/Rook.h"
#include "model/UnitDir/Knight.h"
#include "model/UnitDir/Bishop.h"
#include "model/UnitDir/King.h"
#include "model/UnitDir/Queen.h"
#include "model/UnitDir/Pawn.h"

FieldPtr Board::getField(PositionPtr position) const {
    for(FieldPtr f : fields){
        if(f->getPosition()->getLetterIndex() == position->getLetterIndex()){
            if(f->getPosition()->getNumberIndex() == position->getNumberIndex()){
                return f;
            }
        }
    }
    return nullptr;
}

FieldPtr Board::getField(UnitPtr unit) const {
    for(FieldPtr f : fields){
        if(f->getUnit() == unit){
            return f;
        }
    }
    return nullptr;
}

const std::vector<FieldPtr> &Board::getFields() const {
    return fields;
}

Board::Board() {
    //TODO: Initialize fields
    initlializeWithEmptyFields();
    std::map<PositionPtr, UnitPtr> defaults{
            {std::make_shared<Position>(A, _1), std::make_shared<Rook>(WHITE)},
            {std::make_shared<Position>(B, _1), std::make_shared<Knight>(WHITE)},
            {std::make_shared<Position>(C, _1), std::make_shared<Bishop>(WHITE)},
            {std::make_shared<Position>(D, _1), std::make_shared<Queen>(WHITE)},
            {std::make_shared<Position>(E, _1), std::make_shared<King>(WHITE)},
            {std::make_shared<Position>(F, _1), std::make_shared<Bishop>(WHITE)},
            {std::make_shared<Position>(G, _1), std::make_shared<Knight>(WHITE)},
            {std::make_shared<Position>(H, _1), std::make_shared<Rook>(WHITE)},

            {std::make_shared<Position>(A, _2), std::make_shared<Pawn>(WHITE)},
            {std::make_shared<Position>(B, _2), std::make_shared<Pawn>(WHITE)},
            {std::make_shared<Position>(C, _2), std::make_shared<Pawn>(WHITE)},
            {std::make_shared<Position>(D, _2), std::make_shared<Pawn>(WHITE)},
            {std::make_shared<Position>(E, _2), std::make_shared<Pawn>(WHITE)},
            {std::make_shared<Position>(F, _2), std::make_shared<Pawn>(WHITE)},
            {std::make_shared<Position>(G, _2), std::make_shared<Pawn>(WHITE)},
            {std::make_shared<Position>(H, _2), std::make_shared<Pawn>(WHITE)},

            {std::make_shared<Position>(A, _8), std::make_shared<Rook>(BLACK)},
            {std::make_shared<Position>(B, _8), std::make_shared<Knight>(BLACK)},
            {std::make_shared<Position>(C, _8), std::make_shared<Bishop>(BLACK)},
            {std::make_shared<Position>(D, _8), std::make_shared<Queen>(BLACK)},
            {std::make_shared<Position>(E, _8), std::make_shared<King>(BLACK)},
            {std::make_shared<Position>(F, _8), std::make_shared<Bishop>(BLACK)},
            {std::make_shared<Position>(G, _8), std::make_shared<Knight>(BLACK)},
            {std::make_shared<Position>(H, _8), std::make_shared<Rook>(BLACK)},

            {std::make_shared<Position>(A, _7), std::make_shared<Pawn>(BLACK)},
            {std::make_shared<Position>(B, _7), std::make_shared<Pawn>(BLACK)},
            {std::make_shared<Position>(C, _7), std::make_shared<Pawn>(BLACK)},
            {std::make_shared<Position>(D, _7), std::make_shared<Pawn>(BLACK)},
            {std::make_shared<Position>(E, _7), std::make_shared<Pawn>(BLACK)},
            {std::make_shared<Position>(F, _7), std::make_shared<Pawn>(BLACK)},
            {std::make_shared<Position>(G, _7), std::make_shared<Pawn>(BLACK)},
            {std::make_shared<Position>(H, _7), std::make_shared<Pawn>(BLACK)},
    };

    for(const auto& kv : defaults){
        FieldPtr field = getField(kv.first);
        if(field != nullptr){
            field->setUnit(kv.second);
        }

    }

}

Board::Board(std::vector<FieldPtr> fields) {
    this->fields = fillMissingFields(std::move(fields));
}

void Board::initlializeWithEmptyFields() {
    this->fields = fillMissingFields(std::vector<FieldPtr> ());
}

std::vector<FieldPtr> Board::fillMissingFields(std::vector<FieldPtr> fieldsToFill) {
    for(int i = 0; i <= 7; i++){
        for(int j = 0; j <= 7; j++){
            PositionPtr pos = std::make_shared<Position>(LetterIndex(j), NumberIndex(i));
            FieldPtr field;
            for(const auto& f : fieldsToFill){
                if(f->getPosition()->equals(pos)){
                    field = f;
                    break;
                }
            }
            if(field == nullptr){
                fieldsToFill.push_back(std::make_shared<Field>(pos, nullptr));
            }
        }
    }
    return fieldsToFill;
}

std::vector<UnitPtr> Board::getUnits() const {
    std::vector<UnitPtr> playingUnits;
    for(const auto &field : fields){
        UnitPtr unit = field->getUnit();
        if(unit != nullptr) playingUnits.push_back(unit);
    }
    return playingUnits;
}


