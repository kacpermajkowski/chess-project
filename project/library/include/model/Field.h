#ifndef CHESSPROJECT_FIELD_H
#define CHESSPROJECT_FIELD_H

#include "Position.h"
#include "unit/Unit.h"

/**
 * @brief Field class represents a single field with a position and optionally a unit
 */
class Field : public std::enable_shared_from_this<Field>{

private:
    PositionPtr position; ///< Pointer to the position object of this field
    UnitPtr unit = nullptr; ///< Pointer to the unit occupying this field or nullptr
public:
    /**
     * @brief Constructor for a Field object with a given position
     * @param position Pointer to the position
     */
    explicit Field(PositionPtr position);

    /**
     * @brief Constructor for a Field object with a given position and unit
     * @param position Pointer to the position
     * @param unit Pointer to the unit to be placed on this field
     */
    Field(PositionPtr position, UnitPtr unit);

    virtual ~Field();

    /**
     * @return Pointer to the position of the field
     */
    PositionPtr getPosition();

    /**
     * @return Pointer to the unit occupying this field, or nullptr if empty
     */
    UnitPtr getUnit();

    /**
     * @brief Checks if this field is occupied by any unit
     * @return true if the field is occupied by a unit, false otherwise
     */
    bool isOccupied();

    /**
     * @brief Checks if this field is occupied by an enemy unit of the given player color
     * @param color The player color to check against
     * @return true if the field is occupied by an enemy unit, false otherwise
     */
    bool isOccupiedByEnemy(PlayerColor color);

    /**
     * @brief Checks if this field is occupied by an enemy unit relative to a given ally unit
     * @param allyUnit Pointer to the ally unit to compare against
     * @return true if the field is occupied by an enemy unit, false otherwise
     */
    bool isOccupiedByEnemy(const UnitPtr& allyUnit);

    /**
     * @brief Checks if this field is occupied by an ally unit of the given player color
     * @param color The player color to check against
     * @return true if the field is occupied by an ally unit, false otherwise
     */
    bool isOccupiedByAlly(PlayerColor color);

    /**
     * @brief Checks if this field is occupied by a specific ally unit
     * @param allyUnit Pointer to the ally unit to compare against
     * @return true if the field is occupied by the specified ally unit, false otherwise
     */
    bool isOccupiedByAlly(const UnitPtr& allyUnit);

    /**
     * @brief Sets a new unit to occupy this field
     * @param newUnit Pointer to the new unit to be placed on this field
     */
    void setUnit(UnitPtr newUnit);
};


#endif //CHESSPROJECT_FIELD_H
