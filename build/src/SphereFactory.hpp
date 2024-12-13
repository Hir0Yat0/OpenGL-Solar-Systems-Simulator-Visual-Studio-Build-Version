#ifndef SPHEREFACTORY_HPP
#define SPHEREFACTORY_HPP

// #include "SphereFactory.hpp"

#include <vector>
#include <memory>

#include "ShapeFactory.hpp"
#include "Shape.hpp"

class SphereFactory: public ShapeFactory {

    private:

    std::unique_ptr<std::vector<float>> getVertices(void);
    std::unique_ptr<std::vector<unsigned int>> getIndices(void);
    std::unique_ptr<std::vector<float>> getVertices1(void);
    std::unique_ptr<std::vector<unsigned int>> getIndices1(void);

    public:

    size_t numSectorPerStackLevel;
    size_t numStackPerSector;

    SphereFactory(size_t numSectorPerStackLevel = 20U, size_t numStackPerSector = 20U);

    std::unique_ptr<Shape> getSphere(bool isLightSource = false); 
    std::unique_ptr<Shape> getShape() override;

};


#endif // SPHEREFACTORY_HPP
