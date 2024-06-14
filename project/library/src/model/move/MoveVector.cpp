//
// Created by user on 11.06.2024.
//

#include "model/move/MoveVector.h"

int MoveVector::getRowOffset() const {
    return rowOffset;
}

int MoveVector::getColumnOffset() const {
    return columnOffset;
}

MoveVector::MoveVector(const int columnOffset, const int rowOffset) : rowOffset(rowOffset),
                                                                      columnOffset(columnOffset) {}
