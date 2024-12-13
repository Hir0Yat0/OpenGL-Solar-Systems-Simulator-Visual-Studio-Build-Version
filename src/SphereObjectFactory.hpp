#ifndef SPHEREOBJECTFACTORY_HPP
#define SPHEREOBJECTFACTORY_HPP

// #include "SphereObjectFactory.hpp"

#include <memory>
#include <vector>

#include "Object3DFactory.hpp"

#include "SphereFactory.hpp"
#include "Shape.hpp"
#include "Shader.hpp"
#include "Texture.hpp"
#include "TextureLoader.hpp"
#include "Object3D.hpp"

class SphereObjectFactory: public Object3DFactory {

    private:

    

    public:



    std::unique_ptr<Object3D> getObject3D() override;
    std::shared_ptr<Object3D> getSharedObject3D() override;

};


#endif // SPHEREOBJECTFACTORY_HPP
