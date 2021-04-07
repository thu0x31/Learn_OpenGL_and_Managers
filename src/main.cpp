#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Triangle/TriangleScene.hpp"
#include "thuw/Keyboard/Key.hpp"
#include "thuw/Scene/Transitioner.hpp"
#include "thuw/Window/Window.hpp"
#include "thuw/Scene/Scene.hpp"
#include "thuw/Scene/Render.hpp"
#include "First/FirstScene.hpp"
#include <memory>

int main() {
    const auto&& window = thuw::Window(800,600, "test");
    auto&& key = thuw::Key(window);

    auto&& sceneList = std::make_shared<thuw::Scene::List>();
    auto&& transitioner = thuw::Scene::Transitioner(sceneList);//TODO: 
    sceneList->emplace(
        FirstScene(transitioner, key),
        TriangleScene(transitioner, key)
    );

    thuw::Scene::Render(window, sceneList).loop<FirstScene>();
    return 0;
}