#pragma once

#include "glad/glad.h"
#include "thuw/Vertex/VBO.hpp"
#include <iostream>
#include <ostream>

namespace thuw {
    struct VAO;
}

struct thuw::VAO {
private:
    GLuint id;

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

    void unbind() {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    void copyInBuffer(const thuw::Vertex::VBO& vbo) const {
        glBindBuffer(GL_ARRAY_BUFFER, vbo.id);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vbo.vercities), vbo.vercities.data(), GL_STATIC_DRAW);

        #ifndef NDEBUG
            std::cout << "Copy in Buffer: VBO id:" << vbo.id
             << " size:" << sizeof(vbo.vercities) << std::endl;
            for(const auto& v : vbo.vercities) {
                std::cout << v << std::endl;
            }
        #endif
    }

    void setAttribute() const {
        //TODO: vec2, vec3, vec4
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
    }
};