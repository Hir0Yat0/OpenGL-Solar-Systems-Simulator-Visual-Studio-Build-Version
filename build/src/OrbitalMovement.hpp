#ifndef ORBITALMOVEMENT_HPP
#define ORBITALMOVEMENT_HPP

// #include "OrbitalMovement.hpp"

// #include "glmlib.hpp"
#include <array>

/*
    ellipse equations: x^2 / a^2 + y^2 / b^2 = 1

    where a is the radius of the longer axis
    and b is the radius of the short axis
*/

class OrbitalMovement {

    private:

    

    public:

    float majorAxisHalfLength;
    float minorAxisHalfLength;
    float prevX;
    float prevY;
    float xVelocity;
    float yVelocity;

    OrbitalMovement(
        float majorAxisHalfLength, 
        float minorAxisHalfLength,
        float prevX,
        float prevY,
        float xVelocity,
        float yVelocity
    );

    std::array<float,2> getNewPosition(float deltaTimeSeconds);

};


#endif // ORBITALMOVEMENT_HPP
