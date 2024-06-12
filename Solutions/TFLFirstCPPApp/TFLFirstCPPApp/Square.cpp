#include "Square.h"
Square::Square()
{
    cout << "--------Default Square Constructor--------" << endl;
    side = 10;
}

Square::Square(int side)
{
    cout << "--------Parameterized Square Constructor--------" << endl;
    this->side = side;
}

void Square::display()
{
    cout << "Area of a Square is : " << CalculateArea() << endl;
}