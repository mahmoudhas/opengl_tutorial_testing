#include <iostream>
#include "Display.h"
#include "Shader.h"
#include "Mesh.h"

int main() {
    Display display(800, 600, "hello world");
    Shader shader("../res/shader.vert", "../res/shader.frag");


    Vertex vertices[] = {
            Vertex(glm::vec3(-0.5, -0.5, 0)),
            Vertex(glm::vec3(0, 0.5, 0)),
            Vertex(glm::vec3(0.5, -0.5, 0))
    };


    Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));

    while (!display.isClosed()) {
        display.Clear(0, 0, 0, 1);

        shader.Bind();
        mesh.Draw();


        display.Update();
    }
}