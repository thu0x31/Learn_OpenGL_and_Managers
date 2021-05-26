#pragma once

#include "thuw/Geometry/Attribute/Point.hpp"
#include "thuw/Geometry/Geometry.hpp"
#include "thuw/Math/Vec/Vec.hpp"
#include <vector>

namespace thuw::Geo {
    class Triangle;
}

class thuw::Geo::Triangle {
private:
    thuw::Geometry geo;

public:
    thuw::Point position{thuw::Vec4{0, 0, 0, 0}};
    std::vector<thuw::Point> points;
    float scale = 1;
    float rotate = 0;
    // bounding box
    // color

    template<Concepts::Vec Vec>
    Triangle(Vec&& pos) : position(0, pos) {
        // TODO: constexpr triangale -> transform matrix -> scale matrix

        constexpr thuw::Vec4 top
         = thuw::Vec4{
            .x = pos.x,
            .y = pos.y + 0.5f * scale,
            .z = pos.z
        };

        constexpr thuw::Vec4 left
         = thuw::Vec4{
            .x = pos.x - 0.5f * scale,
            .y = pos.y - 0.5f * scale,
            .z = pos.z
        };

        constexpr thuw::Vec4 right
         = thuw::Vec4{
            .x = pos.x + 0.5f * scale,
            .y = pos.y - 0.5f * scale,
            .z = pos.z
        };

    }
};