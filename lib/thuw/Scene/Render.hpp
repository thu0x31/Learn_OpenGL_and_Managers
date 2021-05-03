#pragma once
#include "First/FirstScene.hpp"
#include "Scene.hpp"
#include "thuw/Window/Window.hpp"
#include "Transitioner.hpp"
#include "List.hpp"

#ifndef NDEBUG
    #include <iostream>
    #include <ostream>
    #include <cassert>
#endif

namespace thuw::Scene {
    template<class SceneList>
    class Render;
}

template<class SceneList>
class thuw::Scene::Render {
private:
    //TODO: emscripten
    const thuw::Window window;
    const SceneList sceneList;
public:
    Render(const Window& targetWindow, SceneList& sceneList) 
    : window(targetWindow), sceneList(sceneList) {}

    // TODO: emscripten
    template<class Scene>
    void loop() {
        auto&& scene = this->sceneList[Scene::Name];
        scene->setup();

        while (this->window.isClose()) {
            scene->update();

            this->window.swapBuffers();
            glfwPollEvents();
        }
        this->window.close();
    }
};