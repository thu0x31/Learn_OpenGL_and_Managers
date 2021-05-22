#include <array>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <initializer_list>
#include <thread>
#include "Triangle/TriangleScene.hpp"
#include "thuw/Vec.hpp"
#include "thuw/Window/Window.hpp"
#include "thuw/Scene/Scene.hpp"
#include "thuw/Scene/Render.hpp"
#include "First/FirstScene.hpp"

int main() {
    auto&& window = thuw::Window(800,600, "thuthuthu");
    thuw::Scene::Rendering<FirstScene>(std::move(window));

    return 0;
}