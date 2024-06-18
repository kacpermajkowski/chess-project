#ifndef CHESSPROJECT_POSITION_H
#define CHESSPROJECT_POSITION_H

#include "typedefs.h"
#include "model/move/MoveVector.h"

/**
 * @brief Position class represents a position on a board
 */
class Position : public std::enable_shared_from_this<Position>{
private:
    LetterIndex letterIndex; ///< The letter index of the position
    NumberIndex numberIndex; ///< The number index of the position
public:
    /**
     * @brief Constructor for a Position object
     * @param letterIndex The letter index of the position
     * @param numberIndex The number index of the position
     */
    Position(LetterIndex letterIndex, NumberIndex numberIndex);
    virtual ~Position();

    /**
     * @brief Applies a move vector to the current position and returns a new position
     * @param vector Pointer to the move vector to apply
     * @return Pointer to the new Position object
     */
    PositionPtr applyMoveVector(MoveVectorPtr vector) const;

    /**
     * @return The letter index of the position
     */
    LetterIndex getLetterIndex() const;

    /**
     * @return The number index of the position
     */
    NumberIndex getNumberIndex() const;

    /**
     * @brief Checks if this position is equal to another position
     * @param position Pointer to the position to compare against
     * @return true if the positions are equal, false otherwise
     */
    bool equals(const PositionPtr& position) const noexcept;
};




#endif //CHESSPROJECT_POSITION_H
