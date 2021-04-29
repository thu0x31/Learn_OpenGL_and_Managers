#pragma once
#include "Concept.hpp"
#include <array>
#include <functional>
#include <iostream>
#include <memory>
#include <string>

#ifndef NDEBUG
    #include <cassert>
#endif

template<class SceneClass>
concept SceneConcept = requires(SceneClass scene){
    scene.setup();
    scene.update();
};

namespace thuw::Scene {    
    class Interface;
}

class thuw::Scene::Interface {
public:
    virtual void setup() = 0;
    virtual void update() = 0;
};