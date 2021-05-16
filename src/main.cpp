#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <thread>
#include "Triangle/TriangleScene.hpp"
#include "thuw/Window/Window.hpp"
#include "thuw/Scene/Scene.hpp"
#include "thuw/Scene/Render.hpp"
#include "First/FirstScene.hpp"

#include "SPSCQueue/include/rigtorp/SPSCQueue.h"

int main() {
    auto&& window = thuw::Window(800,600, "thuthuthu");
    thuw::Scene::Rendering<FirstScene>(std::move(window));

    return 0;
}