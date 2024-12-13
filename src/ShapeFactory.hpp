#ifndef SHAPEFACTORY_HPP
#define SHAPEFACTORY_HPP

// #include "ShapeFactory.hpp"

#include <memory>

#include "Shape.hpp"

class ShapeFactory {

    private:

    

    public:

    virtual ~ShapeFactory(){};

    virtual std::unique_ptr<Shape> getShape() = 0;

};


#endif // SHAPEFACTORY_HPP
