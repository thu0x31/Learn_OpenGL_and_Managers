#pragma once
#include <algorithm>
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
    class Manager;

    namespace Global {
        // TODO: multiwindow taiou sitai, id wo hozon suru?
        std::shared_ptr<Manager> sceneManager = nullptr;
    }

    void transition(const char* sceneName) noexcept;
}

class thuw::Scene::Manager {
private:
    std::shared_ptr<SceneInterface> selectedScene;
    //TODO: semimap
    std::unordered_map<const char*, std::shared_ptr<SceneInterface>> sceneMap;

    //TODO: emscripten
    const thuw::Window window;

public:
    Manager(const Window& targetWindow) noexcept : window(targetWindow) {};

    template<thuw::Scene::Concept::ScenePack ...Scene>
    static inline auto create(const Window& targetWindow) noexcept {
        #ifndef NDEBUG
            assert(Global::sceneManager == nullptr);
        #endif

        Global::sceneManager = std::make_shared<Manager>(targetWindow);
        // Global::sceneManager->emplaceScene<Scene...>();
        (Global::sceneManager->sceneMap.emplace(Scene::NAME, std::make_shared<Scene>(targetWindow)), ...);
        return Global::sceneManager;
    }

    // auto targetingWindow(const std::shared_ptr<thuw::Window>& window) noexcept {
    //     this->window = window;
    //     return this;
    // }

    template<Concept::Scene Scene>
    auto select() noexcept {
        #ifndef NDEBUG
            assert(this->sceneMap.contains(Scene::NAME));
        #endif
        
        this->selectedScene = this->sceneMap[Scene::NAME];
        this->selectedScene->setup();

        return this;
    }

    auto select(const char* sceneName) noexcept {
        #ifndef NDEBUG
            assert(this->sceneMap.contains(sceneName));
        #endif
        
        this->selectedScene = this->sceneMap[sceneName];
        this->selectedScene->setup();

        return this;
    }

    void update() const noexcept {
        while (this->window.isClose()) {
            this->selectedScene->update();
            
            glfwPollEvents();
            this->window.swapBuffers();
        }
        glfwTerminate();
        this->window.close();
    }

    // template<Concept::ScenePack ...Scene>
    // void emplaceScene() noexcept {
    //     (this->sceneMap.emplace(Scene::NAME, std::make_shared<Scene>()), ...);
    // }

    auto targetWindow() const noexcept {
        return this->window;
    }
};

// ----------------------------------------------------------

inline void thuw::Scene::transition(const char* sceneName) noexcept {
    //TODO: preTrandition
    Global::sceneManager->select(sceneName);
    //TODO: transitioned
}
