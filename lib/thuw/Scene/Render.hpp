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
    class Render;
}

class thuw::Scene::Render {
private:
    //TODO: emscripten
    const thuw::Window window;
    const std::shared_ptr<thuw::Scene::List> sceneList;
public:
    Render(const Window& targetWindow, std::shared_ptr<thuw::Scene::List>& sceneList) noexcept
    : window(targetWindow), sceneList(sceneList) {}

    // TODO: emscripten
    template<class Scene>
    void loop() noexcept {
        this->sceneList->choose(Scene::Name)->setup();

        while (this->window.isClose()) {
            // TODO: key

            this->sceneList->current()->update();

            glfwPollEvents();
            this->window.swapBuffers();
        }
        this->window.close();
    }
};