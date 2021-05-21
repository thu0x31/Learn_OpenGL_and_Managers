#pragma once

#include "glad/glad.h"
#include "thuw/Vec.hpp"
#include <algorithm>
#include <array>
#include <cstddef>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <locale>
#include <ostream>
#include <tuple>
#include <type_traits>
#include <vector>
#include <string>


namespace thuw {
    template<size_t Size, size_t D>
    class Vertices;


    // Vertices< Type{int, float, double}, ListSize{3, 3, 3, 3}>
    template<Number ...Type, size_t ...ListSize>
    Vertices(const Type (&...list)[ListSize]) 
    -> Vertices<sizeof...(ListSize), (ListSize + ...) / sizeof...(ListSize)>;
}

// vertices<float, Size = 4, VecD = 3>
template<size_t Size, size_t D>
class thuw::Vertices {
public:
    using Type = float;

    static constexpr std::size_t dimension = D;
    static constexpr std::size_t size = Size;

    using VecArray = std::array<Type, dimension>;
    std::array<VecArray, size> vertices;

    template<size_t ...ListSize>
    constexpr Vertices(const Type (&...list)[ListSize]) : vertices({std::to_array(list)...}) {}

    constexpr auto data() const {
        return this->vertices.data();
    }

    constexpr thuw::Vec<dimension> operator[](const std::size_t index) const {
        return vertices[index];
    }
};