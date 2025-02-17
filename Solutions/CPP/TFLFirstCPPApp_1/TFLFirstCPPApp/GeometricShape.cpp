#include "GeometricShape.h"


//each method declared overriable in class have to be 
//implemented in class

void GeometricShape::draw()   {
    std::cout << "Drawing the shape..." << std::endl;
}

void GeometricShape::print()   {
    std::cout << "Printing the shape..." << std::endl;
}

// Implementation of the serialize function
void GeometricShape::serialize()  {
    std::cout << "Serializing the shape..." << std::endl;
}
