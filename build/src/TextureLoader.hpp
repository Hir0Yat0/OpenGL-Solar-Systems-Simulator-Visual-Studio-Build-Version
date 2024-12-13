#ifndef TEXTURELOADER_HPP
#define TEXTURELOADER_HPP

#include <memory>

#include "Texture.hpp"

class TextureLoader {
    public:
    static std::unique_ptr<Texture> load(const char * texturePath);
};

#endif // TEXTURELOADER_HPP
