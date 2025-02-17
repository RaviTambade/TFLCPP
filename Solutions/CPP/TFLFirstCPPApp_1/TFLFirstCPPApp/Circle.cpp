#include "Circle.h"

Circle::Circle()
{
    cout << "--------Default Circle Constructor--------" << endl;
    radius = 10;
}

void Circle::display()
{
    cout << "Area of circle is : " << CalculateArea() << endl;
}