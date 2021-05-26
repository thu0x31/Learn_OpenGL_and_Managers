#pragma once

#include "lib/thuw/Math/Vec/Vec.hpp"

namespace thuw {
    struct Point;
}

struct thuw::Point {
    union {
        thuw::Vec4 vec;
        struct { float x, y, z, w; };
    };

    union {
        thuw::Vec4 color;
        struct { float r, g, b , a; };
    };

    template<Concepts::Vec V>
    constexpr Point(V&& vec) : vec(vec) {}

    constexpr auto normal() {
        // TODO: calc normal
    }

    // TODO: draw()
};