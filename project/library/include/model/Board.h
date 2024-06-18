#ifndef CHESSPROJECT_BOARD_H
#define CHESSPROJECT_BOARD_H

#include <vector>
#include "Field.h"
#include "model/unit/King.h"
#include <algorithm>

/**
 * @brief Board class represents a game board containing fields
 */
class Board : public std::enable_shared_from_this<Board>{
private:
    std::vector<FieldPtr> fields; ///< Vector containing pointers to all fields on the board
public:
    /**
     * @brief Constructor that initializes board with default chess pieces
     */
    explicit Board();

    /**
     * @brief Constructor that initializes the board with given fields
     * @param fields Vector of FieldPtr objects representing the initial state of the board
     */
    Board(std::vector<FieldPtr> fields);

    /**
     * @param position Pointer to the position of the field
     * @return Pointer to the Field object at the specified position, or nullptr if not found
     */
    FieldPtr getField(PositionPtr position) const;

    /**
     * @param unit Pointer to the unit object
     * @return Pointer to the Field object containing the specified unit, or nullptr if not found
     */
    FieldPtr getField(UnitPtr unit) const;

    /**
     * @return Constant reference to the vector of FieldPtr objects representing all fields on the board
     */
    const std::vector<FieldPtr> &getFields() const;

    /**
     * @return Vector of UnitPtr objects representing all units present on the board.
     */
    std::vector<UnitPtr> getUnits() const;

    /**
     * @param kingColor The color of the king to search for (WHITE or BLACK)
     * @return Pointer to the Field object containing the king of the specified color
     * @throws StateIntegrityException if no king of the specified color is found on the board
     */
    FieldPtr getKingField(PlayerColor kingColor);

private:
    /**
     * @brief Initializes the board with empty fields.
     * Fills the board with default chess pieces according to the standard setup.
     */
    void initlializeWithEmptyFields();

    /**
     * @brief Helper function to fill missing fields in the board setup.
     * @param fieldsToFill Vector of FieldPtr objects to be filled with missing fields.
     * @return Vector of FieldPtr objects with all positions filled, including those provided in fieldsToFill.
     */
    static std::vector<FieldPtr> fillMissingFields(std::vector<FieldPtr> fieldsToFill) ;
};


#endif //CHESSPROJECT_BOARD_H
