#ifndef TYPETRAITS_H
#define TYPETRAITS_H

#include <type_traits>
#include "data.h"

// Using type traits defined in C++20 to check for type
template <typename T>
concept isData = std::is_same<T, Data>::value;

#endif
