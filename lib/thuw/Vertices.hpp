#pragma once

#include "glad/glad.h"
#include "thuw/Vec.hpp"
#include <array>
#include <initializer_list>
#include <iterator>
#include <type_traits>
#include <vector>


namespace thuw {
    template<VecConcept FirstVec, VecConcept ...ListVec>
    class Vertices;
}

template<VecConcept FirstVec, VecConcept ...ListVec>
class thuw::Vertices {
public:
    const std::array<FirstVec, sizeof...(ListVec) + 1> vertices;
    static constexpr std::size_t dimension = FirstVec::dimension;

    constexpr Vertices(FirstVec firstVec, ListVec ...list) : vertices({firstVec, list...}) {
        static_assert(std::disjunction_v<std::is_same<FirstVec, ListVec>...>);
        
    }

    constexpr auto data() const {
        return this->vertices.data();
    }

    // TODO: rotate. sum. etc...
};