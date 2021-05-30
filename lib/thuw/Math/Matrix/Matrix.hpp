#pragma once

// #include "thuw/Math/Lib/linalg/linalg.h"
#include <type_traits>
#include "../Math.hpp"

namespace thuw {
    namespace Concepts {
        template<typename M>
        concept Mat = requires(M&& mat){
            mat.x;
            mat.y;
            mat.row();
        };
    }

    inline namespace Matrix {
        // template<int M, int N>
        // using Mat = linalg::mat<float, M, N>;

        // template<int M, int N>
        // using MatF = linalg::mat<float, M, N>;

        // template<int M, int N>
        // using MatI = linalg::mat<int, M, N>;

        // template<int M, int N>
        // using MatD = linalg::mat<double, M, N>;
    }
};