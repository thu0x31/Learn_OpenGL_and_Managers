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
    SceneList sceneList;
public:
    Render(const Window& targetWindow, SceneList& sceneList) 
    : window(targetWindow), sceneList(sceneList) {}

    // TODO: emscripten
    template<class Scene>
    void loop() {
        this->sceneList.choose(Scene::Name)->setup();

        while (this->window.isClose()) {
            // this->sceneList.current()->key->update(this->window.glfwWwindow());
            this->sceneList.current()->update();

            this->window.swapBuffers();
            glfwPollEvents();
        }
        this->window.close();
    }

    // template<KeyboardConcept Scene>
    // void updateKeyboard(const Scene& scene) {
    //     scene.key->update();
    // }

    // template<class Scene>
    // void updateKeyboard(Scene& scene) {}
};