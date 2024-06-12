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

