#pragma once

#include "glad/glad.h"
#include "thuw/Scene/Scene.hpp"
#include "thuw/Keyboard/Keyboard.hpp"
#include "thuw/Scene/Transitioner.hpp"
#include "thuw/Shader/Vertex.hpp"
#include "thuw/Shader/Fragment.hpp"
#include "thuw/Shader/Program.hpp"
#include "thuw/Buffer/VBO.hpp"
#include "thuw/Buffer/EBO.hpp"
#include "thuw/Signal/Signal.hpp"
#include "thuw/Geometry/Geometry.hpp"
#include "thuw/VAO.hpp"
#include "thuw/Vec.hpp"
#include "thuw/Vertices.hpp"
#include <algorithm>
#include <array>
#include <string>
#include <utility>
#include <vector>


#ifndef NDEBUG
    #include <iostream>
    #include <ostream>
#endif

class TriangleScene final : public thuw::Scene::Interface {
public:
    static constexpr auto Name = "Triangle";
    thuw::Keyboard keyboard;
    thuw::Keyboard::Connection keyConnection;
    thuw::Keyboard::Connection keyConnection3;

    // thuw::Geometry geo;

    TriangleScene() 
    {
        glClearColor(0.1,0.1, 0.2, 1.);
        glClear(GL_COLOR_BUFFER_BIT);

        // TODO: fix
        std::string currentFilePath(__FILE__);
        currentFilePath.erase(
            currentFilePath.begin() + currentFilePath.rfind("/"),
            currentFilePath.end()
        );

        const auto&& geo = thuw::Geometry(
            thuw::Vertices{
                {0.5f, 0.5f, 0.0f},
                {0.5f, -0.5f, 0.0f},
                {-0.5f, -0.5f, 0.0f},
                {-0.5f,  0.5f, 0.0f}},
            thuw::Buffer::EBO{
                0, 1, 3,
                1, 2, 3
            },
            thuw::Shader::Vertex(currentFilePath + "/shader/triangle.vert"),
            thuw::Shader::Fragment(currentFilePath + "/shader/triangle.frag")
        );

        this->keyConnection = this->keyboard.pressed<thuw::Key::A>([geometry = std::move(geo)] {
            geometry.draw();
        });

        this->keyConnection3 = this->keyboard.pressed<thuw::Key::Q>([&] {
            std::cout << "test" << std::endl;
        });
    }

    void update() {
    }
};