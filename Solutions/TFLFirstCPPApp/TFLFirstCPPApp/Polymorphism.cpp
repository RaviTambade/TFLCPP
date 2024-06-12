#include "Shape.h"
#include "Square.h"
#include "Circle.h"
#include "rectangle.h"
#include <iostream>
using namespace std;





//global  functions

void getside(Square& s)
{
    cout << "Enter the side to calculate the area of Square: ";
    cin >> s.side;
}

void getLengthBreadth(Rectangle& r)
{
    cout << "Enter the length and breadth of the rectangle : ";
    cin >> r.length >> r.breadth;
}

void getradius(Circle& r)
{
    cout << "Enter the raduis of the circle : ";
    cin >> r.radius;
}

void calculateArea(Circle& c, Rectangle& r, Square& s)
{
    int choice;
    do
    {
        cout << "1. Area of Circle, 2. Area of Square, 3. Area of Rectangle, 4. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            getradius(c);
            c.CalculateArea();
            c.display();
            break;

        case 2:
            getside(s);
            s.CalculateArea();
            s.display();
            break;

        case 3:
            getLengthBreadth(r);
            r.CalculateArea();
            r.display();
            break;

        case 4:
            cout << "Thanks for calculating.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }

    } while (choice != 4);
}

int main()
{

    string strName = "Ravi Tambade";
    string* ptrName = NULL;
    ptrName =& strName;         //Point may or many not point to object

    string& refName = strName;  //reference always points to object

    const string * ptrMentor = &strName;

    //Reference is constant Pointer to object









    int radius = 0;
    int length = 0, breadth = 0, side = 0;
    cout << "Enter length, breadth and height = ";
    cin >> length >> breadth;

   // Circle c1(radius);
    Rectangle r1(length, breadth);
    Square s1(side);
    //calculateArea(c1, r1, s1);

    return 0;
}