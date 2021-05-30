#pragma once

#include "glad/glad.h"
#include <cassert>
#include <fstream>
#include <iterator>
#include <string>

#ifndef NDEBUG
    #include <iostream>
    #include <ostream>
#endif

namespace thuw::Shader {
    class Vertex;
}

class thuw::Shader::Vertex {
public:
    const GLuint id = 0;
    std::string code;

    Vertex(const std::string& shaderPath) : id(glCreateShader(GL_VERTEX_SHADER)) {
        this->path(shaderPath);
        this->compile();
    }

private:
    void path(const std::string& shaderPath) {
        #ifndef NDEBUG
            assert(id != 0);
            std::cout << "VertexShader: id:" << this->id << " path:" << shaderPath << std::endl;
        #endif

        std::ifstream fileStream(shaderPath);
        assert(!fileStream.fail());

        this->code = std::string(
            std::istreambuf_iterator<char>(fileStream),
            std::istreambuf_iterator<char>()
        );
    }

    void compile() const {
        const char* code = this->code.c_str();
        glShaderSource(this->id, 1, &code, NULL);
        glCompileShader(this->id);

        #ifndef NDEBUG
            std::cout << "Compile Shader Code: " << std::endl << code << std::endl;

            int success;
            glGetShaderiv(this->id, GL_COMPILE_STATUS, &success);

            if(!success){
                char infoLog[512];
                glGetShaderInfoLog(this->id, 512, NULL, infoLog);
                std::cout << "ERROR::SHADER:: " << infoLog << std::endl;
                return;
            }

            std::cout << "Shader Compile is Success" << std::endl;
        #endif
    }
};