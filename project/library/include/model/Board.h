#ifndef CHESSPROJECT_BOARD_H
#define CHESSPROJECT_BOARD_H

#include <vector>
#include "Field.h"

class Board : public std::enable_shared_from_this<Board>{
private:
    std::vector<FieldPtr> fields;
public:
    explicit Board();
    Board(std::vector<FieldPtr> fields);

    FieldPtr getField(PositionPtr position) const;
    FieldPtr getField(UnitPtr unit) const;

    const std::vector<FieldPtr> &getFields() const;
    std::vector<UnitPtr> getUnits() const;
private:
    void initlializeWithEmptyFields();
    static std::vector<FieldPtr> fillMissingFields(std::vector<FieldPtr> fieldsToFill) ;
};


#endif //CHESSPROJECT_BOARD_H
