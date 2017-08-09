//
// Created by mahmoud on 8/9/17.
//

#ifndef HELLOWORLD_SHADER_H
#define HELLOWORLD_SHADER_H


#include <GL/glew.h>
#include <string>


class Shader {
public:
    Shader(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath);
    virtual ~Shader();

    void Bind();

private:
    GLuint m_program;

    GLuint m_vertexShader;
    GLuint m_fragmentShader;
};


#endif //HELLOWORLD_SHADER_H
