#include "OrbitalObjectFactory.hpp"

std::unique_ptr<Object3D> OrbitalObjectFactory::getObject3D() {
    return this->getOrbitalObject3D();
    // return nullptr;
}

std::shared_ptr<Object3D> OrbitalObjectFactory::getSharedObject3D() {
    return this->getSharedOrbitalObject3D();
    // return nullptr;
}

std::unique_ptr<OrbitalObject3D> OrbitalObjectFactory::getOrbitalObject3D() {
    return std::make_unique<OrbitalObject3D>();
    // return nullptr;
}

std::shared_ptr<OrbitalObject3D> OrbitalObjectFactory::getSharedOrbitalObject3D() {
    // auto obj = this->sphereObjectFactory.getSharedObject3D();
    // auto orbobj = std
    return std::make_shared<OrbitalObject3D>();
    // return nullptr;
}