#pragma once

// #include "thuw/Math/Lib/linalg/linalg.h"
#include "../Math.hpp"
#include "thuw/Math/Lib/glm/glm/glm.hpp"

namespace thuw {
    namespace Concepts {
        template<class V>
        concept Vec = requires(V&& vec) {
            vec.x;
            vec.y;
        };
    };

    inline namespace Vector {
        template<int D, typename Type = float>
        using Vec = glm::vec<D, Type>;

        using Vec2 = Vec<2, float>;
        using Vec3 = Vec<3, float>;
        using Vec4 = Vec<4, float>;

        using Vec2i = Vec<2, int>;
        using Vec3i = Vec<3, int>;
        using Vec4i = Vec<4, int>;

        using Vec2f = Vec<2, float>;
        using Vec3f = Vec<3, float>;
        using Vec4f = Vec<4, float>;

        template<typename Array>
        auto arrayToVec(Array&& arr);
    };
}

// template<typename Array>
// auto thuw::Vector::arrayToVec(Array&& arr){
//     return 
// }