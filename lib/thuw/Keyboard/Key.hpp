#pragma once
#include "thuw/Window/Window.hpp"
#include <GLFW/glfw3.h>
#include <functional>
#include "boost/signals2.hpp"
#include <functional>

namespace thuw {
    class Key;
}

class thuw::Key {
public:
    boost::signals2::signal<void(GLFWwindow* window, const char key)> signal;
    const char key;

    Key(const char key) noexcept : key(key) {}
    // Key() noexcept {};

    [[nodiscard]] bool isPressed(GLFWwindow* window) noexcept {
        return glfwGetKey(window, this->key);
    }

    // // TODO: key name dehanaku koudou ni awaseru
    // // TODO: emscripten
    // inline void press(const thuw::Window& window, const int key, std::function<void(void)> callback) noexcept {
    //     if(glfwGetKey(window.glfwWwindow(), key) == GLFW_PRESS) {
    //         callback();
    //     }
    // }
};