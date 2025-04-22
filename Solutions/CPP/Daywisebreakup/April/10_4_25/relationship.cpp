# include <iostream>
#include <string>

using namespace std;

class Point{
    protected: 
            int x;
            int y;

     public:

            Point(){
                x=y=0;
            }
            Point(int xx, int yy){
                x=xx;
                y=yy;
            }
};

class Shape{
    protected :
        string color;
        int thickness;

    public:
          Shape(){
            color="black";
            thickness=1;

          }

          Shape( string c, int t){
            color=c;
            thickness=t;
          }


};

class Line:Shape{
    public:
         Point   startPoint;
         Point   endPoint;
         
         //Member Initialzed List (constructor)
         Line(Point  pt1, Point pt2, string c, int t):Shape(c,t){
            //Shape::Shape(c, t);
            this->startPoint=pt1;
            this->endPoint=pt2;
         }

};

int main () {


    Point start(45,65);
    Point end(77,78);
     
    Line l(start, end);




}