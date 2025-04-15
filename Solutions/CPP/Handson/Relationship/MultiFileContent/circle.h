#ifndef __CIRCLE_H
#define __CIRCLE_H
#include "point.h"
#include "shape.h"
namespace Drawing
{
    class Circle: public Shape{ 
        public :
                Point center;
                int radius;
                Circle();
                Circle(Point pt, int r,  int t, string c);
                void display();
    };
}
#endif