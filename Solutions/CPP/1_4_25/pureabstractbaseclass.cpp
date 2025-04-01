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