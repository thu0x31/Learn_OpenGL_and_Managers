#pragma once
#include "thuw/Scene/Scene.hpp"
#include <cassert>
#include <initializer_list>
#include <string>
#include <utility>
#include <memory>
#include <unordered_map>

namespace thuw::Scene {
    class List;
}

class thuw::Scene::List {
private:
    std::shared_ptr<SceneInterface> currentScene;
    std::unordered_map<std::string, std::shared_ptr<SceneInterface>> sceneMap;

public:
    List() {
    }

    template<typename ...Scene>
    void emplace(const Scene ...scene) {
        (this->sceneMap.emplace(Scene::Name, std::make_shared<Scene>(scene)), ...);
    }

    [[nodiscard]] auto operator[](const std::string name) {
        assert(this->sceneMap.contains(name));

        return this->sceneMap[name];
    }

    [[nodiscard]] auto current() const {
        assert(this->currentScene != nullptr);

        return this->currentScene;
    }

    auto choose(const std::string name) {
        assert(this->sceneMap.contains(name));

        this->currentScene = this->sceneMap[name];
        return this->current();
    }
};