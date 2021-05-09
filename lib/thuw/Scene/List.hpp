#pragma once
#include "thuw/Scene/Scene.hpp"
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

// VO
template<SceneConcept ...SceneClass>
class thuw::Scene::List {
public:
    const std::unordered_map<std::string, thuw::Scene::Interface*> sceneMap;

    // コピーしてしまうとScene::signalが死ぬのでここでSceneを作る
    List() : sceneMap({{SceneClass::Name, new SceneClass()}... }) {}

    [[nodiscard]] auto operator[](const std::string& name) const {
        assert(List::sceneMap.contains(name));

        return List::sceneMap.at(name);
    }
};