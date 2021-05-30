#pragma once
#define GLM_FORCE_SWIZZLE

#include "thuw/Math/Lib/glm/glm/glm.hpp"
#include <type_traits>

namespace thuw {
    namespace Concepts {
        template<typename Type>
        concept Numeric = std::is_arithmetic_v<Type>;
    }

}