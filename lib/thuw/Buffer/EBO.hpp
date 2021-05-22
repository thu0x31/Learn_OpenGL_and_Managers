#pragma once

#include "glad/glad.h"
#include <array>
#include <initializer_list>
#include <iostream>
#include <vector>

namespace thuw::Buffer {
    template<class T>
    concept EBOConcept = requires {
        T::id;
        T::indices;
    };

    // TODO: EBO{{}, {}, {}}
    template<typename ...Index>
    struct EBO;
}

// TODO: EBO<n , n>
template<typename ...Index>
struct thuw::Buffer::EBO {
    GLuint id = 0;
    const std::array<int, sizeof...(Index)> indices;

    EBO(const Index& ...index) : indices({index...}) {
        glGenBuffers(1, &this->id);

        #ifndef NDEBUG
            std::cout << "create EBO : id:" << this->id << std::endl;
        #endif
    }
};