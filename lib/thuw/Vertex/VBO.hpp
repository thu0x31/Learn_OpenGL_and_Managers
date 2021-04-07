#pragma once

#include "glad/glad.h"
#include <initializer_list>
#include <iostream>

namespace thuw::Vertex {
    class VBO;
}

class thuw::Vertex::VBO {
private:
    static inline int globalID = 1;
    GLuint id;

public:
    VBO() = default;

    VBO(const std::initializer_list<float>& vercities, const int usage = VBO::STREAM_DRAW) {
        glGenBuffers(globalID, &id);
        glBindBuffer(GL_ARRAY_BUFFER, id);

        globalID++;
    }

    enum : int {
        STREAM_DRAW = GL_STREAM_DRAW,
        STATIC_DRAW = GL_STATIC_DRAW,
        DYNAMIC_DRAW = GL_DYNAMIC_DRAW,
    };
};