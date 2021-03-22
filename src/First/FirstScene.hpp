#pragma once
#include "Triangle/TriangleScene.hpp"
#include "thuw/Scene/List.hpp"
#include "thuw/Scene/Scene.hpp"
#include "thuw/Keyboard/Key.hpp"
#include "thuw/Scene/Transitioner.hpp"

#ifndef NDEBUG
    #include <iostream>
    #include <ostream>
#endif

class FirstScene final : public thuw::Scene::SceneInterface {
public:
    static constexpr auto Name = "First";
    thuw::Scene::Transitioner transition;

    FirstScene(thuw::Scene::Transitioner transition) : transition(transition) {}
    
    void setup() noexcept {
        #ifndef NDEBUG
            std::cout << this->Name << std::endl;
        #endif
        glClearColor(0.2,0.5, 0.2, 1.);
        glClear(GL_COLOR_BUFFER_BIT);

        // thuw::Key::press(GLFWwindow *window);
    }

    void update() {
        this->transition("Triangle");
    }
};