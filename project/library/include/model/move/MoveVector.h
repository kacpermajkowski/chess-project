//
// Created by user on 11.06.2024.
//

#ifndef CHESSPROJECT_MOVEVECTOR_H
#define CHESSPROJECT_MOVEVECTOR_H


#include <memory>

class MoveVector : public std::enable_shared_from_this<MoveVector>{
private:
    const int rowOffset;
    const int columnOffset;

public:
    MoveVector(const int columnOffset, const int rowOffset);

    int getRowOffset() const;

    int getColumnOffset() const;

};


#endif //CHESSPROJECT_MOVEVECTOR_H
