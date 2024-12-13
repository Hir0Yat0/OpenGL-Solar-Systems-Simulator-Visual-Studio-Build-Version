#include "SphereFactory.hpp"

/* this makes M_PI works on windows */
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include<math.h>

std::unique_ptr<std::vector<float>> SphereFactory::getVertices(void) {

    const unsigned int sectorStepCount = this->numSectorPerStackLevel;
    const unsigned int stackStepCount = this->numStackPerSector;
    const float sectorStepSizeRad = 2 * M_PI * (1 / static_cast<float>(sectorStepCount));
    const float stackStepSizeRad = M_PI * (1 / static_cast<float>(stackStepCount));

    constexpr float radius = 1.0f;

    auto vertices = std::make_unique<std::vector<float>>();
    (*vertices).reserve(5 * sectorStepCount * stackStepCount);

    // this (stack then sector) makes things easier when computing indices
    for (unsigned int stack_i = 0; stack_i < stackStepCount; stack_i++){
        for (unsigned int sector_i = 0; sector_i < sectorStepCount; sector_i++){
            const float phi = sectorStepSizeRad * sector_i;
            const float vertex_z = radius * cosf(phi);
            const float rsin_phi = radius * sinf(phi);
            const float theta = stackStepSizeRad * stack_i;
            const float vertex_x = rsin_phi * cosf(theta);
            const float vertex_y = rsin_phi * sinf(theta);
            (*vertices).push_back(vertex_x);
            (*vertices).push_back(vertex_y);
            (*vertices).push_back(vertex_z);
            (*vertices).push_back(static_cast<float>(sector_i) / static_cast<float>(sectorStepCount)); // texture_coords_x
            (*vertices).push_back(static_cast<float>(stack_i) / static_cast<float>(stackStepCount)); // texture_coords_y
        }   
    }

    return vertices;
}

std::unique_ptr<std::vector<unsigned int>> SphereFactory::getIndices(void) {

    auto indices = std::make_unique<std::vector<unsigned int>>();
    const unsigned int sectorStepCount = this->numSectorPerStackLevel;
    const unsigned int stackStepCount = this->numStackPerSector;
    // const float sectorStepSizeRad = 2 * M_PI * (1 / static_cast<float>(sectorStepCount));
    // const float stackStepSizeRad = M_PI * (1 / static_cast<float>(stackStepCount));
    (*indices).reserve(6 * sectorStepCount * stackStepCount); // more than this

    // handy notes:
    // k1--k1+1
    // |  / |
    // | /  |
    // k2--k2+1
    for (unsigned int stack_i = 0; stack_i < numStackPerSector-1;stack_i++){
        for (unsigned int sector_i = 0;sector_i < numSectorPerStackLevel-1;sector_i++){
            const unsigned int k1 = static_cast<unsigned int>(stack_i*numSectorPerStackLevel + sector_i);
            const unsigned int k1_1 = static_cast<unsigned int>(stack_i*numSectorPerStackLevel + sector_i + 1);
            const unsigned int k2 = static_cast<unsigned int>((stack_i + 1)*numSectorPerStackLevel + sector_i);
            const unsigned int k2_1 = static_cast<unsigned int>((stack_i+1)*numSectorPerStackLevel + sector_i + 1);
            (*indices).push_back(k1);
            (*indices).push_back(k1_1);
            (*indices).push_back(k2);
            (*indices).push_back(k2);
            (*indices).push_back(k1_1);
            (*indices).push_back(k2_1);
        }
        // connect last sectors to the first sectors
        const unsigned int k1 = static_cast<unsigned int>(stack_i*numSectorPerStackLevel + (numSectorPerStackLevel-1));
        const unsigned int k1_1 = static_cast<unsigned int>(stack_i*numSectorPerStackLevel);
        const unsigned int k2 = static_cast<unsigned int>((stack_i + 1)*numSectorPerStackLevel + (numSectorPerStackLevel - 1));
        const unsigned int k2_1 = static_cast<unsigned int>((stack_i+1)*numSectorPerStackLevel);
        (*indices).push_back(k1);
        (*indices).push_back(k1_1);
        (*indices).push_back(k2);
        (*indices).push_back(k2);
        (*indices).push_back(k1_1);
        (*indices).push_back(k2_1);
    }

    return indices;
}

