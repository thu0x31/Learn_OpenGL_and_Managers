#pragma once

#include "lib/thuw/Vec.hpp"

namespace thuw {
    struct Point;
}

struct thuw::Point {
    unsigned int number;
    thuw::Vec4 vec;

    template<VecConcept V>
    constexpr Point(unsigned int number, V&& vec) : number(number), vec(vec) {}

    constexpr auto normal() {
        // TODO: calc normal
    }
};