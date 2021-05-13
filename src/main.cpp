#include <algorithm>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Triangle/TriangleScene.hpp"
#include "thuw/Keyboard/Key.hpp"
#include "thuw/Scene/Transitioner.hpp"
#include "thuw/Window/Window.hpp"
#include "thuw/Scene/Scene.hpp"
#include "thuw/Scene/Render.hpp"
#include "thuw/Scene/Initilizer.hpp"
#include "testScene/TestScene.hpp"
#include "First/FirstScene.hpp"
#include <iostream>
#include <memory>

int main() {
    auto&& window = thuw::Window(800,600, "thuthuthu");

    const auto sceneList = thuw::Scene::List(
        new FirstScene(),
        new TriangleScene(),
        new TestScene()
    );

    thuw::Scene::Rendering(std::move(window), std::move(sceneList), TriangleScene::Name);

    return 0;
}