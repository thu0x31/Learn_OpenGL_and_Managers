#pragma once
#include "thuw/Window/Window.hpp"

namespace thuw::Scene {
    class SceneInterface;
}

//TODO: interface?
class thuw::Scene::SceneInterface {
public:
    //TODO: interface ni motasetakunai 
    const Window targetWindow;

    SceneInterface(const Window& window) : targetWindow(window){};

    virtual constexpr char* name() = 0;
    virtual void setup() {};
    virtual void update() {};
    // virtual void save() {}; //シーンが遷移しても保存したいデータを処理する
};