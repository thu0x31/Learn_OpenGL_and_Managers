#pragma once
#include "thuw/Window/Window.hpp"
#include "Concept.hpp"
#include <array>
#include <functional>
#include <memory>
#include <string>
#include "semimap/semimap.h"

#ifndef NDEBUG
    #include <cassert>
#endif

#define ID(x) []() constexpr { return x; }

namespace thuw::Scene {
    class AbstractScene;
    class SceneInterface;
    class Transitioner;
}

class thuw::Scene::SceneInterface {
public:
    // TODO: connections

    virtual constexpr char* name() = 0;
    virtual void setup() = 0; // TODO:
    virtual void update() = 0;

    // virtual void selected() = 0; // TODO:
    // virtual void save() {}; // TODO: 
};

class thuw::Scene::Transitioner {
private:
    using SemiMap = semi::static_map<std::string, std::shared_ptr<AbstractScene>>;

public:
    static constexpr char* NAME = "";

    std::shared_ptr<AbstractScene> nextScene = nullptr;

    template<typename SceneName>
    constexpr void transition(SceneName name) noexcept {
        assert(name() != Transitioner::NAME);
        assert(SemiMap::contains(name));

        this->nextScene = SemiMap::get(name);
    }

    [[nodiscard]] bool wantTransition() const noexcept {
        return this->nextScene != nullptr;
    }
};

class thuw::Scene::AbstractScene : 
    public SceneInterface, 
    public Transitioner {};