#pragma once

#include "glad/glad.h"
#include <iostream>
#include <ostream>
#include <vector>

namespace thuw::Shader {
    class Program;
}

// TODO: global
class thuw::Shader::Program {
public:
    GLuint id;

    Program() = default;

    Program(GLuint id) : id(id) {
        #ifndef NDEBUG
            std::cout << "create Program : id:" << this->id << std::endl;
        #endif
    }

    template<class ...ShaderList>
    void attach(const ShaderList& ...shader) const {
        (glAttachShader(this->id, shader.id), ...);

        #ifndef NDEBUG
            ([&]{
                std::cout << "Attach: Program id:" << this->id << " Shader id:" << shader.id << std::endl;
            }(), ...);
        #endif
    }

    template<class ...ShaderList>
    void link(const ShaderList& ...shader) const {
        glLinkProgram(this->id);

        #ifndef NDEBUG
            int success;
            glGetProgramiv(this->id, GL_LINK_STATUS, &success);
            if(!success) {
                char infoLog[512];
                glGetProgramInfoLog(this->id, 512, NULL, infoLog);
                std::cout << "ERROR:Shader:Program:LINK: " << infoLog << std::endl;
            }
        #endif

        (glDeleteShader(shader.id), ...);
    }

    void use() const {
        #ifndef NDEBUG
            std::cout << "use Program id : " << this->id << std::endl;
        #endif

        glUseProgram(this->id);
    }
};

namespace thuw::Shader {
    namespace Global {
        Shader::Program Program;
    }

    void initProgram() {
        thuw::Shader::Global::Program.id = glCreateProgram();
    }
}