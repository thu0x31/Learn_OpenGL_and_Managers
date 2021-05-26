#pragma once

#include "thuw/Geometry/Attribute/Point.hpp"
#include "thuw/GL/Shader/Fragment.hpp"
#include "thuw/GL/Shader/Program.hpp"
#include "thuw/GL/Shader/Vertex.hpp"
#include "thuw/GL/VAO.hpp"
#include "thuw/Math/Vec/Vertices.hpp"
#include <vector>


// TODO: remove
namespace thuw {
    class Geometry;
}

class thuw::Geometry {
    //  component
    //      - Vertex[n]
    //          - Number : int
    //          - PointNumber : int
    //          - PrimitiveNumber : int
    //      - Point[n]
    //          - Number : int
    //          - vec<D>
    //          - Normal : vec<3>
    //          - Color : vec<4>
    //      - Primitive[n]
    //          - Number : int
    //          - VertexCount : int
    //          - Normal : vec<3>
    //          - Color : vec<4>

public:
    struct Attribute {
        std::vector<thuw::Point> points; // Point::number != ::Index
        
    } attribute;

    thuw::VAO vao;

    template<class Vertices,
            thuw::Buffer::EBOConcept EBO,
            class VertexShader,
            class FragmentShader>
    Geometry(
        Vertices&& vertices,
        EBO&& ebo,
        VertexShader&& vertexShader,
        FragmentShader&& fragmentShader
    ) 
    {
        this->vao.init();

        thuw::Shader::Program::attach(vertexShader, fragmentShader);
        thuw::Shader::Program::link(vertexShader, fragmentShader);

        const auto&& vbo = thuw::Buffer::VBO(vertices);

        vao.bind();
        vao.copyInBuffer(vbo);
        vao.copyInBuffer(ebo);

        // TODO: if default Shader
        constexpr int location = 0;
        vao.setAttribute(location);

        // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        vao.unbind();
    }

    auto draw() const {
        thuw::Shader::Program::use();
        this->vao.bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }
};