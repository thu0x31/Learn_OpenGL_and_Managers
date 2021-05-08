#pragma once

#include "thuw/Scene/Scene.hpp"
#include "thuw/Signal/Signal.hpp"
#include <functional>
#include <iostream>
#include <iterator>
#include <ostream>

class TestScene final : public thuw::Scene::Interface {
public:
    static constexpr auto Name = "Test";

    thuw::Connection<int(int, int)> testConnection;
    thuw::Connection<int(int, int)> testConnection2;
    thuw::Signal<int(int, int)> testSignal;

    TestScene() {
        this->testConnection = this->testSignal.connect([](int a, int b){
            return a + b;
        });

        this->testConnection2 = this->testSignal.connect([](int a, int b){
            return a * b;
        });
    }

    void setup() {
        // this->testSignal('a');

        const auto&& list(this->testSignal.execute<std::list>(1, 3));

        for(const auto& c : list) {
            std::cout << c << std::endl;
        }
    }

    void update() {
        
    }
};