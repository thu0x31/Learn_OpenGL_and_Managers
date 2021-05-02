#pragma once
#include "Scene.hpp"
#include <functional>
#include <iostream>
#include <memory>
#include <ostream>

namespace thuw::Scene {
    class Transitioner;
    void transition(const std::string& name);
}

// TODO: 
class thuw::Scene::Transitioner {
public:
    using TransitionFunc = std::function<std::shared_ptr<Scene::Interface>(const std::string&)>;
    static inline TransitionFunc transition = nullptr;

    Transitioner(TransitionFunc transition) {
        Transitioner::transition = transition;
    }
};

void thuw::Scene::transition(const std::string& name) {
    assert(thuw::Scene::Transitioner::transition != nullptr);

    thuw::Scene::Transitioner::transition(name)->setup();
}