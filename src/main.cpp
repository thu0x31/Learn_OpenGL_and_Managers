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
    const auto&& window = thuw::Window(800,600, "test");

    const auto&& sceneList = thuw::Scene::List<
        FirstScene,
        TriangleScene,
        TestScene
    >();

    thuw::Scene::Render(std::move(window), std::move(sceneList)).loop<TestScene>();
    // thuw::Scene::Render(std::move(window), std::move(sceneList)).loop<TriangleScene>();

    return 0;
}