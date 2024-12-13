#include "OrbitalObject3D.hpp"

OrbitalObject3D::OrbitalObject3D(float gravityToCentralObject, std::weak_ptr<Object3D> centralObject, const std::array<float, 3>& position, float angle, const std::array<float, 3>& axis, const std::array<float, 3>& scale)
: Object3D{position,angle,axis,scale}, gravityToCentralObject{gravityToCentralObject}, centralObject{centralObject}
 
 {

}

void OrbitalObject3D::update(const float& deltaTimeSeconds) {
    
    if (auto centralObject = this->centralObject.lock()){
        const glm::vec3 centralObjectPosition = glm::vec3( (*centralObject).position[0],(*centralObject).position[1],(*centralObject).position[2]);
        const glm::vec3 directionToCentralObject = glm::normalize( centralObjectPosition - glm::vec3(this->position[0],this->position[1],this->position[2]));
        const glm::vec3 distanceToCentralObject = centralObjectPosition - glm::vec3(this->position[0],this->position[1],this->position[2]);
        const float squareddistance = distanceToCentralObject.x * distanceToCentralObject.x + distanceToCentralObject.y * distanceToCentralObject.y + distanceToCentralObject.z * distanceToCentralObject.z + 0;
        // const glm::vec3 accelerationToCentralObject = this->gravityToCentralObject * directionToCentralObject;
        const glm::vec3 accelerationToCentralObject = directionToCentralObject * (this->gravityToCentralObject / squareddistance);

        // std::cerr << "This Class's Updates Is Being Called!" << "\n";

        this->acceleration[0] = accelerationToCentralObject.x;
        this->acceleration[1] = accelerationToCentralObject.y;
        this->acceleration[2] = accelerationToCentralObject.z;

    } 

    Object3D::update(deltaTimeSeconds);

}
