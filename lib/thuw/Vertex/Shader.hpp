#pragma once

#include <cassert>
#include <fstream>
#include <iterator>
#include <string>
#include <utility>

#ifndef NDEBUG
    #include <iostream>
    #include <ostream>
#endif

namespace thuw::Vertex {
    class Shader;
}

class thuw::Vertex::Shader {
private:
    std::string code;

public:
    Shader() = default;

    Shader(const std::string& shaderPath) {
        #ifndef NDEBUG
            std::cout << shaderPath << std::endl;
        #endif

        std::ifstream fileStream(shaderPath);
        assert(!fileStream.fail());

        this->code = std::string(
            std::istreambuf_iterator<char>(fileStream),
            std::istreambuf_iterator<char>()
        );
    }
};