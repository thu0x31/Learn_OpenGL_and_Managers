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
private:
    static inline GLuint id;

public:
    static inline void init() {
        Program::id = glCreateProgram();
    }

    Program(){
        #ifndef NDEBUG
            std::cout << Program::id << std::endl;
        #endif
    };

    template<class ...ShaderList>
    void attach(const ShaderList& ...shader) const {
        (glAttachShader(Program::id, shader.id), ...);

        #ifndef NDEBUG
            ([&]{
                std::cout << "Attach: Program id:" << Program::id << " Shader id:" << shader.id << std::endl;
            }(), ...);
        #endif
    }

    template<class ...ShaderList>
    void link(const ShaderList& ...shader) const {
        glLinkProgram(Program::id);

        #ifndef NDEBUG
            int success;
            glGetProgramiv(Program::id, GL_LINK_STATUS, &success);
            if(!success) {
                char infoLog[512];
                glGetProgramInfoLog(Program::id, 512, NULL, infoLog);
                std::cout << "ERROR:Shader:Program:LINK: " << infoLog << std::endl;
            }
        #endif

        (glDeleteShader(shader.id), ...);
    }

    void use() const {
        #ifndef NDEBUG
            std::cout << "use Program id : " << Program::id << std::endl;
        #endif

        glUseProgram(Program::id);
    }
};