#include "Texture.hpp"

Texture::Texture(unsigned int ID, int width, int height, int nrChannels, int initSuccess) 
: ID{ID}, width{width}, height{height}, nrChannels{nrChannels}, initSuccess{initSuccess}
{
    
}

Texture::~Texture() {
    glDeleteTextures(1,&this->ID);
}

void Texture::use() const {
    glBindTexture(GL_TEXTURE_2D, this->ID);
}
