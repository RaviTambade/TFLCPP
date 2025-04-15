#include<iostream>
using namespace std;

//Abstraction

//content class ( 2 dimensional)
class Point{
    private : int x;
              int y;
    public  :
            void setX(int xx){
                x=xx;
            }
            int getX(){
                return x;
            }
            void setY(int yy){
                y=yy;
            }
            int getY(){
                return y;
            }
};


//Container class
class Circle{
    private :
            int radius;
            Point center;

    public :
            //default constructor
            Circle(){
                radius=10;
            }
            void setRadius(int r){
                radius=r;
            }
            int getRadius(){
                return radius;
            }

            void setCenterPoint(Point p){
                center.setX(p.getX());
                center.setY(p.getY());
            }

            Point getCenterPoint(){
                return center;
            }
};


//Blue Print
class Line{
    private: 
        Point startPoint;
        Point endPoint;
    public:
        void setStartPoint(Point p){
            startPoint=p;
        }

        Point getStartPoint(){
            return startPoint;
        }

        void setEndPoint(Point p){
            endPoint=p;
        }

        Point getEndPoint(){
            return endPoint;
        }
};

class Traingle{
    private :
        Point  firstPoint;
        Point  secondPoint;
        Point  thirdPoint;

    public:
        void setFirstPoint(Point p){
            firstPoint=p;
        }
        Point getFirstPoint(){
            return firstPoint;
        }

        void setSecondPoint(Point p){
            secondPoint=p;
        }
        Point getSecondPoint(){
            return secondPoint;
        }

        void setThirdPoint(Point p){
            thirdPoint=p;
        }
        Point getThirdPoint(){
            return thirdPoint;
        }

};


int main(){
    Point p1;
    p1.setX(56);
    p1.setY(76);

    Circle c1;
    c1.setCenterPoint(p1);
    c1.setRadius(5);
    cout<<p1.getX()<<","<<p1.getY()<<endl;
    cout<<"Radius ="<<c1.getRadius();

    Traingle t1;

    Point p3;
    p3.setX(560);
    p3.setY(123);

    Point p4;
    p4.setX(44);
    p4.setY(78);

    Point p5;
    p5.setX(87);
    p5.setY(12);

    t1.setFirstPoint(p3);
    t1.setSecondPoint(p4);
    t1.setThirdPoint(p5);


    Point p6;
    p6.setX(76);
    p6.setY(44);

    Point p7;
    p7.setX(92);
    p7.setY(11);

    Line l1;
    l1.setStartPoint(p6);
    l1.setEndPoint(p7);


}