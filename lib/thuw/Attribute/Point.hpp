#pragma once

#include "lib/thuw/Math/Vec/Vec.hpp"

namespace thuw {
    struct Point;
}

struct thuw::Point {
    union {
        thuw::Vec3 vec;
        struct { float x, y, z; };
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