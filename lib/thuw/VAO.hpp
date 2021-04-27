#pragma once

#include "glad/glad.h"
#include "thuw/Buffer/EBO.hpp"
#include "thuw/Buffer/VBO.hpp"
#include <iostream>
#include <ostream>

namespace thuw {
    struct VAO;
}

struct thuw::VAO {
private:
    GLuint id;
    GLuint stride;

public:
    VAO() {
        glGenVertexArrays(1, &this->id);
        
        #ifndef NDEBUG
            std::cout << "create VAO : id:" << this->id << std::endl;
        #endif
    }

    void bind() const {
        glBindVertexArray(this->id);
    }

    void unbind() const {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    template<VBOConcept VBO>
    void copyInBuffer(const VBO& vbo, const GLenum usage = GL_STATIC_DRAW) {
        glBindBuffer(GL_ARRAY_BUFFER, vbo.id);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vbo.vertices), vbo.vertices.data(), usage);
        this->stride = vbo.stride;

        #ifndef NDEBUG
            std::cout << "Copy in Buffer: VBO id:" << vbo.id
             << " size:" << sizeof(vbo.vertices) << std::endl;
        #endif
    }

    template<EBOConcept EBO>
    void copyInBuffer(const EBO& ebo, const GLenum usage = GL_STATIC_DRAW) const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo.id);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(ebo.indices), ebo.indices.data(), usage);

        #ifndef NDEBUG
            std::cout << "Copy in Buffer: EBO id:" << ebo.id
             << " size:" << sizeof(ebo.indices) << std::endl;
        #endif
    }

    void setAttribute(const int location) const {
        glVertexAttribPointer(location, 3, GL_FLOAT, GL_FALSE, this->stride, (void*)0);
        glEnableVertexAttribArray(location);
    }
};