#include "SphereObjectFactory.hpp"

std::unique_ptr<Object3D> SphereObjectFactory::getObject3D() {

    auto object3D = std::make_unique<Object3D>();

    return object3D;
}

std::shared_ptr<Object3D> SphereObjectFactory::getSharedObject3D() {
    return std::shared_ptr<Object3D>(std::move(this->getObject3D()));
}
