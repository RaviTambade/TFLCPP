# Polymorphism

Polymorphism, in the context of object-oriented programming, refers to the ability of different objects to respond to the same message (or method call) in different ways. It allows objects of different classes to be treated as objects of a common superclass, enabling more generic and flexible code.

In C++, polymorphism is primarily achieved through two mechanisms: function overloading and virtual functions.

1. **Function Overloading:** Function overloading allows multiple functions with the same name but different parameter lists to coexist within the same scope. When a function is called, the compiler determines which version of the function to invoke based on the number and types of arguments passed to it. This is known as compile-time polymorphism or static polymorphism because the decision is made at compile time.

Example of function overloading:

```cpp
#include <iostream>

void print(int x) {
    std::cout << "Integer: " << x << std::endl;
}

void print(double x) {
    std::cout << "Double: " << x << std::endl;
}

int main() {
    print(10);
    print(3.14);
    return 0;
}
```

2. **Virtual Functions and Inheritance:** Virtual functions allow a function in a base class to be overridden in a derived class. When a virtual function is called through a pointer or reference to a base class, the actual function that gets executed is determined dynamically based on the type of the object at runtime. This is known as runtime polymorphism or dynamic polymorphism.

Example of virtual functions:

```cpp
#include <iostream>

class Shape {
public:
    virtual void draw() {
        std::cout << "Drawing a shape." << std::endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a circle." << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a square." << std::endl;
    }
};

int main() {
    Shape* shape1 = new Circle();
    Shape* shape2 = new Square();

    shape1->draw(); // Calls draw() of Circle
    shape2->draw(); // Calls draw() of Square

    delete shape1;
    delete shape2;

    return 0;
}
```

In this example, the `Shape` class has a virtual function `draw()`. Both `Circle` and `Square` classes override this function. When `draw()` is called through pointers of type `Shape`, the appropriate version of `draw()` is dynamically selected based on the actual type of the object pointed to (whether it's a `Circle` or `Square`). This demonstrates runtime polymorphism in action.