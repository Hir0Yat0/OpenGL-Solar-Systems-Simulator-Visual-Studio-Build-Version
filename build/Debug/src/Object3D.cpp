#include "Object3D.hpp"

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include<math.h>

#include "Utils.hpp"
#include "glmutils.hpp"

#include "DebugLevel.hpp"

bool Object3D::isZeroVector(const glm::vec3 &vec3) const {
    constexpr auto epsilon = glm::epsilon<float>();
    constexpr auto zeroVec = glm::vec3(0.0f);
    const auto isZeroes = glm::epsilonEqual(vec3,zeroVec,epsilon);
    return isZeroes.x && isZeroes.y && isZeroes.z;
    // return true;
}

Object3D::Object3D(const std::array<float, 3>& position, float angle, const std::array<float, 3>& axis, const std::array<float, 3>& scale)
    : id{idManager.getNewID()},
      position{position},
      velocity{std::array<float, 3>{0.0f}},
      acceleration{std::array<float, 3>{0.0f}},
      angle{angle},
      axis{glm::vec3{axis[0], axis[1], axis[2]}},
      angularVelocity{0.0f},
      angularAcceleration{0.0f},
      scale{scale},
      scaleVelocity{std::array<float, 3>{0.0f}},
      scaleAcceleration{std::array<float, 3>{0.0f}} 
{
    Object3D::objs[this->id] =  this;
    if (!this->isZeroVector(this->axis)){
        this->axis = glm::normalize(this->axis);
    }
}

Object3D::~Object3D() {
    idManager.removeID(this->id);
}
void Object3D::update(const std::chrono::milliseconds &deltaTime) {
    const float deltaTimeSeconds = std::chrono::duration<float>(deltaTime).count();
    DBGEXPR(deltaTime);
    DBGEXPR(deltaTimeSeconds);
    this->update(deltaTimeSeconds);
}
void Object3D::update(const float& deltaTimeSeconds) {
    this->angularVelocity += this->angularAcceleration * deltaTimeSeconds;
    this->angle += this->angularVelocity * deltaTimeSeconds;
    this->angle = copysignf(1.0f,this->angle) * fmodf(fabsf(this->angle),2*M_PI);

    for (size_t i = 0; i < this->velocity.size(); i++){
        this->velocity.at(i) += this->acceleration.at(i) * deltaTimeSeconds;
        this->position.at(i) += this->velocity.at(i) * deltaTimeSeconds;
        this->scaleVelocity.at(i) += this->scaleAcceleration.at(i) * deltaTimeSeconds;
        // this->orientation.at(i) = copysignf(1.0f,this->orientation.at(i)) * fmodf(2*M_PI,fabsf(this->orientation.at(i)));
        this->scale.at(i) += this->scaleVelocity.at(i) * deltaTimeSeconds;
    }

}
void Object3D::updateAllObjects(void) {
    if constexpr( DebugLevel::DBGLVL >= DebugLevel::DebugLevel::LOGGING){
        std::cerr << "Starting updateAllObjects!" << "\n";
    }
    for (auto & [objId,obj] : objs){
        if constexpr( DebugLevel::DBGLVL >= DebugLevel::DebugLevel::LOGGING){
            std::cerr << "Updating Objects!" << "\n";
        }
        obj->update(FrameManager::deltaTimeSeconds);
        if constexpr( DebugLevel::DBGLVL >= DebugLevel::DebugLevel::LOGGING){
            obj->printObjectInfo();
        }
    }
    if constexpr( DebugLevel::DBGLVL >= DebugLevel::DebugLevel::LOGGING){
        std::cerr << "Done updateAllObjects!" << "\n";
    }
}

void Object3D::printObjectInfo(void) const {
    DBGEXPR(this->id);
    DBGEXPRARRAY(this->position);
    DBGEXPRARRAY(this->velocity);
    DBGEXPRARRAY(this->acceleration);
    DBGEXPR(this->angle);
    DBGEXPRVEC3(this->axis);
    DBGEXPR(this->angularVelocity);
    DBGEXPR(this->angularAcceleration);
    DBGEXPRARRAY(this->scale);
    DBGEXPRARRAY(this->scaleVelocity);
    DBGEXPRARRAY(this->scaleAcceleration);
}

void Object3D::setAxis(int axis, float val) {
    this->axis[axis] = val;
    if (!this->isZeroVector(this->axis)){
        this->axis = glm::normalize(this->axis);
    }
}

void Object3D::setAxis(const std::array<float,3> &val) {
    this->axis = glm::vec3{val[0],val[1],val[2]};
    if (!this->isZeroVector(this->axis)){
        this->axis = glm::normalize(this->axis);
    }
}

void Object3D::setAxisX(void) {
    this->setAxis(std::array<float,3>{1.0f,0.0f,0.0f});
}

void Object3D::setAxisY(void) {
    this->setAxis(std::array<float,3>{0.0f,1.0f,0.0f});
}

void Object3D::setAxisZ(void) {
    this->setAxis(std::array<float,3>{0.0f,0.0f,1.0f});
}

float Object3D::getAxis(int axis) {
    return this->axis[axis];
}

glm::vec3 Object3D::getAxis(void) {
    return this->axis;
}

void Object3D::setUniformScale(float val) {
    this->scale[0] = val;
    this->scale[1] = val;
    this->scale[2] = val;
}
