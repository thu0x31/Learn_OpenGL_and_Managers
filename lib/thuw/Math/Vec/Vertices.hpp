#pragma once

#include "glad/glad.h"
#include "thuw/Math/Vec/Vec.hpp"
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
#include <utility>
#include <vector>
#include <string>
#include "thuw/Math/Matrix/Matrix.hpp"
#include "thuw/Math/Math.hpp"

namespace thuw {
    namespace Concepts {
        template<class Vert>
        concept Vertices = requires {
            Vert::dimension;
            Vert::size;
        };
    };

    inline namespace Vert {
        template<size_t Size, size_t D>
        class Vertices;

        // Vertices< Type{int, float, double}, ListSize{3, 3, 3, 3}>
        template<Concepts::Numeric ...Type, size_t ...ListSize>
        Vertices(const Type (&...list)[ListSize]) 
        -> Vertices<sizeof...(ListSize), (ListSize + ...) / sizeof...(ListSize)>;
    }
}

template<size_t Size, size_t D>
class thuw::Vertices {
public:
    using Type = float;

    static constexpr std::size_t dimension = D;
    static constexpr std::size_t size = Size;
    static constexpr std::size_t stride = dimension * sizeof(Type);

    // using Vec = std::array<Type, dimension>;
    using Vec = thuw::Vec<D, Type>;
    std::array<Vec, size> vertices;


    // TODO: array to Vec
    // template<size_t ...ListSize>
    // constexpr Vertices(const Type (&...list)[ListSize]) : vertices({Vec(*list) ...}) {}

    template<thuw::Concepts::Vec ...Vec>
    constexpr Vertices(Vec&& ...vec) : vertices({vec...}) {}

    constexpr auto data() const {
        return this->vertices.data();
    }

    constexpr thuw::Vec<dimension> operator[](const std::size_t index) const {
        return vertices[index].data();
    }

    // constexpr auto scale(float x, float y) {
        // std::array<Vec, Size> scaled;
        // std::transform(vertices.begin(), vertices.end(), std::back_inserter(scaled),
        //     [x = std::move(x), y = std::move(y)] (auto&& v) {
        //         return thuw::Vec3(v[0], v[1], v[2]);
        //     }
        // );

        // return thuw::Vertices{scaled};
    // }
};