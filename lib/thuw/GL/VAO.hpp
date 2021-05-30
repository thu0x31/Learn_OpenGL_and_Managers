#pragma once

#include "glad/glad.h"
#include "thuw/GL/Buffer/EBO.hpp"
#include "thuw/GL/Buffer/VBO.hpp"
#include "thuw/Math/Vec/Vertices.hpp"
#include <cassert>
#include <iostream>
#include <ostream>

namespace thuw {
    struct VAO;
}

struct thuw::VAO {
private:
    GLuint id = 0;

public:
    void init() {
        glGenVertexArrays(1, &this->id);

        #ifndef NDEBUG
            std::cout << "init VAO is : " << id << std::endl;
        #endif
    }

    void bind() const {
        #ifndef NDEBUG
            assert(id != 0);
            std::cout << "use VAO is : " << id << std::endl;
        #endif

        glBindVertexArray(this->id);
    }

    void unbind() const {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    template<class Vertices>
    void setAttribute(const int location, Vertices&& vertices) const {
        glVertexAttribPointer(location, vertices.size, GL_FLOAT, GL_FALSE, vertices.stride, (void*)0);
        glEnableVertexAttribArray(location);
    }
};