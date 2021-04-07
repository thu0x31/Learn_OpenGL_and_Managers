#pragma once
#include <cassert>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <functional>
#include <iostream>
#include <string>

namespace thuw{
    class Window;
}

class thuw::Window {
private:
    GLFWwindow* window;

public:
    Window(const GLuint width, const GLuint height,
            const std::string& title = "thuthuthu",
            const int majorVersion = 3, const int minorVersion = 3) noexcept
    {
        glfwInit();
        this->contextVersion(majorVersion, minorVersion);
        
        #ifdef __APPLE__
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        #endif
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        this->window = this->createWindow(width, height, title);
        this->setCallbacks();
    }

private:
    void contextVersion(const int majorVersion, const int minorVersion) const noexcept {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, majorVersion);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minorVersion);
    }

    [[nodiscard]] GLFWwindow* createWindow(const GLuint width, const GLuint height, const std::string& title) noexcept {
        const auto&& window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
        assert(window != nullptr);
        glfwMakeContextCurrent(window);

        const auto&& isLoaded = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        assert(isLoaded);

        glViewport(0, 0, width, height);

        return window;
    }

    void setCallbacks() noexcept {
        glfwSetFramebufferSizeCallback(this->window, Window::resize);
    }

public:
    [[nodiscard]] bool isClose() const noexcept {
        return !glfwWindowShouldClose(this->window);
    }

    void swapBuffers() const noexcept {
        glfwSwapBuffers(this->window);
    }
    
    void close() const noexcept {
        glfwSetWindowShouldClose(this->window, true);
    }

    [[nodiscard]] auto glfwWwindow() const noexcept {
        return this->window;
    }

private:
    static void resize(GLFWwindow* , int width, int height) noexcept {
        glViewport(0, 0, width, height);
    }
};