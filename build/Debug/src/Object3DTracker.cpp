#include "Object3DTracker.hpp"

Object3DTracker::Object3DTracker(std::weak_ptr<Object3D> trackedObject3D, const std::array<float, 3>& position, float angle, const std::array<float, 3>& axis, const std::array<float, 3>& scale) 
:
    trackedObject3D{trackedObject3D},
    Object3D{position,angle,axis,scale}
{



}

void Object3DTracker::update(const float& deltaTimeSeconds) {

    if (auto obj = this->trackedObject3D.lock()){
        this->position[0] = (*obj).position[0];
        this->position[1] = (*obj).position[1];
        this->position[2] = (*obj).position[2];
    }
    Object3D::update(deltaTimeSeconds);

}
