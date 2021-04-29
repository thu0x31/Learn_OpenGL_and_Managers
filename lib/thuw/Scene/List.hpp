#pragma once
#include "thuw/Scene/Scene.hpp"
#include <cassert>
#include <initializer_list>
#include <string>
#include <utility>
#include <memory>
#include <unordered_map>

namespace thuw::Scene {
    template<SceneConcept ...SceneClass>
    struct List;
}

template<SceneConcept ...SceneClass>
struct thuw::Scene::List {
    static inline std::shared_ptr<SceneInterface> currentScene; // TODO: 分離できるはず
    static const inline std::unordered_map<std::string, std::shared_ptr<thuw::Scene::SceneInterface>>
        sceneMap = {
                {SceneClass::Name , std::make_shared<SceneClass>()}... 
            };

    [[nodiscard]] auto operator[](const std::string& name) {
        assert(List::sceneMap.contains(name));

        return List::sceneMap.at(name);
    }

    [[nodiscard]] auto current() const {
        assert(List::currentScene != nullptr);

        return List::currentScene;
    }

    auto choose(const std::string& name) {
        assert(List::sceneMap.contains(name));

        List::currentScene = List::sceneMap.at(name);
        
        return List::currentScene;
    }
};