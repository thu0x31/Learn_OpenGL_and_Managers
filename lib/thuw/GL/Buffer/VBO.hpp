#pragma once

#include "glad/glad.h"
#include "thuw/Math/Vec/Vec.hpp"
#include <algorithm>
#include <array>
#include <iostream>
#include <utility>
#include <vector>

namespace thuw::Buffer {
    template<class VBOClass>
    concept VBOConcept = requires {
        VBOClass::vertices;
        VBOClass::id;
        VBOClass::stride;
    };

    template<class Vertices>
    class VBO;
}

template<class Vertices>
class thuw::Buffer::VBO {
public:
    GLuint id;
    const Vertices vertices;

    VBO(Vertices vertices) : vertices(vertices) {
        glGenBuffers(1, &id);
        
        #ifndef NDEBUG
            std::cout << "create VBO : id:" << this->id << std::endl;
        #endif
    }

    void copyInBuffer(const GLenum usage = GL_STATIC_DRAW) const {
        glBindBuffer(GL_ARRAY_BUFFER, id);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices.data(), usage);

        #ifndef NDEBUG
            std::cout << "Copy in Buffer: VBO id:" << id
             << " size:" << sizeof(vertices) << std::endl;
        #endif
    }
};