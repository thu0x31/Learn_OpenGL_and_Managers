#pragma once

#include "glad/glad.h"
#include <__tuple>
#include <algorithm>
#include <array>
#include <cstddef>
#include <initializer_list>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>
#include "./linalg/linalg.h"

namespace thuw {
    namespace Concepts{
        template<class VecClass>
        concept Vec = requires(VecClass vec) {
            vec.x;
            vec.y;
        };

        template<typename Type>
        concept Numeric = std::is_arithmetic_v<Type>;
    };

    template<typename Type, int Size>
    using Vec = linalg::vec<Type, Size>;

    using Vec2 = linalg::aliases::float2;
    using Vec3 = linalg::aliases::float3;
    using Vec4 = linalg::aliases::float4;

    using Vec2f = linalg::aliases::float2;
    using Vec3f = linalg::aliases::float3;
    using Vec4f = linalg::aliases::float4;
}
