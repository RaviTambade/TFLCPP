#include <iostream>
#include <string>
#include "point.h"
#include "shape.h"
#include  "line.h"
#include  "circle.h"

using namespace std;
using namespace Drawing;

int main(){
    cout <<"Reusibility using Inheritance"<<endl;
    Shape s;
    s.display();
    Shape s2(3,"red");
    s2.display();

    Point p1(34,45);
    Point p2(55,76);

    Line l1(p1, p2, 4, "blue");
    l1.display();

    Point p5(56,34);
    Point p6(179,298);

    Line l2(p5, p6, 4, "darkred");
    l2.display();

    Point p3(100,123);
    int radius=6;

    Circle c1(p1,25,4, "gold");
    c1.display();
}