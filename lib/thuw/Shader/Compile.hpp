#pragma once

#include "glad/glad.h"
#include <iostream>
#include <ostream>

//TODO: concept shader

namespace thuw::Shader {
    template<class Shader>
    void compile(const Shader& shader) {
        const char* code = shader->code.c_str();
        glShaderSource(shader->id, 1, &code, NULL);
        glCompileShader(shader->id);

        #ifndef NDEBUG
            std::cout << "Compile Shader Code: " << std::endl << code << std::endl;

            int success;
            glGetShaderiv(shader->id, GL_COMPILE_STATUS, &success);

            if(!success){
                char infoLog[512];
                glGetShaderInfoLog(shader->id, 512, NULL, infoLog);
                std::cout << "ERROR::SHADER:: " << infoLog << std::endl;
                return;
            }

            std::cout << "Shader Compile is Success" << std::endl;
        #endif
    }
}