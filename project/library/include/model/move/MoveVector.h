//
// Created by user on 11.06.2024.
//

#ifndef CHESSPROJECT_MOVEVECTOR_H
#define CHESSPROJECT_MOVEVECTOR_H


#include <memory>

/**
 * @brief MoveVector class represents a directional move vector on the chessboard
 *
 * A MoveVector is used to determine the relative movement from one position to another,
 * specifying the row and column offsets
 */
class MoveVector : public std::enable_shared_from_this<MoveVector>{
private:
    const int rowOffset; ///< The row offset for the move (positive or negative)
    const int columnOffset; ///< The column offset for the move (positive or negative)

public:
    /**
     * @brief Constructs a MoveVector with specified column and row offsets
     * @param columnOffset The column offset for the move
     * @param rowOffset The row offset for the move
     */
    MoveVector(const int columnOffset, const int rowOffset);

    /**
     * @return The row offset
     */
    int getRowOffset() const;

    /**
     * @return The column offset
     */
    int getColumnOffset() const;

};


#endif //CHESSPROJECT_MOVEVECTOR_H
