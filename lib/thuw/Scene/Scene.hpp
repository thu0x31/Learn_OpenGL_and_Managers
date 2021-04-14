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

namespace thuw::Scene {    
    class SceneInterface;
}

class thuw::Scene::SceneInterface {
public:
    virtual void setup() = 0;
    virtual void update() = 0;
};