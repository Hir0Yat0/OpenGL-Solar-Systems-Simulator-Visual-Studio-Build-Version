#include "OrbitalMovement.hpp"

OrbitalMovement::OrbitalMovement(
        float majorAxisHalfLength, 
        float minorAxisHalfLength,
        float prevX,
        float prevY,
        float xVelocity,
        float yVelocity
):
    majorAxisHalfLength{majorAxisHalfLength}, 
    minorAxisHalfLength{minorAxisHalfLength}, 
    prevX{prevX}, 
    prevY{prevY}, 
    xVelocity{xVelocity}, 
    yVelocity{yVelocity} 
{

};

std::array<float,2> OrbitalMovement::getNewPosition(float deltaTimeSeconds) {

    const float currentX = this->prevX + xVelocity * deltaTimeSeconds;
    const float currentY = this->prevY + yVelocity * deltaTimeSeconds;
    const float a = 1.0f;

    return std::array<float,2>();
}