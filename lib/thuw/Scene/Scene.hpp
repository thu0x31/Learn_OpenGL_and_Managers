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

#define SceneId(x) []() constexpr { return x; }

namespace thuw::Scene {
    class AbstractScene;
    class SceneInterface;
    class Transitioner;
}

class thuw::Scene::SceneInterface {
public:
    // TODO: connections

    virtual constexpr const char* name() = 0;
    virtual void setup() = 0; // TODO:
    virtual void update() = 0;

    // virtual void selected() = 0; // TODO:
    // virtual void save() {}; // TODO: 
};

class thuw::Scene::Transitioner {
private:
    using StaticMap = semi::static_map<std::string, std::shared_ptr<AbstractScene>>;

public:
    static constexpr auto Id = SceneId("");

    std::shared_ptr<AbstractScene> nextScene = nullptr;

    template<typename SceneId>
    constexpr void transition(SceneId id) noexcept {
        assert(id() != Transitioner::Id());
        assert(StaticMap::contains(id));

        this->nextScene = StaticMap::get(id);
    }

    [[nodiscard]] bool wantTransition() const noexcept {
        return this->nextScene != nullptr;
    }
};

// TODO: template de hituyouna system dakece kousei dekiru youni suru
class thuw::Scene::AbstractScene : 
    public SceneInterface, 
    public Transitioner {};