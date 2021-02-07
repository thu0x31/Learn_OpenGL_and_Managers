#pragma once
#include "thuw/Window/Window.hpp"
#include <GLFW/glfw3.h>
#include <functional>

namespace thuw::key {

    void release(const thuw::Window& window, const int key, std::function<void(void)> callback) {
        if(glfwGetKey(window.glfwWwindow(), key) == GLFW_RELEASE) {
            callback();
        }
    }

    // TODO: key name dehanaku koudou ni awaseru
    // TODO: emscripten
    void press(const thuw::Window& window, const int key, std::function<void(void)> callback) noexcept {
        if(glfwGetKey(window.glfwWwindow(), key) == GLFW_PRESS) {
            callback();
        }
    }

    // void repeat(const int key, std::function<void(void)> callback) {

    // }
};