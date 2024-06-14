//
// Created by majkosia on 14.06.2024.
//

#include "model/exceptions/NoMoveToChooseFromException.h"

const char *NoMoveToChooseFromException::what() const noexcept {
    return message.c_str();
}

NoMoveToChooseFromException::NoMoveToChooseFromException(std::string message) : message(message) {

}

NoMoveToChooseFromException::NoMoveToChooseFromException() {}
