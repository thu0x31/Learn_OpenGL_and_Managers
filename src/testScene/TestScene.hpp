#pragma once

#include "thuw/Scene/Scene.hpp"
#include "thuw/Signal/Signal.hpp"
#include <functional>
#include <iostream>
#include <iterator>
#include <ostream>

// TODO: test Framework
class TestScene final : public thuw::Scene::Interface {
public:
    static constexpr auto Name = "Test";

    TestScene() {
        
    }

    void setup() {
        
    }

    void update() {
        
    }
};