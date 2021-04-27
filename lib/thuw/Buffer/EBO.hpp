#pragma once

#include "glad/glad.h"
#include <array>
#include <bits/c++config.h>
#include <initializer_list>
#include <iostream>
#include <vector>

template<class T>
concept EBOConcept = requires {
    T::indices;
    T::id;
};

namespace thuw::Buffer {
    template<typename ...Index>
    struct EBO;
}

template<typename ...Index>
struct thuw::Buffer::EBO {
    GLuint id;
    const std::array<int, sizeof...(Index)> indices;
    
    EBO(const Index& ...index) : indices({index...}) {
        glGenBuffers(1, &this->id);

        #ifndef NDEBUG
            std::cout << "create EBO : id:" << this->id << std::endl;
        #endif
    }
};