#include <iostream>
#include "Display.h"
#include "Shader.h"

int main() {
    Display display(800, 600, "hello world");
    Shader shader("./res/shader.vert", "./res/shader.frag");

    while (!display.isClosed()) {
        display.Clear(0, 0, 0, 1);

        shader.Bind();


        display.Update();
    }
}