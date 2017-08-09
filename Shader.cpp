//
// Created by mahmoud on 8/9/17.
//

#include <fstream>
#include <iostream>
#include "Shader.h"

GLuint CreateShader(const std::string &text, unsigned int type) ;
std::string LoadShader(const std::string &fileName) ;
void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string &errorMessage);


Shader::Shader(const std::string &vertexShaderFilePath, const std::string &fragmentShaderFilePath) {
    m_program = glCreateProgram();

    m_vertexShader = CreateShader(LoadShader(vertexShaderFilePath), GL_VERTEX_SHADER);
    m_fragmentShader = CreateShader(LoadShader(fragmentShaderFilePath), GL_FRAGMENT_SHADER);

    glAttachShader(m_program, m_vertexShader);
    glAttachShader(m_program, m_fragmentShader);

    glLinkProgram(m_program);
    CheckShaderError(m_program, GL_LINK_STATUS, true, "Error linking shader program");

    glValidateProgram(m_program);
    CheckShaderError(m_program, GL_VALIDATE_STATUS, true, "Invalid shader program");
}

Shader::~Shader() {
    glDeleteProgram(m_program);
}

void Shader::Bind() {
    glUseProgram(m_program);
}

std::string LoadShader(const std::string &fileName) {
    std::ifstream file;
    file.open((fileName).c_str());

    std::string output;
    std::string line;

    if(file.is_open()) {
        while(file.good()) {
            getline(file, line);
            output.append(line + "\n");
        }
    }
    else {
        std::cerr << "Unable to load shader: " << fileName << std::endl;
    }

    return output;
}

GLuint CreateShader(const std::string &text, unsigned int type) {
    GLuint shader = glCreateShader(type);

    if (shader == 0) {
        std::cerr << "Error compiling shader type" << std::endl;
    }

    const GLchar* p = text.c_str();
    GLint length = text.length();

    glShaderSource(shader, 1, &p, &length);
    glCompileShader(shader);

    CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error compiling shader!");


    return shader;
}

void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string &errorMessage) {
    GLint success = 0;
    GLchar error[1024] = { 0 };

    if(isProgram) {
        glGetProgramiv(shader, flag, &success);
    }
    else {
        glGetShaderiv(shader, flag, &success);
    }

    if (success == GL_FALSE) {
        (isProgram ? glGetProgramInfoLog : glGetShaderInfoLog)(shader, sizeof(error), nullptr, error);

        std::cerr << errorMessage << ": '" << error << "'" << std::endl;
    }
}
