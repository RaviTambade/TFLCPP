#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
private:
    int length = 0, breadth = 0;

public:
    int getLength() { return length; }
    void setlength(int length) { this->length = length; }
    int getBreadth() { return breadth; }
    void setbreadth(int breadth) { this->breadth = breadth; }

    Rectangle();
    Rectangle(int length, int breadth);

    //Overrided function
    float CalculateArea() { return length * breadth; }

    void display();

    friend void getLengthBreadth(Rectangle& r);

    ~Rectangle(){}
};


