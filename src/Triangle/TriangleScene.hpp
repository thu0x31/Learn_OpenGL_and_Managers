#pragma once

#include "glad/glad.h"
#include "thuw/Scene/Scene.hpp"
#include "thuw/Keyboard/Keyboard.hpp"
#include "thuw/Scene/Transitioner.hpp"
#include "thuw/GL/Shader/Vertex.hpp"
#include "thuw/GL/Shader/Fragment.hpp"
#include "thuw/GL/Shader/Program.hpp"
#include "thuw/GL/Buffer/VBO.hpp"
#include "thuw/GL/Buffer/EBO.hpp"
#include "thuw/Signal/Signal.hpp"
#include "thuw/Shapes/Triangle/Triangle.hpp"
#include "thuw/GL/VAO.hpp"
#include "thuw/Math/Vec/Vec.hpp"
#include "thuw/Math/Vec/Vertices.hpp"
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

        const auto&& geo = thuw::Shapes::Triangle(thuw::Vec3{0,0,0});

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