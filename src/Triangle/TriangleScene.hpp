#pragma once


#include "thuw/Scene/Scene.hpp"
#include "thuw/Keyboard/Key.hpp"
#include "thuw/Scene/Transitioner.hpp"
#include "thuw/Vertex/Shader.hpp"
#include "thuw/Vertex/VBO.hpp"
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

    thuw::Vertex::Shader vertexShader;
    thuw::Vertex::VBO vbo;

    TriangleScene(const thuw::Scene::Transitioner& transition , const thuw::Key& key)
     : transition(transition), key(key) , vertexShader(thuw::Vertex::Shader())
    {
        this->key.pressed<thuw::Key::W>([&]{
            this->transition("First");
        });

        std::string currentFilePath(__FILE__);
        currentFilePath.erase(
            currentFilePath.begin() + currentFilePath.rfind("/"),
            currentFilePath.end()
        );

        this->vbo = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
        };
        this->vertexShader = thuw::Vertex::Shader(currentFilePath + "/shader/triangle.vert");
    }

    void setup() {
        #ifndef NDEBUG
            std::cout << this->Name << std::endl;
        #endif

        glClearColor(0.5,0.5, 0.2, 1.);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void update() {
        this->key.update();
    }
};