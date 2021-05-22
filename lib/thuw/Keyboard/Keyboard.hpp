#pragma once
#include "SPSCQueue/include/rigtorp/SPSCQueue.h"
#include "thuw/Window/Window.hpp"
#include <GLFW/glfw3.h>
#include "thuw/Keyboard/Key.hpp"
#include "thuw/Signal/Signal.hpp"
#include <algorithm>
#include <functional>
#include <initializer_list>
#include <utility>
#include <vector>

namespace thuw {
    class Keyboard;
}

// Key<Key enum>{size}
// Key<Key enum>::Signal
// Key<Key enum>::Connection

// Key<enum>::Press -> connection
//      scene "n" o-- "1" connection
//      or Keyboard "n" o-- "1" connection

class thuw::Keyboard {
public:
    using PressIfConnection = thuw::Signal<void(GLFWwindow*)>::Connection;
    static inline thuw::Signal<void(GLFWwindow*)> PressIf;

    // static inline rigtorp::SPSCQueue<std::function<void()>> Queue{100};

    using Connection = PressIfConnection;

    Keyboard() = default;

    template<const int Key>
    [[nodiscard]] Connection pressed(std::function<void()>&& callback)
    {
        PressIfConnection&& connection = Keyboard::PressIf.connect(
            [callback = std::move(callback)] (GLFWwindow* window) {
            if(GLFW_PRESS == glfwGetKey(window, Key)) {
                #ifndef NDEBUG
                    std::cout << "key press: " << glfwGetKeyName(Key, 0) << std::endl;
                #endif

                callback();
            }
        });

        #ifndef NDEBUG
            std::cout << "Connected : GetPressKey" << std::endl;
        #endif

        return Keyboard::Connection(std::move(connection));
    }
};