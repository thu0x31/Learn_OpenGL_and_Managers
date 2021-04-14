#pragma once

#include "glad/glad.h"
#include "thuw/Scene/Scene.hpp"
#include "thuw/Keyboard/Key.hpp"
#include "thuw/Scene/Transitioner.hpp"
#include "thuw/Shader/Vertex.hpp"
#include "thuw/Shader/Fragment.hpp"
#include "thuw/Shader/Program.hpp"
#include "thuw/Vertex/VBO.hpp"
#include "thuw/VAO.hpp"
#include <array>
#include <string>
#include <vector>

#ifndef NDEBUG
    #include <iostream>
    #include <ostream>
#endif

class TriangleScene final : public thuw::Scene::SceneInterface {
public:
    static constexpr auto Name = "Triangle";
    thuw::Scene::Transitioner transition;
    thuw::Key key;
    thuw::Shader::Program program;
    thuw::VAO vao;

    TriangleScene(const thuw::Scene::Transitioner& transition , const thuw::Key& key)
     : transition(transition), key(key)
    {
        this->key.pressed<thuw::Key::W>([&]{
            this->transition("First");
        });
    }

    void setup() {
        #ifndef NDEBUG
            std::cout << this->Name << std::endl;
        #endif

        glClearColor(0.5,0.5, 0.2, 1.);
        glClear(GL_COLOR_BUFFER_BIT);

        // TODO: 
        std::string currentFilePath(__FILE__);
        currentFilePath.erase(
            currentFilePath.begin() + currentFilePath.rfind("/"),
            currentFilePath.end()
        );

        const auto&& vertexShader = thuw::Shader::Vertex(currentFilePath + "/shader/triangle.vert");
        const auto&& fragmentShader = thuw::Shader::Fragment(currentFilePath + "/shader/triangle.frag");
        vertexShader.compile();
        fragmentShader.compile();

        // const auto && program = thuw::Shader::Program();
        program.attach(vertexShader, fragmentShader);
        program.link(vertexShader, fragmentShader);

        const auto&& vbo = thuw::Vertex::VBO(
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
        );
        // const auto&& vao = thuw::VAO();
        vao.bind();
        vao.copyInBuffer(vbo);
        vao.setAttribute();

        vao.unbind();
    }

    void update() {
        glClearColor(0.1,0.1, 0.2, 1.);
        glClear(GL_COLOR_BUFFER_BIT);

        this->key.update();

        this->program.use();
        this->vao.bind();
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
};