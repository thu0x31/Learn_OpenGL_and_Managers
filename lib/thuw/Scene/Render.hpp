#pragma once
#include "First/FirstScene.hpp"
#include "Scene.hpp"
#include "Triangle/TriangleScene.hpp"
#include "thuw/Keyboard/Keyboard.hpp"
#include "thuw/Scene/Manager.hpp"
#include "thuw/GL/Shader/Program.hpp"
#include "thuw/Window/Window.hpp"
#include "Transitioner.hpp"
#include "List.hpp"
#include <functional>
#include <iterator>
#include <thread>
#include <utility>

#ifndef NDEBUG
    #include <iostream>
    #include <ostream>
    #include <cassert>
#endif

namespace thuw::Scene {
    template<class SceneType>
    void Rendering(thuw::Window&& window);
}

template<class SceneType>
void thuw::Scene::Rendering(thuw::Window&& window)
{
    Shader::Program::init();
    Scene::Manager::init<SceneType>();

    // update

    while (window.isClose() == false) // draw 
    {
        Keyboard::PressIf(window.glfwWindow());
        thuw::Scene::Manager::TransitionIf();

        Scene::Manager::currentScene->update();

        window.swapBuffers();
        glfwPollEvents();
    }

    window.close();
}