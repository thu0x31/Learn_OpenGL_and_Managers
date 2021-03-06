#pragma once
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iterator>
#include <memory>
#include <unordered_map>
#include <string>
#include <utility>
#include "Scene.hpp"
#include "Concept.hpp"
#include "thuw/Window/Window.hpp"


#ifndef NDEBUG
    #include <iostream>
    #include <ostream>
    #include <cassert>
#endif

namespace thuw::Scene {
    template<thuw::Scene::Concept::ScenePack ...SceneClass>
    class Manager;
}

template<thuw::Scene::Concept::ScenePack ...SceneClass>
class thuw::Scene::Manager {
private:
    std::shared_ptr<AbstractScene> selectedScene = nullptr;
    // TODO: need Tag, Tag = window.title
    using SemiMap = semi::static_map<std::string, std::shared_ptr<AbstractScene>>;

    //TODO: emscripten
    const thuw::Window window;

public:
    Manager(const Window& targetWindow) noexcept : window(targetWindow) {
        (assert(SceneClass::Id() != AbstractScene::Id()), ...);

        ([]{SemiMap::get(SceneClass::Id) = std::make_shared<SceneClass>();}(), ...);
    }

    template<Scene::Concept::Scene Scene>
    auto select() noexcept {
        assert(SemiMap::contains(Scene::Id));
        
        this->selectedScene = SemiMap::get(Scene::Id);
        this->selectedScene->setup();

        return this;
    }

    void update() noexcept {
        // TODO: emscripten
        while (this->window.isClose()) {
            // TODO: key

            if(this->selectedScene->wantTransition()) {
                this->transition(this->selectedScene->nextScene);
            }

            this->selectedScene->update();

            glfwPollEvents();
            this->window.swapBuffers();
        }
        this->window.close();
    }

    auto targetWindow() const noexcept {
        return this->window;
    }

private:
    void transition(std::shared_ptr<AbstractScene>& trasitionScene) noexcept {
        //TODO: preTrandition
        this->selectedScene = std::move(trasitionScene);
        this->selectedScene->setup();
        //TODO: transitioned
    }
};