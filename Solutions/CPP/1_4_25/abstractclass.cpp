//abstract class
#include <iostream>

using namespace std;

//abstract base class 
class Shape {
    public:
        //Pure virtual function
        void  virtual draw()=0;
    };


//for Achieving polymorphism you must extend child class from abstract class

//derived class
class Circle : public Shape {
    public:
        void draw()  override  {
            std::cout << "Drawing a circle" << std::endl;
        }
    };
    
    class Rectangle : public Shape {
    public:
        void draw()  override  {
            std::cout << "Drawing a rectangle" << std::endl;
        }
    };
    
    int main() {
       
        Shape* shape1 = new Circle();
        Shape* shape2 = new Rectangle();
      
        shape1->draw();  // Outputs: Drawing a circle
        shape2->draw();  // Outputs: Drawing a rectangle

        //two types of classes
        //a.concrete class
        //we can create objects from class
        //b.absract class
        //we can not create object from class
    }