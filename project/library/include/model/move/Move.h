#ifndef CHESSPROJECT_MOVE_H
#define CHESSPROJECT_MOVE_H

#include "model/Position.h"
#include "model/Field.h"
#include "Action.h"

class Move : public std::enable_shared_from_this<Move> {
private:
    FieldPtr currentField;
    FieldPtr targetField;
    UnitPtr movedUnit;
    ActionPtr action = nullptr;
public:
    Move(const FieldPtr currentField, const FieldPtr targetField);

    virtual ~Move();

    const UnitPtr getMovedUnit() const;

    const FieldPtr getCurrentField() const;
    const FieldPtr getTargetField() const;
    const ActionPtr getAction() const;

    void setAction(const ActionPtr action);

};


#endif //CHESSPROJECT_MOVE_H
