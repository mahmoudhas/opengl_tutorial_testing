//
// Created by mahmoud on 8/9/17.
//

#ifndef HELLOWORLD_MESH_H
#define HELLOWORLD_MESH_H


#include <GL/glew.h>
#include <glm/glm.hpp>


class Vertex {
public:
    explicit Vertex(const glm::vec3& in) {
        this->pos = in;
    }
private:
    glm::vec3 pos;
};


class Mesh {
public:
    Mesh(Vertex *vertices, unsigned int numVertices);
    virtual ~Mesh();

    void Draw();

private:
    GLuint m_vertexArrayObject;
    GLuint m_vertexArrayBuffer;

    unsigned int m_drawCount;
};


#endif //HELLOWORLD_MESH_H
