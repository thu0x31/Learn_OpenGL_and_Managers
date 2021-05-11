#pragma once
#include "Scene.hpp"
#include "thuw/Signal/Signal.hpp"
#include <GLFW/glfw3.h>
#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <ostream>
#include <string>
#include <unordered_map>

namespace thuw::Scene {

    // TODO: multi Window
    thuw::Signal<std::string()> TransitionSignal;
    thuw::Signal<std::string()>::Connection TransitionConnection;

    template<typename ScneName>
    void Transition(ScneName&& sceneName);
}

template<typename ScneName>
void thuw::Scene::Transition(ScneName&& sceneName) {
    Scene::TransitionConnection = Scene::TransitionSignal.connect(
        [sceneName = std::move(sceneName)] () constexpr {
            return sceneName;
        }
    );
}