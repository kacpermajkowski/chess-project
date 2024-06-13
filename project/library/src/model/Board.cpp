#include "model/Board.h"

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
}

Board::Board(std::vector<FieldPtr> fields) {
    for(int i = 0; i <= 7; i++){
        for(int j = 0; j <= 7; j++){
            PositionPtr pos = std::make_shared<Position>(LetterIndex(j), NumberIndex(i));
            FieldPtr field = getField(pos);
            if(field == nullptr){
                fields.push_back(std::make_shared<Field>(pos, nullptr));
            }
        }
    }
    this->fields = fields;
}

