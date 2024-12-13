#ifndef OBJECT3DTRACKER_HPP
#define OBJECT3DTRACKER_HPP

// #include "Object3DTracker.hpp"
#include "Object3D.hpp"
#include <memory>
#include <array>

class Object3DTracker: public Object3D {

    private:

    

    public:

    std::weak_ptr<Object3D> trackedObject3D;

    Object3DTracker(std::weak_ptr<Object3D> trackedObject3D = std::weak_ptr<Object3D>(), const std::array<float,3> &position=std::array<float,3>{0.0f,0.0f,0.0f}, float angle = 0.0f,const std::array<float,3> &axis=std::array<float,3>{1.0f,0.0f,0.0f}, const std::array<float,3> &scale=std::array<float,3>{1.0f,1.0f,1.0f});

    virtual void update(const float& deltaTimeSeconds) override;

};


#endif // OBJECT3DTRACKER_HPP
