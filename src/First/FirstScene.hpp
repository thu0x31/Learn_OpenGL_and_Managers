#pragma once
#include "Triangle/TriangleScene.hpp"
#include "glad/glad.h"
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
    static constexpr auto Name = "First";// TODO: 存在を保証されない
    thuw::Scene::Transitioner transition;
    thuw::Key key;

    FirstScene(const thuw::Scene::Transitioner& transition , const thuw::Key& key)
     : transition(transition), key(key)
    {
        this->key.pressed<thuw::Key::E>([&]{
            this->transition("Triangle");
        });
    }
    
    void setup() {
        #ifndef NDEBUG
            std::cout << this->Name << std::endl;
        #endif
        glClearColor(0.2,0.5, 0.2, 1.);
        glClear(GL_COLOR_BUFFER_BIT);

    }

    void update() {
        this->key.update();

        unsigned int VBO;
        glGenBuffers(1, &VBO);
    }
};