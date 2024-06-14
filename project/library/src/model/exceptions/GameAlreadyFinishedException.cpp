//
// Created by user on 14.06.2024.
//

#include "model/exceptions/GameAlreadyFinishedException.h"

#include <utility>

GameAlreadyFinishedException::~GameAlreadyFinishedException() noexcept = default;

const char *GameAlreadyFinishedException::what() const noexcept {
    return message.c_str();
}

GameAlreadyFinishedException::GameAlreadyFinishedException(std::string message) : message(std::move(message)) {
}
