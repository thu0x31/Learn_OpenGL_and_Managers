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

template<class VBOClass>
concept VBOConcept = requires {
    VBOClass::vertices;
    VBOClass::id;
    VBOClass::stride;
};

namespace thuw::Buffer {
    template<class Vertices>
    class VBO;
}

template<class Vertices>
class thuw::Buffer::VBO {
public:
    GLuint id;
    const Vertices vertices;
    const std::size_t stride;// TODO:

    VBO(Vertices vertices) : vertices(vertices), stride(vertices.dimension * sizeof(float)) {
        glGenBuffers(1, &id);
        
        #ifndef NDEBUG
            std::cout << "create VBO : id:" << this->id << std::endl;
        #endif
    }
};