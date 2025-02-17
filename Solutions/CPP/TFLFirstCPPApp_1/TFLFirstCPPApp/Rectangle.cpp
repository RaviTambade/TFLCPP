#include "Rectangle.h"

Rectangle::Rectangle()
{
    cout << "--------Default Rectangle Constructor--------" << endl;
    length = 10;
    breadth = 30;
}

Rectangle::Rectangle(int length, int breadth)
{
    cout << "--------Parameterized Rectangle Constructor--------" << endl;
    this->length = length;
    this->breadth = breadth;
}


void Rectangle::display()
{
    cout << "Area of rectangle is : " << CalculateArea() << endl;
}