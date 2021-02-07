#pragma once
#include "thuw/Scene/Manager.hpp"
#include "thuw/Scene/Scene.hpp"
#include "thuw/Keyboard/Key.hpp"

#ifndef NDEBUG
    #include <iostream>
    #include <ostream>
#endif

class TriangleScene final : public thuw::Scene::SceneInterface {     
public:
    using thuw::Scene::SceneInterface::SceneInterface;
    static constexpr char* NAME = "Triangle";
    constexpr char* name()  { return NAME; }

    void setup() {
        #ifndef NDEBUG
            std::cout << this->name() << std::endl;
        #endif
    }

    void update() {
        // thuw::key::press(this->targetWindow, GLFW_KEY_ESCAPE, [&]{
        //     this->targetWindow.close();
        // });
    }
};