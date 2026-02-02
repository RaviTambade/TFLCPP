# Namespace in C++

A **namespace** in C++ allows you to group related classes, functions, and variables, and prevent naming conflicts.

Creating a **user-defined namespace** for a **shape hierarchy** in C++ is a great way to organize the code and encapsulate the classes related to different shapes. 
Let's create a **shape hierarchy** with the following structure:

- **Shape** (Base class)
  - **Circle** (Derived class)
  - **Rectangle** (Derived class)
  - **Triangle** (Derived class)

We will use a **namespace** to group all the classes related to shapes.

### Step 1: Define the `Shape` Base Class and Derived Classes

We'll define a base class `Shape` and a few derived classes (`Circle`, `Rectangle`, `Triangle`) within the `Drawing`.

### Code Example:

```cpp
#include <iostream>
#include <cmath>
using namespace std;

// User-defined namespace for shapes
namespace Drawing {

    // Base class: Shape
    class Shape {
    public:
        virtual void displayArea() = 0;  // Pure virtual function to calculate area
        virtual ~Shape() {}  // Virtual destructor
    };

    // Derived class: Circle
    class Circle : public Shape {
    private:
        float radius;
    public:
        // Constructor to initialize radius
        Circle(float r) : radius(r) {}

        // Implement displayArea for Circle
        void displayArea() override {
            float area = 3.14 * radius * radius;
            cout << "Area of Circle: " << area << endl;
        }
    };

    // Derived class: Rectangle
    class Rectangle : public Shape {
    private:
        float length, width;
    public:
        // Constructor to initialize length and width
        Rectangle(float l, float w) : length(l), width(w) {}

        // Implement displayArea for Rectangle
        void displayArea() override {
            float area = length * width;
            cout << "Area of Rectangle: " << area << endl;
        }
    };

    // Derived class: Triangle
    class Triangle : public Shape {
    private:
        float base, height;
    public:
        // Constructor to initialize base and height
        Triangle(float b, float h) : base(b), height(h) {}

        // Implement displayArea for Triangle
        void displayArea() override {
            float area = 0.5 * base * height;
            cout << "Area of Triangle: " << area << endl;
        }
    };

}  // End of ShapeNamespace

int main() {
    // Create objects of Circle, Rectangle, and Triangle using the ShapeNamespace
    Drawing::Circle circle(5.0);
    Drawing::Rectangle rectangle(4.0, 6.0);
    Drawing::Triangle triangle(4.0, 7.0);

    // Display area for each shape
    circle.displayArea();
    rectangle.displayArea();
    triangle.displayArea();

    return 0;
}
```

### **Explanation of the Code:**

1. **Namespace (`Drawing`)**:
   - The `Drawing` encapsulates all classes related to shapes. This helps avoid name conflicts and logically organizes related classes and functions.

2. **Base Class `Shape`**:
   - This is an abstract class with a pure virtual function `displayArea()` to calculate the area of the shape. This makes `Shape` an abstract class, so it cannot be instantiated directly.
   
3. **Derived Classes**:
   - **Circle**: Inherits from `Shape` and implements the `displayArea()` function to calculate the area of a circle using the formula `π * r^2`.
   - **Rectangle**: Inherits from `Shape` and implements the `displayArea()` function to calculate the area of a rectangle using the formula `length * width`.
   - **Triangle**: Inherits from `Shape` and implements the `displayArea()` function to calculate the area of a triangle using the formula `0.5 * base * height`.

4. **Main Function**:
   - We create objects of the derived classes (`Circle`, `Rectangle`, `Triangle`) and call the `displayArea()` function for each object to display the area.

### **Output:**
```
Area of Circle: 78.5
Area of Rectangle: 24
Area of Triangle: 14
```

### Key Concepts Used:

1. **Namespace**: We define a user-defined namespace `Drawing` to group all the shape-related classes, ensuring better organization and avoiding naming conflicts with other parts of the program.

2. **Polymorphism**: The base class `Shape` has a pure virtual function, and the derived classes override this function to provide their own implementations for calculating the area. This allows dynamic polymorphism (i.e., the correct `displayArea()` function is called for each object at runtime).

3. **Encapsulation**: The member variables of each shape (like `radius`, `length`, and `width`) are encapsulated within their respective classes, ensuring that data is only accessed through the appropriate member functions.

### Conclusion:
By using **user-defined namespaces** and **object-oriented programming principles** (inheritance, polymorphism, and encapsulation), we have organized our shape hierarchy into a clear structure. This ensures modularity, maintainability, and scalability of the code.