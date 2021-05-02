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
    struct List;
}

template<SceneConcept ...SceneClass>
struct thuw::Scene::List {
    static inline auto choose(const std::string& name) {
        assert(List::sceneMap.contains(name));

        List::currentScene = List::sceneMap.at(name);
        
        return List::currentScene;
    }
    
    [[nodiscard]] auto operator[](const std::string& name) const {
        assert(List::sceneMap.contains(name));

        return List::sceneMap.at(name);
    }

    static inline auto current() {
        assert(List::currentScene != nullptr);

        return List::currentScene;
    }

    template<class Scene>
    static inline auto makeScene() {
        thuw::Scene::Transitioner([](const std::string &name){
            return List::choose(name);
        });

        // TODO: 
        const auto&& scene = std::make_shared<Scene>();
        return scene;
    }

    static inline std::shared_ptr<Scene::Interface> currentScene; // TODO: windowへ分離できるはず

    using SceneList = std::unordered_map<std::string, std::shared_ptr<thuw::Scene::Interface>>;
    static const inline SceneList sceneMap = {
                {SceneClass::Name , makeScene<SceneClass>()}... 
            };
};