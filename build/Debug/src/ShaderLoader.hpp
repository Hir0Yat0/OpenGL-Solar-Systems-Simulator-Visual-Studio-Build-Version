#ifndef SHADERLOADER_HPP
#define SHADERLOADER_HPP

// #include "ShaderLoader.hpp"
#include <memory>
#include "Shader.hpp"

class ShaderLoader {

    private:

    

    public:

    static std::unique_ptr<Shader> loadShader(const char* vertexPath, const char* fragmentPath);

};


#endif // SHADERLOADER_HPP
