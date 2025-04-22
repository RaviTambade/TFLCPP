#include <iostream>

class Point {
private:
    int x, y;
    
public:
    // Constructor to initialize the point
    Point(int x_val, int y_val) : x(x_val), y(y_val) {}

    // Copy constructor
    Point(const Point& other) {
        x = other.x;
        y = other.y;
        std::cout << "Copy constructor called!" << std::endl;
    }

    void display() const {
        std::cout << "Point(" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    Point p1(10, 20);  // Regular constructor
    Point p2 = p1;      // Copy constructor called here

    p1.display();       // Output: Point(10, 20)
    p2.display();       // Output: Point(10, 20)
    
    return 0;
}