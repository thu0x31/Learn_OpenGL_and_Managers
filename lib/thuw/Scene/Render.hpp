#pragma once
#include "First/FirstScene.hpp"
#include "Scene.hpp"
#include "thuw/Keyboard/Key.hpp"
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
    template<class SceneList>
    class Render;
}

template<class SceneList>
class thuw::Scene::Render {
private:
    //TODO: emscripten
    thuw::Window window;
    SceneList sceneList;
public:
    Render(const Window&& targetWindow, const SceneList&& sceneList) 
    : window(targetWindow), sceneList(sceneList) {}

    // TODO: emscripten
    template<class Scene>
    void loop() {
        thuw::Scene::Interface* scene = this->sceneList[Scene::Name];
        scene->setup();

        while (this->window.isClose()) {
            if(this->isWaitSceneTransition()) {
                scene = this->transitionScene();

                #ifndef NDEBUG
                    std::cout << "Transitioned" << std::endl;
                #endif
            }

            Key::Global::Signal(this->window.glfwWwindow());
            
            scene->update();

            this->window.swapBuffers();
            glfwPollEvents();
        }
        this->window.close();
    }

private:
    bool isWaitSceneTransition() const {
        return Scene::TransitionSignal.hasSlot();
    }

    Scene::Interface* transitionScene() {
        const auto&& name = Scene::TransitionSignal.slotList.back()();
        Scene::TransitionConnection.disconnect();

        return this->sceneList[name];
    }
};