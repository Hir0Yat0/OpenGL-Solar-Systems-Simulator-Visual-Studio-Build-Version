#include "Camera.hpp"

#include "math.h"

Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
    : Front{glm::vec3(0.0f, 0.0f, -1.0f)}, 
    sprintMultiplier{SPRINT_MULTIPLIER}, 
    MovementSpeed{SPEED}, MouseSensitivity{SENSITIVITY}, 
    Zoom{ZOOM} ,
    object3D{std::make_shared<Object3D>()}, 
    firstMouse{true}, 
    prevPosX{}, 
    prevPosY{}
{
    Position = position;
    WorldUp = up;
    Yaw = yaw;
    Pitch = pitch;
    updateCameraVectors();
}

glm::mat4 Camera::GetViewMatrix() {
    return glm::lookAt(Position, Position + Front, Up);
}


void Camera::ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch) {
        xoffset *= MouseSensitivity;
        yoffset *= MouseSensitivity;

        Yaw += xoffset;
        Pitch += yoffset;

        if (constrainPitch) {
            if (Pitch > 89.0f){
                Pitch = 89.0f;
            }
            if (Pitch < -89.0f){
                Pitch = -89.0f;
            }
        }

        updateCameraVectors();
    }

void Camera::ProcessMouseScroll(float yoffset) {
    Zoom -= (float)yoffset;
    if (Zoom < 1.0f){
        Zoom = 1.0f;
    }
    if (Zoom > 45.0f){
        Zoom = 45.0f;
    }
}

void Camera::ProcessKeyboard(Camera_Movement direction, float deltaTime, bool isShiftPressed) {
    const float velocity = MovementSpeed * deltaTime * (isShiftPressed ? sprintMultiplier : 1.0f);
    switch (direction) {
        case Camera_Movement::FORWARD: {
            Position += Front * velocity;
        }   break;
        case Camera_Movement::BACKWARD: {
            Position -= Front * velocity;
        }   break;
        case Camera_Movement::LEFT: {
            Position -= Right * velocity;
        }   break;
        case Camera_Movement::RIGHT: {
            Position += Right * velocity;
        }   break;
        case Camera_Movement::UP: {
            Position += Up * velocity;
        }   break;
        case Camera_Movement::DOWN: {
            Position -= Up * velocity;
        }   break;
        default: {
            // nothing
        }   break;
    }
    // update attached object3D
    (*this->object3D).position[0] = this->Position[0];
    (*this->object3D).position[1] = this->Position[1];
    (*this->object3D).position[2] = this->Position[2];
}

void Camera::updateCameraVectors() {
    glm::vec3 front;
    front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    front.y = sin(glm::radians(Pitch));
    front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    Front = glm::normalize(front);
    Right = glm::normalize(glm::cross(Front, WorldUp));
    Up = glm::normalize(glm::cross(Right, Front));

    

}
