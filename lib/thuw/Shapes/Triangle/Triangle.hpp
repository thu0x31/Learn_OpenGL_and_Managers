#pragma once

#include "thuw/GL/VAO.hpp"
#include "thuw/Attribute/Point.hpp"
#include "thuw/Math/Vec/Vec.hpp"
#include "thuw/Math/Vec/Vertices.hpp"
#include "thuw/GL/Shader/Program.hpp"
#include "thuw/GL/Shader/Fragment.hpp"
#include "thuw/GL/Shader/Vertex.hpp"
#include <filesystem>
#include <vector>

namespace thuw::Shapes {
    class Triangle;
}

class thuw::Shapes::Triangle {
public:
    thuw::Point position{thuw::Vec4{0, 0, 0, 0}};
    std::vector<thuw::Point> points;
    float scale = 1;
    float rotate = 0;

    static constexpr auto Top = Vec3{0.f, 0.5f, 0.f};
    static constexpr auto Left = Vec3{-0.5f, -0.5f, 0.f};
    static constexpr auto Right = Vec3{0.5f, -0.5f, 0.f};

    thuw::VAO vao;

    // bounding box
    // color

    template<Concepts::Vec Vec>
    Triangle(Vec&& pos) : position(pos) {
        // TODO: constexpr triangale -> transform matrix -> scale matrix

        // scale matrix

        constexpr auto vertices = thuw::Vertices<3,3>{Top, Left, Right};
        const auto&& ebo = thuw::Buffer::EBO{0,1,2};
        
        namespace fs = std::filesystem;
        const auto path = fs::absolute("lib/thuw/Shapes/Triangle").generic_string();
        const auto&& vertexShader= thuw::Shader::Vertex(path + "/triangle.vert");
        const auto&& fragmentShader= thuw::Shader::Fragment(path + "/triangle.frag");

        this->vao.init();

        thuw::Shader::Program::attach(vertexShader, fragmentShader);
        thuw::Shader::Program::link(vertexShader, fragmentShader);

        const auto&& vbo = thuw::Buffer::VBO(vertices);

        vao.bind();
        const auto&& mode = GL_STATIC_DRAW;
        vbo.copyInBuffer(mode);
        ebo.copyInBuffer(mode);

        // TODO: if default Shader
        constexpr int location = 0;
        vao.setAttribute(location, vertices);

        // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        vao.unbind();
    }

    auto draw() const {
        thuw::Shader::Program::use();
        this->vao.bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }
};