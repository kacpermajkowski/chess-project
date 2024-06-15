//
// Created by user on 13.06.2024.
//

#include <type_traits>
#include "typedefs.h"

template<typename T, typename = std::enable_if_t<std::is_base_of<Unit, T>::value>>
bool isTypeOf(const UnitPtr& unitPtr) {
    // Attempt to cast the shared pointer to a shared pointer of type T
    std::shared_ptr<T> derivedPtr = std::dynamic_pointer_cast<T>(unitPtr);
    // If the cast is successful (not null), it is pointing to an instance of T
    return (derivedPtr != nullptr);
}