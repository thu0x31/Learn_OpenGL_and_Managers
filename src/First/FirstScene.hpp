#pragma once
#include "Triangle/TriangleScene.hpp"
#include "glad/glad.h"
#include "thuw/Scene/List.hpp"
#include "thuw/Scene/Manager.hpp"
#include "thuw/Scene/Scene.hpp"
#include "thuw/Keyboard/Keyboard.hpp"
#include "thuw/Scene/Transitioner.hpp"
#include <functional>
#include "thuw/Signal/Signal.hpp"

#ifndef NDEBUG
    #include <iostream>
    #include <ostream>
#endif

class FirstScene final : public thuw::Scene::Interface {
public:
    static constexpr auto Name = "First";
    thuw::Keyboard key;
    thuw::Keyboard::Connection keyConnection;

    FirstScene()
    {
        this->keyConnection = this->key.pressed<thuw::Key::E>([] {
            thuw::Scene::Manager::Transition<TriangleScene>();
        });

        // TODO: draw thread
        glClearColor(0.2,0.5, 0.2, 1.);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void update() {
        
    }
};