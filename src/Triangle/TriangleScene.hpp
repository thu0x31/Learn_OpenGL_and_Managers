#pragma once

#include "glad/glad.h"
#include "thuw/Scene/Scene.hpp"
#include "thuw/Keyboard/Key.hpp"
#include "thuw/Scene/Transitioner.hpp"
#include "thuw/Shader/Vertex.hpp"
#include "thuw/Shader/Fragment.hpp"
#include "thuw/Shader/Program.hpp"
#include "thuw/Buffer/VBO.hpp"
#include "thuw/Buffer/EBO.hpp"
#include "thuw/VAO.hpp"
#include "thuw/Vec.hpp"
#include "thuw/Vertices.hpp"
#include <array>
#include <string>
#include <vector>

#ifndef NDEBUG
    #include <iostream>
    #include <ostream>
#endif

class TriangleScene final : public thuw::Scene::Interface {
public:
    static constexpr auto Name = "Triangle";
    // thuw::Key key;
    thuw::Shader::Program program;
    thuw::VAO vao;

    TriangleScene()
    {
        // this->key.pressed<thuw::Key::W>([&]{
        //     this->transition("First");
        // });

        // this->key.pressed<thuw::Key::A>([&]{
        //     this->program.use();
        //     this->vao.bind();
        //     // glDrawArrays(GL_TRIANGLES, 0, 3);
        //     glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        // });

        // TODO: 
        std::string currentFilePath(__FILE__);
        currentFilePath.erase(
            currentFilePath.begin() + currentFilePath.rfind("/"),
            currentFilePath.end()
        );

        const auto&& vertexShader = thuw::Shader::Vertex(currentFilePath + "/shader/triangle.vert");
        const auto&& fragmentShader = thuw::Shader::Fragment(currentFilePath + "/shader/triangle.frag");

        program.attach(vertexShader, fragmentShader);
        program.link(vertexShader, fragmentShader);

        constexpr auto vertices = thuw::Vertices{
            thuw::Vec{0.5f, 0.5f, 0.0f},
            thuw::Vec{0.5f, -0.5f, 0.0f},
            thuw::Vec{-0.5f, -0.5f, 0.0f},
            thuw::Vec{-0.5f,  0.5f, 0.0f}
        };

        const auto&& vbo = thuw::Buffer::VBO(vertices);
        const auto&& ebo = thuw::Buffer::EBO{
            0, 1, 3,
            1, 2, 3
        };

        vao.bind();
        vao.copyInBuffer(vbo);
        vao.copyInBuffer(ebo);

        constexpr int location = 0;
        vao.setAttribute(location);

        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        vao.unbind();
    }

    void setup() {
        #ifndef NDEBUG
            std::cout << this->Name << std::endl;
        #endif

        glClearColor(0.5,0.5, 0.2, 1.);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void update() {
        glClearColor(0.1,0.1, 0.2, 1.);
        glClear(GL_COLOR_BUFFER_BIT);

        this->program.use();
        this->vao.bind();
        // glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }
};