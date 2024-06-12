#ifndef CHESSPROJECT_MOVE_H
#define CHESSPROJECT_MOVE_H

#include "model/Position.h"
#include "model/Field.h"
#include "Action.h"

class Move {
private:
    FieldPtr currentField;
    FieldPtr targetField;
    UnitPtr movedUnit;
    ActionPtr action = nullptr;
public:
    Move(const UnitPtr movedUnit, const FieldPtr currentField, const FieldPtr targetField);

    virtual ~Move();

    const UnitPtr getMovedUnit() const;

    const FieldPtr getStartingPosition() const;
    const FieldPtr getTargetPosition() const;
    const ActionPtr getAction() const;

    void setAction(const ActionPtr action);

};


#endif //CHESSPROJECT_MOVE_H
