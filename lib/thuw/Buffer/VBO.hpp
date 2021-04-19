#pragma once

#include "glad/glad.h"
#include "thuw/Vec.hpp"
#include <algorithm>
#include <array>
#include <bits/c++config.h>
#include <initializer_list>
#include <iostream>
#include <utility>
#include <vector>

template<class T>
concept VBOConcept = requires {
    T::vercities;
    T::id;
};

namespace thuw::Buffer {
    template<class First, class ...V>
    class VBO;
}

template<class First, class ...V>
class thuw::Buffer::VBO {
public:
    GLuint id;
    const std::array<const First, sizeof...(V) + 1> vercities;

    VBO(const First&& fvec, const V&& ... vec) : vercities({fvec, vec...}) {
        (assert(First::dimension == vec.dimension), ...);
        glGenBuffers(1, &id);
        
        #ifndef NDEBUG
            std::cout << "create VBO : id:" << this->id << std::endl;
        #endif
    }
};