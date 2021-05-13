#pragma once
#include "First/FirstScene.hpp"
#include "Scene.hpp"
#include "thuw/Keyboard/Key.hpp"
#include "thuw/Shader/Program.hpp"
#include "thuw/Window/Window.hpp"
#include "Transitioner.hpp"
#include "List.hpp"
#include <iterator>

#ifndef NDEBUG
    #include <iostream>
    #include <ostream>
    #include <cassert>
#endif

namespace thuw::Scene {
    template<class Window, class SceneList, class SelectSceneName>
    void Rendering(Window&& window, SceneList&& sceneList, SelectSceneName&& name);
}

template<class Window, class SceneList, class SelectSceneName>
void thuw::Scene::Rendering(Window&& window, SceneList&& sceneList, SelectSceneName&& name) {
    thuw::Shader::initProgram();

    thuw::Scene::Interface* scene = sceneList[name];
    scene->setup();

    while (window.isClose() == false) {

        // TODO: prototype
        if(Scene::Transitioner::WantTransition()) {
            scene = sceneList[Scene::Transitioner::ToName()];
            scene->setup();
            Scene::Transitioner::resetToName();

           #ifndef NDEBUG
                std::cout << "Transitioned" << std::endl;
            #endif
        }

        Key::Global::Press(window.glfwWwindow());
         
        scene->update();

        window.swapBuffers();
        glfwPollEvents();
    }

    window.close();
}