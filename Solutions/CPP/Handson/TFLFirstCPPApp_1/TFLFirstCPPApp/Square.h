#pragma once
#include "Shape.h"
class Square : public Shape
{
private:
    int side = 0;
    int getside() { return side; }

public:
    Square();
    void setSide(int side) { this->side = side; }
    Square(int side);
    float CalculateArea() { return side * side; }
    void display();
       friend void getside(Square& s); // Declaration of friend function
};


