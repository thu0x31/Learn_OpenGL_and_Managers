#pragma once

#include "thuw/Scene/Scene.hpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <ostream>
#include <utility>

namespace thuw::Scene {
    struct Manager;
}

struct thuw::Scene::Manager {
private:
    static inline std::function<void()> TransitionFunction{[]{}};
public:
    static inline std::unique_ptr<thuw::Scene::Interface> currentScene;

    template<class SceneType>
    static inline  void init() {
        currentScene = std::make_unique<SceneType>();
    }

    template<class SceneType>
    static inline  void Transition() {
        TransitionFunction = []{
            currentScene = std::make_unique<SceneType>();

            #ifndef NDEBUG
                std::cout << "Transitioned: Scene: " << SceneType::Name << std::endl;
            #endif
        };
    }

    static inline void TransitionIf() {
        TransitionFunction();
        TransitionFunction = []{};
    }
};