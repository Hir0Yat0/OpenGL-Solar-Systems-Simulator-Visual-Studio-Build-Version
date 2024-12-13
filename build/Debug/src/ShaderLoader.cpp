#include "ShaderLoader.hpp"

std::unique_ptr<Shader> ShaderLoader::loadShader(const char* vertexPath, const char* fragmentPath) {
    return std::make_unique<Shader>(vertexPath,fragmentPath);
}