std::unique_ptr<std::vector<float>> SphereFactory::getVertices1(void) {

    const int sectorStepCount = this->numSectorPerStackLevel;
    const int stackStepCount = this->numStackPerSector;
    const float sectorStepSizeRad = 2 * M_PI * (1 / static_cast<float>(sectorStepCount));
    const float stackStepSizeRad = M_PI * (1 / static_cast<float>(stackStepCount));

    constexpr float radius = 1.0f;

    auto vertices = std::make_unique<std::vector<float>>();
    (*vertices).reserve(5 * sectorStepCount * stackStepCount);

    /*
        adapted from: https://www.songho.ca/opengl/gl_sphere.html
    */

    float x{}, y{}, z{}, xy{};                              // vertex position
    float nx{}, ny{}, nz{}, lengthInv = 1.0f / radius;    // vertex normal
    float s{}, t{};                                     // vertex texCoord

    float sectorStep = sectorStepSizeRad;
    float stackStep = stackStepSizeRad;
    float sectorAngle, stackAngle;

    for(int i = 0; i <= stackStepCount; ++i)
    {
        stackAngle = M_PI / 2 - i * stackStep;        // starting from pi/2 to -pi/2
        xy = radius * cosf(stackAngle);             // r * cos(u)
        z = radius * sinf(stackAngle);              // r * sin(u)

        // add (sectorCount+1) vertices per stack
        // first and last vertices have same position and normal, but different tex coords
        for(int j = 0; j <= sectorStepCount; ++j)
        {
            sectorAngle = j * sectorStep;           // starting from 0 to 2pi

            // vertex position (x, y, z)
            x = xy * cosf(sectorAngle);             // r * cos(u) * cos(v)
            y = xy * sinf(sectorAngle);             // r * cos(u) * sin(v)
            (*vertices).push_back(x);
            (*vertices).push_back(y);
            (*vertices).push_back(z);

            // vertex tex coord (s, t) range between [0, 1]
            s = static_cast<float>(j) / static_cast<float>(sectorStepCount);
            t = static_cast<float>(i) / static_cast<float>(stackStepCount);
            // texCoords.push_back(s);
            // texCoords.push_back(t);
            (*vertices).push_back(-s);
            (*vertices).push_back(t);


            // normalized vertex normal (nx, ny, nz)
            nx = x * lengthInv;
            ny = y * lengthInv;
            nz = z * lengthInv;
            // normals.push_back(nx);
            // normals.push_back(ny);
            // normals.push_back(nz);
            (*vertices).push_back(nx);
            (*vertices).push_back(ny);
            (*vertices).push_back(nz);
        }
    }

    return vertices;
}

std::unique_ptr<std::vector<unsigned int>> SphereFactory::getIndices1(void) {

    auto indices = std::make_unique<std::vector<unsigned int>>();
    const int sectorStepCount = this->numSectorPerStackLevel;
    const int stackStepCount = this->numStackPerSector;
    // const float sectorStepSizeRad = 2 * M_PI * (1 / static_cast<float>(sectorStepCount));
    // const float stackStepSizeRad = M_PI * (1 / static_cast<float>(stackStepCount));
    (*indices).reserve(6 * sectorStepCount * stackStepCount); // more than this

    /*
        adapted from: https://www.songho.ca/opengl/gl_sphere.html
    */

    // generate CCW index list of sphere triangles
    // k1--k1+1
    // |  / |
    // | /  |
    // k2--k2+1
    // std::vector<int> indices;
    // std::vector<int> lineIndices;
    int k1{}, k2{};
    for(int i = 0; i < stackStepCount; ++i)
    {
        k1 = i * (sectorStepCount + 1);     // beginning of current stack
        k2 = k1 + sectorStepCount + 1;      // beginning of next stack

        for(int j = 0; j < sectorStepCount; ++j, ++k1, ++k2)
        {
            // 2 triangles per sector excluding first and last stacks
            // k1 => k2 => k1+1
            if(i != 0)
            {
                (*indices).push_back(k1);
                (*indices).push_back(k2);
                (*indices).push_back(k1 + 1);
            }

            // k1+1 => k2 => k2+1
            if(i != (stackStepCount-1))
            {
                (*indices).push_back(k1 + 1);
                (*indices).push_back(k2);
                (*indices).push_back(k2 + 1);
            }

            // // store indices for lines
            // // vertical lines for all stacks, k1 => k2
            // lineIndices.push_back(k1);
            // lineIndices.push_back(k2);
            // if(i != 0)  // horizontal lines except 1st stack, k1 => k+1
            // {
            //     lineIndices.push_back(k1);
            //     lineIndices.push_back(k1 + 1);
            // }
        }
    }

    return indices;
}

SphereFactory::SphereFactory(size_t numSectorPerStackLevel, size_t numStackPerSector)
: numSectorPerStackLevel{numSectorPerStackLevel}, numStackPerSector{numStackPerSector}
{
}

std::unique_ptr<Shape> SphereFactory::getSphere(bool isLightSource) {

    auto vertices = this->getVertices1();
    auto indices = this->getIndices1();

    auto shape = std::make_unique<Shape>((*vertices),(*indices));
    // auto shape = Shape(vertices,indices);
    (*shape).initShapeWithTexture(isLightSource);

    return shape;
}

std::unique_ptr<Shape> SphereFactory::getShape() {
    return this->getSphere();
    // return nullptr;
}
