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

    thuw::Signal<void(char)> testSignal;
    thuw::Connection<void(char)> testConnection;
    thuw::Connection<void(char)> testConnection2;

    thuw::Signal<void()> testSignalVoid;
    thuw::Connection<void()> testConnection3;

    thuw::Signal<int()> testSignalRNum;
    thuw::Connection<int()> testConnection4;

    thuw::Signal<int(char)> testSignalNN;
    thuw::Connection<int(char)> testConnection5;

    thuw::Signal<int(char, int, int, int)> testSignal6;
    thuw::Connection<int(char)> testConnection6;

    TestScene() {
        this->testConnection = this->testSignal.connect([](char a){
            return 1;
        });

        this->testConnection2 = this->testSignal.connect([](char a){
            return 2;
        });

        this->testConnection3 = this->testSignalVoid.connect([]{});

        this->testConnection4 = this->testSignalRNum.connect([]{return 1;});

        this->testConnection5 = this->testSignalNN.connect([](char c){return 1;});
    }

    void setup() {
        this->testSignal('a');

        char testC = 'i';
        this->testSignal(testC);
        this->testSignal(std::move(testC));

        this->testSignalVoid();

        const auto list = this->testSignalRNum.execute<std::list>();

        const auto list2 = this->testSignalRNum.execute<std::vector>();

        const auto&& list3(this->testSignalNN.execute<std::list>('a'));

        for(const auto& c : list) {
            std::cout << c << std::endl;
        }

        this->testConnection.disconnect();
        this->testConnection2.disconnect();
        this->testConnection3.disconnect();
        this->testConnection4.disconnect();
        this->testConnection5.disconnect();
    }

    void update() {
        
    }
};