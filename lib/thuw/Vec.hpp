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

namespace thuw {
    template<class VecClass>
    concept VecConcept = requires(VecClass vec) {
        vec.dimension;
    };

    template<typename Type>
    concept Number = std::is_floating_point_v<Type> || std::is_integral_v<Type>;

    template<std::size_t Dimension>
    class Vec;

    using Vec2 = Vec<2>;
    using Vec3 = Vec<3>;
    using Vec4 = Vec<4>;

    template<Number ...Num>
    Vec(Num&& ...nums) -> Vec<sizeof...(Num)>;
}

template<std::size_t Dimension>
class thuw::Vec {
private:
    static_assert(Dimension < 5);

    using Type = float;

public:
    static constexpr std::size_t X = 0;
    static constexpr std::size_t Y = 1;
    static constexpr std::size_t Z = 2;
    static constexpr std::size_t W = 3;

    static constexpr std::size_t dimension = Dimension;

    std::array<Type, dimension> vec;
    
    template<Number ...Num>
    constexpr Vec(Num&& ...num) : vec({static_cast<float>(num)...}){}

    constexpr Vec(std::array<Type, Dimension> arr) : vec(arr) {}

public:
    constexpr float x() const {
        return this->vec[X];
    }

    constexpr float y() const {
        if constexpr (Y >= dimension){
            return 0.f;
        }

        return this->vec[Y];
    }

    constexpr float z() const {
        if constexpr (Z >= dimension) {
            return 0.f;
        }

        return this->vec[Z];
    }

    constexpr float w() const {
        if constexpr (W >= dimension) {
            return 1.f;
        }

        return this->vec[W];
    }

    template<Number Index>
    constexpr float get(const Index index) const {
        if(X == index)
            return this->x();

        if(Y == index)
            return this->y();

        if(Z == index)
            return this->z();

        if(W == index)
            return this->w();

        return 0;
    }

    template<Number Index>
    constexpr float operator[](const Index&& index) const {
        return this->get(std::forward<Index>(index));
    }

    constexpr auto data() const {
        return this->vec.data();
    }
    
    template<VecConcept V>
    [[nodiscard]] 
    constexpr auto operator+(V& vec) const {
        constexpr std::size_t D = std::max(dimension, V::dimension);

        std::array<Type, D> arr;
        for(std::size_t i = 0; i < D; i++) {
            arr[i] = this->get(i) + vec.get(i);
        }

        return thuw::Vec<D>(arr);
    }
};

// TODO: prototype test
constexpr thuw::Vec v1{1.f, 2.f, 3.f, 4};
constexpr auto v2 = thuw::Vec<3>{1, 2, 3};
constexpr auto v5 = thuw::Vec4{1.f, 2.f, 3.f, 3.f};
constexpr auto v3 = thuw::Vec{1.f, 2.f};
constexpr auto v4 = thuw::Vec{1.f, 2.f, 3.f};
constexpr auto vvv = thuw::Vec{1.f, 2.f, 3.f};
auto v23 = thuw::Vec{1.f, 2.f};
auto v34 = thuw::Vec{1.f, 2.f, 3.f};
auto test = v23 + v34;
const auto test2 = v23 + v34;
constexpr auto aaa = v1.data();
constexpr thuw::Vec vecR = v1 + v2;