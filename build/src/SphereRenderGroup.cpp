#include "SphereRenderGroup.hpp"

std::unique_ptr<RenderGroup3D> SphereRenderGroup::getRenderGroup3D(const char * texturePath,const char * vertShaderPath,const char * fragShaderPath, bool isLightSource) {

    int initSuccess = 1;

    auto sphereFactory = SphereFactory();

    auto shape = sphereFactory.getSphere(isLightSource);

    auto shader = ShaderLoader::loadShader(vertShaderPath,fragShaderPath);

    if (!(*shader).shaderStatus){
        std::cerr << "Shader Initialization Errors" << "\n";
        initSuccess = 0;
    }

    auto texture = TextureLoader::load(texturePath);

    if (!(*texture).initSuccess) {
        std::cerr << "Texture Initialization Errors" << "\n";
        initSuccess = 0;
    }

    auto renderGroup3D = std::make_unique<RenderGroup3D>(std::move(shape),std::move(shader),std::move(texture),initSuccess);

    return renderGroup3D;
}