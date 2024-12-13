#include "ShapeSurface.hpp"

ShapeSurface::ShapeSurface(const Shape &shape, const char * texturePath)
: shape{shape}, texture{TextureLoader::load(texturePath)}
{
    this->texture.use();
    this->shape.initShapeWithTexture();
}

ShapeSurface::ShapeSurface(const Shape &shape, const Texture &texture)
: shape{shape}, texture{texture}
{
    this->texture.use();
    this->shape.initShapeWithTexture();
}

void ShapeSurface::use() {
    this->texture.use();
    this->shape.use();
}

void ShapeSurface::draw() {
    this->use();
    this->shape.draw();
}

// ShapeSurface::~ShapeSurface(){
    // texture.~Texture();
    // shape.~Shape();
// }
