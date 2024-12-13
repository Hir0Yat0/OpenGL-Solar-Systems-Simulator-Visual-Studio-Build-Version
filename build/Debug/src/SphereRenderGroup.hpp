#ifndef SPHERERENDERGROUP_HPP
#define SPHERERENDERGROUP_HPP

// #include "SphereRenderGroup.hpp"
#include<memory>
#include"RenderGroup3D.hpp"
#include"Shape.hpp"
#include"Shader.hpp"
#include"TextureLoader.hpp"
#include"Texture.hpp"
#include"ShaderLoader.hpp"
#include"SphereFactory.hpp"

class SphereRenderGroup {

    private:

    

    public:

    std::unique_ptr<RenderGroup3D> getRenderGroup3D(const char * texturePath = "assets/sky-and-grass-24.jpg", const char * vertShaderPath = "src/shaders/object3d.vert",const char * fragShaderPath = "src/shaders/object3d.frag",bool isLightSource = false);

};


#endif // SPHERERENDERGROUP_HPP
