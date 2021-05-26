#pragma once

#include "glad/glad.h"
#include <iostream>
#include <ostream>
#include <vector>
#include <cassert>

namespace thuw::Shader {
    class Program;
}

// TODO: global
class thuw::Shader::Program {
private:
    static inline GLuint id = 0;

public:
    static inline void init() {
        Program::id = glCreateProgram();
    }

    Program(){
        #ifndef NDEBUG
            assert(Program::id != 0);
            std::cout << Program::id << std::endl;
        #endif
    };

    template<class ...ShaderList>
    static inline void attach(const ShaderList& ...shader) {
        (glAttachShader(Program::id, shader.id), ...);

        #ifndef NDEBUG
            ([&]{
                std::cout << "Attach: Program id:" << Program::id << " Shader id:" << shader.id << std::endl;
            }(), ...);
        #endif
    }

    template<class ...ShaderList>
    static inline void link(const ShaderList& ...shader) {
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

    static inline void use() {
        #ifndef NDEBUG
            std::cout << "use Program id : " << Program::id << std::endl;
        #endif

        glUseProgram(Program::id);
    }
};