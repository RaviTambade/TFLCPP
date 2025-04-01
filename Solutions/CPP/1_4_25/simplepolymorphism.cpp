#include <iostream>
using namespace std;


class Shape {
    public:
    void  virtual draw() {
            std::cout << "Drawing a generic shape" << std::endl;
        }
    };
    
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
    }