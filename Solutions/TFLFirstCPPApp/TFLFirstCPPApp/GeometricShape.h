#pragma once
#include "IDrawable.h"
#include "IPrintable.h"
#include "ISerializable.h"
#include <iostream>

class GeometricShape:public IDrawable, public IPrintable, public ISerializable
{

    public:
        // Implementation of the draw function
        void draw() override {
            std::cout << "Drawing the shape..." << std::endl;
        }

        void print() override {
            std::cout << "Printing the shape..." << std::endl;
        }

        // Implementation of the serialize function
        void serialize() override {
            std::cout << "Serializing the shape..." << std::endl;
        }
};

