#pragma once
#include "thuw/Scene/Manager.hpp"
#include "thuw/Scene/Scene.hpp"
#include "thuw/Keyboard/Key.hpp"

#ifndef NDEBUG
    #include <iostream>
    #include <ostream>
#endif

class TriangleScene final : public thuw::Scene::AbstractScene {     
public:
    static constexpr auto Id = SceneId("Triangle");
    constexpr const char* name()  { return Id(); }

    void setup() {
        #ifndef NDEBUG
            std::cout << this->name() << std::endl;
        #endif

        glClearColor(0.5,0.5, 0.2, 1.);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void update() {
        // thuw::Key::press(GLFW_KEY_ESCAPE, [&]{
        //     this->targetWindow.close();
        // });
        this->transition(SceneId("First"));
    }
};