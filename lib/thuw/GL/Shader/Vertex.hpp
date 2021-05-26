#pragma once

#include "glad/glad.h"
#include <cassert>
#include <fstream>
#include <iterator>
#include <string>
#include "thuw/GL/Shader/Compile.hpp"

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
        thuw::Shader::compile(this);
    }
};