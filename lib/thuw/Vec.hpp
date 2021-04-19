#pragma once

#include "glad/glad.h"
#include <array>
#include <bits/c++config.h>
#include <initializer_list>
#include <tuple>
#include <vector>

//TODO: namespace
namespace thuw {
    template<std::size_t Dimension>
    class Vec;
}

template<std::size_t Dimension>
class thuw::Vec {
public:
    const std::array<GLfloat, Dimension> vec;
    static constexpr std::size_t dimension = Dimension;

    enum : const int {
        X = 0,
        Y = 1,
        Z = 2,
        W = 3
    };

    template<typename ...T>
    constexpr Vec(const T& ...n) : vec({n...}) {
        static_assert(sizeof...(n) == Dimension);
    }

    constexpr GLfloat x() const {
        return this->vec[X];
    }

    constexpr GLfloat y() const {
        return this->vec[Y];
    }

    constexpr GLfloat z() const {
        static_assert(Dimension > Z);
        return this->vec[Z];
    }

    constexpr GLfloat w() const {
        static_assert(Dimension > W);
        return this->vec[W];
    }
    
    template<typename Vector>
    constexpr Vec<Dimension> operator+(const Vector&& vec) const {
        GLfloat v[Dimension];
        for(int i = 0; i < Dimension; i++) {
            v[i] = this->vec[i] + vec.vec[i];
        }
        return Vec<Dimension>(v);
    }

};