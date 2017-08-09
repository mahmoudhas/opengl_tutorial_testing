//
// Created by mahmoud on 8/9/17.
//

#ifndef HELLOWORLD_DISPLAY_H
#define HELLOWORLD_DISPLAY_H


#include <string>
#include <SDL2/SDL.h>
#include <GL/glew.h>


class Display {
public:
    Display(int width, int height, const std::string& windowName);
    virtual ~Display();
    bool isClosed();

    void Update();
    void Clear(float r, float g, float b, float a);

private:
    SDL_Window *m_window;
    SDL_GLContext m_glContext;

    bool m_isClosed;
};


#endif //HELLOWORLD_DISPLAY_H
