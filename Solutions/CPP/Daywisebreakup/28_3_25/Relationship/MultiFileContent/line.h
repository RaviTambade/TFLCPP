#ifndef  __LINE_H
#define __LINE_H

#include "shape.h"
#include "point.h"
namespace Drawing {
    class Line: public Shape  {
        public : 
                Point startPoint;
                Point endPoint;

                Line(); 
                Line(Point pt1, Point pt2, int t, string c); 
                void display();
    };
}
#endif