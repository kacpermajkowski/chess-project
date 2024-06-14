//
// Created by majkosia on 14.06.2024.
//

#include "noMoveToChooseFromException.h"

const char *noMoveToChooseFromException::what() const noexcept {
    return message;
}

noMoveToChooseFromException::noMoveToChooseFromException(char *message) : message(message) {

}

noMoveToChooseFromException::noMoveToChooseFromException() {}
