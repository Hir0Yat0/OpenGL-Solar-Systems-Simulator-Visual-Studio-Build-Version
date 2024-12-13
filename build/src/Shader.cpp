#include "shader.hpp"

#include <iostream>
#include <fstream>


Shader::Shader(const char* vertexPath, const char* fragmentPath)
:   
    ID{},
    vertexStatus{0},
    fragmentStatus{0},
    shaderLinkingStatus{0},
    shaderStatus{0}
{
    const std::ifstream vShaderFile{vertexPath};   

    if (!vShaderFile){
        std::cerr << "Failed To Open File: " << std::string{vertexPath} << "\n";
        return;
    }

    std::stringstream vbuffer{};
    vbuffer << vShaderFile.rdbuf();
    if (vbuffer.fail()){
        std::cerr << "Failed To Read File: " << std::string{vertexPath} << "\n";
        return;
    }
    const std::string vertexCode{vbuffer.str()};

    const std::ifstream fShaderFile{fragmentPath};
    if (!fShaderFile){
        std::cerr << "Failed To Open File: " << std::string{fragmentPath} << "\n";
        return;
    }
    std::stringstream fbuffer{};
    fbuffer << fShaderFile.rdbuf();
    if (fbuffer.fail()){
        std::cerr << "Failed To Read File: " << std::string{fragmentPath} << "\n";
        return;
    }
    const std::string fragmentCode{fbuffer.str()};
    
    this->initShader(vertexCode.c_str(),fragmentCode.c_str());

}

void Shader::initShader(const char * const vertexShaderSource,const char * const fragmentShaderSource){
    // build and compile our shader program
    // ------------------------------------
    // vertex shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // check for shader compile errors
    int success = 0;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << "\n";
    }
    this->vertexStatus = 1;
    // fragment shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << "\n";
    }
    this->fragmentStatus = 1;
    // link shaders
    this->ID = glCreateProgram();
    glAttachShader(this->ID, vertexShader);
    glAttachShader(this->ID, fragmentShader);
    glLinkProgram(this->ID);
    // check for linking errors
    glGetProgramiv(this->ID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(this->ID, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << "\n";
    }
    this->shaderLinkingStatus = 1;
    this->shaderStatus = 1;
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    // success = success;
    return ;
}

Shader::~Shader(){
    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteProgram(this->ID);
}

void Shader::use(){
    glUseProgram(this->ID);
}

// utility uniform functions
void Shader::setBool(const std::string &name, bool value) const {
    glUniform1i(glGetUniformLocation(this->ID, name.c_str()), static_cast<int>(value)); 
}  
void Shader::setInt(const std::string &name, int value) const {
    glUniform1i(glGetUniformLocation(this->ID, name.c_str()), value); 
}   
void Shader::setFloat(const std::string &name, float value) const {
    glUniform1f(glGetUniformLocation(this->ID, name.c_str()), value); 
}
