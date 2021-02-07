#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Triangle/TriangleScene.hpp"
#include "thuw/Window/Window.hpp"
#include "thuw/Scene/Scene.hpp"
#include "thuw/Scene/Manager.hpp"
#include "First/FirstScene.hpp"
#include <memory>

int main() {
    const auto&& window = thuw::Window(800,600);

    //TODO: window emscripten
    thuw::Scene::Manager::create<
            FirstScene,
            TriangleScene
        >(window)
    // ->targetingWindow(window) 
    ->select(FirstScene::NAME)
    ->update();

    return 0;
}