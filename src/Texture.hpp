#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "glad/glad.h"
#include "GLFW/glfw3.h"

class Texture {
public:
    const unsigned int ID;
    const int width; 
    const int height; 
    const int nrChannels;
    const int initSuccess;
    Texture(unsigned int ID,int width, int height, int nrChannels, int initSuccess);
    ~Texture();
    void use() const;
};

#endif // TEXTURE_HPP
