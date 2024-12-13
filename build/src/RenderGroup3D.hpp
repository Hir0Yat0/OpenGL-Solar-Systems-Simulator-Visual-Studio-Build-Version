#ifndef RENDERGROUP3D_HPP
#define RENDERGROUP3D_HPP

// #include "RenderGroup3D.hpp"

#include <memory>
#include <unordered_map>

#include "glmlib.hpp"

#include "Shape.hpp"
#include "Shader.hpp"
#include "Texture.hpp"
#include "Object3D.hpp"

class RenderGroup3D {

    private:

    std::unique_ptr<Shape> shape;
    std::unique_ptr<Shader> shader;
    std::unique_ptr<Texture> texture;
    std::unique_ptr<std::unordered_map<size_t,std::shared_ptr<Object3D>>> objects;

    public:
    
    int initSuccess;

    RenderGroup3D(std::unique_ptr<Shape> shape, 
                std::unique_ptr<Shader> shader,
                std::unique_ptr<Texture> texture ,
                int initSuccess
    );
    virtual ~RenderGroup3D() = default;
    virtual void render(void);
    virtual void render([[maybe_unused]] const glm::mat4 &projection, [[maybe_unused]] const glm::mat4 &view, [[maybe_unused]] const glm::vec3& cameraPos);
    virtual void add(std::shared_ptr<Object3D> object);
    virtual void remove(size_t objectID);

};


#endif // RENDERGROUP3D_HPP
