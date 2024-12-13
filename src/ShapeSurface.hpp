#ifndef SHAPESURFACE_HPP
#define SHAPESURFACE_HPP

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Shape.hpp"
#include "Texture.hpp"
#include "TextureLoader.hpp"

class ShapeSurface {

    private:

    public:

    Shape shape;
    Texture texture;    

    ShapeSurface(const Shape &shape, const char * texturePath);
    ShapeSurface(const Shape &shape, const Texture &texture);
    // ~ShapeSurface();
    void use();
    void draw();

};

#endif // SHAPESURFACE_HPP
