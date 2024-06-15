//
// Created by user on 15.06.2024.
//

#include "model/exceptions/StateIntegrityException.h"

const char *StateIntegrityException::what() const noexcept {
    return message.c_str();
}

StateIntegrityException::StateIntegrityException() {}

StateIntegrityException::StateIntegrityException(const std::string &message) : message(message) {}
