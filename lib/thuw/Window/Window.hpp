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
    const GLuint width;
    const GLuint height;
    const std::string title;

    Window(const GLuint width, const GLuint height,
            const std::string& title = "thuthuthu",
            const int majorVersion = 3, const int minorVersion = 3) 
            : width(width), height(height), title(title)
    {
        glfwInit();
        this->contextVersion(majorVersion, minorVersion);
        
        #ifdef __APPLE__
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        #endif
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        this->window = this->createWindow(this->width, this->height, this->title);
        this->setCallbacks();
    }

private:
    void contextVersion(const int majorVersion, const int minorVersion) const {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, majorVersion);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minorVersion);
    }

    [[nodiscard]] GLFWwindow* createWindow(const GLuint width, const GLuint height, const std::string& title) {
        const auto&& window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
        assert(window != nullptr);
        glfwMakeContextCurrent(window);

        const auto&& isLoaded = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        assert(isLoaded);

        glViewport(0, 0, width, height);

        return window;
    }

    void setCallbacks() {
        glfwSetFramebufferSizeCallback(this->window, Window::resize);
    }

public:
    [[nodiscard]] bool isClose() const {
        return !glfwWindowShouldClose(this->window);
    }

    void swapBuffers() const {
        glfwSwapBuffers(this->window);
    }
    
    void close() const {
        glfwSetWindowShouldClose(this->window, true);
    }

    [[nodiscard]] auto glfwWwindow() const {
        return this->window;
    }

private:
    static void resize(GLFWwindow* , int width, int height) {
        glViewport(0, 0, width, height);
    }
};