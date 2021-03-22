#pragma once
#include "thuw/Scene/Scene.hpp"
#include "thuw/Keyboard/Key.hpp"

#ifndef NDEBUG
    #include <iostream>
    #include <ostream>
#endif

class TriangleScene final : public thuw::Scene::SceneInterface {
public:
    static constexpr auto Name = "Triangle";

    void setup() {
        #ifndef NDEBUG
            std::cout << this->Name << std::endl;
        #endif

        glClearColor(0.5,0.5, 0.2, 1.);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void update() {
    }
};