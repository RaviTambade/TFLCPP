#pragma once
#include "IDrawable.h"
#include "IPrintable.h"
#include "ISerializable.h"
#include <iostream>


//Multiple Interface Inheritance

class GeometricShape:public IDrawable, public IPrintable, public ISerializable
{
    // All three interfaces IDrawable, IPrintable and ISerializable
    // have to be implemted in it's child (sub) classes
    // forcefully, essentially, compulsorily

    //All interface pure virtual functions have to be implmented in their
    //sub classes( child classes)
    public:
        // Implementation of the draw function
        // It is compulsion
        //Interfaces enforce implementtion in their child classes
        void draw() override;
        void print() override;
        void serialize() override;
};

