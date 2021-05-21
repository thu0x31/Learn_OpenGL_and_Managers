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
    template<size_t ...Size>
    class Vertices;
}

template<size_t ...Size>
class thuw::Vertices {
public:
    static constexpr auto sizes = std::make_tuple(Size...);
    static constexpr std::size_t dimension = std::get<0>(sizes);
    static constexpr std::size_t maxIndex = sizeof...(Size);

    std::array<std::array<float, dimension>, maxIndex> vertices;

    template<Number Type>
    constexpr Vertices(const Type (&...list)[Size]) : vertices({std::to_array(list)...}) {}

    constexpr auto data() const {
        return this->vertices.data();
    }

    constexpr thuw::Vec<dimension> operator[](const std::size_t index) const {
        return vertices[index];
    }
};