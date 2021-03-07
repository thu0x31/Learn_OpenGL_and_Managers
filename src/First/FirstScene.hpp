#pragma once
#include "Triangle/TriangleScene.hpp"
#include "thuw/Scene/Scene.hpp"
#include "thuw/Scene/Manager.hpp"
#include "thuw/Keyboard/Key.hpp"
#include <GLFW/glfw3.h>

#ifndef NDEBUG
    #include <iostream>
    #include <ostream>
#endif

class FirstScene final : public thuw::Scene::AbstractScene {
public:
    static constexpr auto Id = SceneId("First");
    constexpr const char* name()  { return Id(); }
    // thuw::Key key;

    static constexpr int id = 0;
    
    void setup() {
        #ifndef NDEBUG
            std::cout << this->name() << std::endl;
        #endif
        glClearColor(0.2,0.5, 0.2, 1.);
        glClear(GL_COLOR_BUFFER_BIT);

        // key("e", []{
        //     this->transition("Triangle");
        // })
        // this->key = thuw::Key('e');
    }

    void update() {
        this->transition(TriangleScene::Id);
    }
};