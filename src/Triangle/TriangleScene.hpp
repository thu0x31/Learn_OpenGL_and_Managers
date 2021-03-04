#pragma once
#include "thuw/Scene/Manager.hpp"
#include "thuw/Scene/Scene.hpp"
#include "thuw/Keyboard/Key.hpp"

#ifndef NDEBUG
    #include <iostream>
    #include <ostream>
#endif

class TriangleScene final : public thuw::Scene::AbstructScene {     
public:
    static constexpr char* NAME = "Triangle";
    constexpr char* name()  { return NAME; }

    void setup() {
        #ifndef NDEBUG
            std::cout << this->name() << std::endl;
        #endif

        glClearColor(0.5,0.5, 0.2, 1.);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void update() {
        // thuw::Key::press(this->targetWindow, GLFW_KEY_ESCAPE, [&]{
        //     this->targetWindow.close();
        // });
        this->transition(ID("First"));
    }
};