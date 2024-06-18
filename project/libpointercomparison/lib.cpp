//
// Created by user on 18.06.2024.
//

#include <type_traits>
#include <memory>

class Unit;
typedef std::shared_ptr<Unit> UnitPtr;

template<typename T>
bool isTypeOf(const UnitPtr& unitPtr) {
    // Attempt to cast the shared pointer to a shared pointer of type T
    std::shared_ptr<T> derivedPtr = std::dynamic_pointer_cast<T>(unitPtr);
    // If the cast is successful (not null), it is pointing to an instance of T
    return (derivedPtr != nullptr);
}