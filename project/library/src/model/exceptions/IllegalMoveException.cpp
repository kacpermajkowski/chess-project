//
// Created by user on 15.06.2024.
//
#include "model/exceptions/IllegalMoveException.h"

#include <utility>

IllegalMoveException::IllegalMoveException() = default;

IllegalMoveException::IllegalMoveException(string message) {
    this->message = std::move(message);
}

const char *IllegalMoveException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {
    return message.c_str();
}

