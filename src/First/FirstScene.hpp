#pragma once
#include "thuw/Scene/Scene.hpp"
#include "thuw/Scene/Manager.hpp"
#include "thuw/Keyboard/Key.hpp"
#include <GLFW/glfw3.h>

#ifndef NDEBUG
    #include <iostream>
    #include <ostream>
#endif

class FirstScene final : public thuw::Scene::SceneInterface {
public:
    // TODO: interface no constructa wo yobidasubeki dehanai kamo?
    using thuw::Scene::SceneInterface::SceneInterface;
    static constexpr char* NAME = "First";
    constexpr char* name() { return NAME; }
    
    void setup() {
        #ifndef NDEBUG
            std::cout << this->name() << std::endl;
        #endif
        glClearColor(0.2,0.5, 0.2, 1.);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void update() {
        thuw::key::press(this->targetWindow, GLFW_KEY_ESCAPE, []{
            thuw::Scene::transition("Triangle");
        });
    }

};