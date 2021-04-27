#pragma once

#include "glad/glad.h"
#include <array>
#include <bits/c++config.h>
#include <initializer_list>
#include <tuple>
#include <vector>

template<class VecClass>
concept VecConcept = requires {
    VecClass::vec;
    VecClass::dimension;
};

//TODO: namespace
namespace thuw {
    template<typename ...Num>
    class Vec;
}

template<typename ...Num>
class thuw::Vec {
public:
    static constexpr std::size_t dimension = sizeof...(Num);
    const std::array<GLfloat, dimension> vec;

    enum : const int {
        X = 0,
        Y = 1,
        Z = 2,
        W = 3
    };

    constexpr Vec(const Num& ...n) : vec({n...}) {
        // static_assert(sizeof...(n) == Dimension);
    }

    constexpr GLfloat x() const {
        return this->vec[X];
    }

    constexpr GLfloat y() const {
        return this->vec[Y];
    }

    constexpr GLfloat z() const {
        static_assert(dimension > Z);
        return this->vec[Z];
    }

    constexpr GLfloat w() const {
        static_assert(dimension > W);
        return this->vec[W];
    }
    
    template<typename Vector>
    constexpr auto operator+(const Vector&& vec) const {
        GLfloat v[this->dimension];
        for(int i = 0; i < this->dimension; i++) {
            v[i] = this->vec[i] + vec.vec[i];
        }
        return Vec(v);
    }
};