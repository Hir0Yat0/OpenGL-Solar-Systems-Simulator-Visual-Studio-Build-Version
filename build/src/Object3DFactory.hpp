#ifndef OBJECT3DFACTORY_HPP
#define OBJECT3DFACTORY_HPP

// #include "Object3DFactory.hpp"

#include<memory>
#include"Object3D.hpp"

class Object3DFactory {

    private:

    

    public:

    virtual ~Object3DFactory(){};

    virtual std::unique_ptr<Object3D> getObject3D() = 0;
    virtual std::shared_ptr<Object3D> getSharedObject3D() = 0;
};


#endif // OBJECT3DFACTORY_HPP
