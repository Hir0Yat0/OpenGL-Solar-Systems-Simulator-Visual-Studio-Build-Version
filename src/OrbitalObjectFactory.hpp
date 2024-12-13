#ifndef ORBITALOBJECTFACTORY_HPP
#define ORBITALOBJECTFACTORY_HPP

// #include "OrbitalObjectFactory.hpp"

#include "Object3DFactory.hpp"
#include "SphereObjectFactory.hpp"
#include "OrbitalObject3D.hpp"

class OrbitalObjectFactory: public Object3DFactory {

    private:

    // SphereObjectFactory sphereObjectFactory;

    public:

    // OrbitalObjectFactory(): sphereObjectFactory{}{};
    virtual std::unique_ptr<Object3D> getObject3D() override;
    virtual std::shared_ptr<Object3D> getSharedObject3D() override;
    std::unique_ptr<OrbitalObject3D> getOrbitalObject3D() ;
    std::shared_ptr<OrbitalObject3D> getSharedOrbitalObject3D();

};


#endif // ORBITALOBJECTFACTORY_HPP
