//
// Created by user on 13.06.2024.
//

#include <type_traits>

template<typename T, typename U>
bool areSameBaseType(const T& t, const U& u) {
    return std::is_base_of<T, U>::value;
}