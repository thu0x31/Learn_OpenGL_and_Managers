#pragma once

#include "glad/glad.h"
#include <cassert>
#include <fstream>
#include <iterator>
#include <string>
#include "thuw/Shader/Compile.hpp"

#ifndef NDEBUG
    #include <iostream>
    #include <ostream>
#endif

namespace thuw::Shader {
    class Fragment;
}

class thuw::Shader::Fragment {
private:
    const GLuint id;
    std::string code;

public:
    Fragment(const std::string& shaderPath) : id(glCreateShader(GL_FRAGMENT_SHADER)) {
        this->path(shaderPath);
    }

    void path(const std::string& shaderPath) {
        #ifndef NDEBUG
            std::cout << "FragmentShader: id:" << this->id << " path:" << shaderPath << std::endl;
        #endif

        std::ifstream fileStream(shaderPath);
        assert(!fileStream.fail());

        this->code = std::string(
            std::istreambuf_iterator<char>(fileStream),
            std::istreambuf_iterator<char>()
        );
    }

    auto getCode() const {
        return this->code.c_str();
    }

    auto getId() const {
        return this->id;
    }

    void compile() const {
        thuw::Shader::compile(this);
    }
};