#pragma once

#include "glad/glad.h"
#include <algorithm>
#include <array>
#include <initializer_list>
#include <iostream>
#include <vector>

// TODO: Buffer namespace?
namespace thuw::Vertex {
    class VBO;
}

class thuw::Vertex::VBO {
public:
    GLuint id; // TODO: 複数のバッファに対応させるかどうか
    const std::vector<GLfloat> vercities;

    // TODO: vec2,vec3,vec4
    // TODO: 複数のバッファに対応させるかどうか
    template<class ...Vertex>
    VBO(Vertex ...vertex) : vercities({vertex...}) {
        glGenBuffers(1, &id);
        
        #ifndef NDEBUG
            std::cout << "create VBO : id:" << this->id << std::endl;
        #endif
    }
};