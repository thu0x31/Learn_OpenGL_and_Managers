#pragma once
#include "Scene.hpp"
#include "thuw/Scene/List.hpp"
#include <iostream>
#include <memory>
#include <ostream>

namespace thuw::Scene{
    struct Transitioner;
}

struct thuw::Scene::Transitioner {
    std::shared_ptr<thuw::Scene::List> sceneList;

public:
    Transitioner(const std::shared_ptr<thuw::Scene::List>& sceneList) : sceneList(sceneList) {}

    void operator()(const std::string& name) noexcept {
        this->sceneList->choose(name)->setup();
    }

    void transition(const std::string& name) noexcept {
        this->sceneList->choose(name)->setup();
    }
};