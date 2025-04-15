//Pure abstract base class
#include <iostream>

using namespace std;
//Shape:
// Area , Perimeter

//Pure Abstract Base Class
//defines a policy
//defining a contract
// Interface:
//
class Shape{
    public:

            //Enforcement: Define Rules
            virtual double calculateArea() const=0;
            virtual double calculatePerimeter() const=0;
};


//Providers:

class Circle:Shape{
    private:
            double radius;
    public :
            Circle(double r): radius(r){}

            //Implement Rules defiend by Parent

            double calculateArea() const override{
                //Formula for circle area PI* R* R
                return  (3.14) * radius* radius;
            }

            double calculatePerimeter() const override{
                //Formula for circle perimeter 2 * PI * R
                return  (3.14) * radius* 2;
            }
};

class Rectangle:Shape{

    private:
            double length, width;
    public :
            Rectangle(double l, double w): length(l), width(w) {}

              //Implement Rules defiend by Parent
            
            double calculateArea() const override{
                //Formula for Rectangle =length * width
                return length * width;  
            }

            double calculatePerimeter() const override{
                //Formula for  rectangle= 2(length + width)
                return    2 * (length + width);
            }
};

class Traingle:Shape{
    private :
        double base, edge1, edge2, height,;

    public :
            Traingle(double b, double h,double e1, double e2){
                base=b;
                height=h;
                edge1=e1;
                edge2=e2;
            }

            double calculateArea() const override{
                //Formula for Triangle  area =
                double area=(base * height)/2;
                return area;  
            }

            double calculatePerimeter() const override{
                //Formula for  rectangle= 2(length + width)
                double perimieter=base + edge1 + edge2;
                return perimieter;
            }
};

class Square:Shape{
    private:
            double side;
    private:
            Square(double s){
                side=s;
            }

            double calculateArea() const override{
                //Formula for Sqaure  area =
                double area= side * side;
                return area;  
            }

            double calculatePerimeter() const override{
                //Formula for  square= 
                double perimieter=side * 4;
                return perimieter;
            }
};

//Consumer
int main(){

  Shape * pCircle= (Shape *)new Circle(25);
  Shape * pRectangle=(Shape *) new Rectangle(23,45);

  double cArea=pCircle->calculateArea();
  double cPerimeter=pCircle->calculatePerimeter();


  double rArea=pRectangle->calculateArea();
  double rPerimeter=pRectangle->calculatePerimeter();


  cout<< "Area of Circle ="<<cArea<<endl;
  cout<< "Perimeter of Circle ="<<cPerimeter<<endl;
  

  cout<< "Area of Rectangle ="<<rArea<<endl;
  cout<< "Perimeter of Rectangle ="<<rPerimeter<<endl;

}