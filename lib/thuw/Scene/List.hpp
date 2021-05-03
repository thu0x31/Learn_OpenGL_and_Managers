#pragma once
#include "thuw/Scene/Scene.hpp"
#include "thuw/Scene/Transitioner.hpp"
#include <cassert>
#include <functional>
#include <initializer_list>
#include <string>
#include <utility>
#include <memory>
#include <unordered_map>

namespace thuw::Scene {
    template<SceneConcept ...SceneClass>
    class List;
}

template<SceneConcept ...SceneClass>
class thuw::Scene::List {
public:
    using SceneList = std::unordered_map<std::string, std::shared_ptr<thuw::Scene::Interface>>;
    const SceneList sceneMap;

    List(SceneClass&& ...scene) : sceneMap({{SceneClass::Name , std::make_shared<SceneClass>(scene)}... }) {}

    [[nodiscard]] auto operator[](const std::string& name) const {
        assert(List::sceneMap.contains(name));

        return List::sceneMap.at(name);
    }
};