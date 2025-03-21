# Polymorphism in C++

In C++, **polymorphism** is a fundamental concept in object-oriented programming that allows you to use a single interface to represent different underlying forms or data types. The word "polymorphism" comes from the Greek words **poly** (meaning many) and **morph** (meaning forms), indicating that a single entity (e.g., a function or an object) can take many forms.

There are **two main types of polymorphism** in C++:

1. **Compile-Time Polymorphism (Static Polymorphism)**: This occurs at the time of compilation and is resolved before the program runs.
2. **Run-Time Polymorphism (Dynamic Polymorphism)**: This is resolved during program execution (at runtime).

Let’s explore both types with examples.

---

### **1. Compile-Time Polymorphism (Static Polymorphism)**

**Compile-time polymorphism** is achieved when the function or operator is resolved at compile time. It typically includes:

- **Function Overloading**
- **Operator Overloading**

#### **Function Overloading**:
Function overloading is when multiple functions have the same name but different parameters (either in number, type, or order). The compiler decides which function to call based on the arguments passed.

```cpp
#include <iostream>
using namespace std;

class Print {
public:
    // Overloaded function to print an integer
    void display(int i) {
        cout << "Integer: " << i << endl;
    }

    // Overloaded function to print a float
    void display(float f) {
        cout << "Float: " << f << endl;
    }

    // Overloaded function to print a string
    void display(string str) {
        cout << "String: " << str << endl;
    }
};

int main() {
    Print obj;
    obj.display(5);      // Calls the function that accepts an int
    obj.display(3.14f);  // Calls the function that accepts a float
    obj.display("Hello, World!");  // Calls the function that accepts a string
    return 0;
}
```

**Explanation**:
- The `display()` function is overloaded with different parameter types (`int`, `float`, and `string`).
- The correct version of the function is chosen by the compiler at compile time based on the type of argument passed.

#### **Operator Overloading**:
Operator overloading allows you to define the behavior of operators (like `+`, `-`, `*`, etc.) for user-defined types (e.g., classes).

```cpp
#include <iostream>
using namespace std;

class Complex {
private:
    int real;
    int imag;

public:
    Complex(int r, int i) : real(r), imag(i) {}

    // Overload the + operator
    Complex operator + (const Complex& c) {
        return Complex(real + c.real, imag + c.imag);
    }

    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 4), c2(1, 2);
    Complex c3 = c1 + c2;  // Calls the overloaded + operator
    c3.display();           // Output: 4 + 6i
    return 0;
}
```

**Explanation**:
- The `+` operator is overloaded to add two `Complex` numbers.
- The operator `+` is resolved at compile time.

---

### **2. Run-Time Polymorphism (Dynamic Polymorphism)**

**Run-time polymorphism** is achieved through inheritance and pointers or references to base class objects. It allows a function to behave differently based on the type of the object being referenced or pointed to at runtime. This is typically achieved using **virtual functions**.

#### **Virtual Functions**:
A virtual function is a function that is declared in the base class and is meant to be overridden in derived classes. When you call a virtual function using a base class pointer or reference, C++ decides at runtime which function to call based on the actual object type (not the type of the pointer/reference).

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    // Virtual function to calculate area
    virtual void area() const {
        cout << "Calculating area of generic shape." << endl;
    }
};

class Circle : public Shape {
private:
    float radius;

public:
    Circle(float r) : radius(r) {}

    // Override the area function
    void area() const override {
        cout << "Area of Circle: " << 3.14f * radius * radius << endl;
    }
};

class Rectangle : public Shape {
private:
    float width, height;

public:
    Rectangle(float w, float h) : width(w), height(h) {}

    // Override the area function
    void area() const override {
        cout << "Area of Rectangle: " << width * height << endl;
    }
};

int main() {
    Shape* shape1 = new Circle(5.0);   // Base class pointer to derived class object
    Shape* shape2 = new Rectangle(4.0, 6.0);

    shape1->area();  // Calls Circle's area
    shape2->area();  // Calls Rectangle's area

    delete shape1;
    delete shape2;
    return 0;
}
```

**Explanation**:
- The `area()` function is declared as `virtual` in the base class `Shape` and overridden in the derived classes `Circle` and `Rectangle`.
- At runtime, when the `area()` function is called using a base class pointer (`shape1`, `shape2`), the correct version of `area()` is called based on the actual object type (either `Circle` or `Rectangle`), not the type of the pointer.

#### **Pure Virtual Functions (Abstract Classes)**:
A pure virtual function is a virtual function that has no implementation in the base class and must be overridden in any derived class. This turns the base class into an **abstract class**, which cannot be instantiated directly.

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    // Pure virtual function makes Shape an abstract class
    virtual void area() const = 0;

    virtual ~Shape() {}
};

class Triangle : public Shape {
private:
    float base, height;

public:
    Triangle(float b, float h) : base(b), height(h) {}

    // Override the area function
    void area() const override {
        cout << "Area of Triangle: " << 0.5f * base * height << endl;
    }
};

int main() {
    Shape* shape = new Triangle(10.0, 5.0);
    shape->area();  // Calls Triangle's area

    delete shape;
    return 0;
}
```

**Explanation**:
- The `area()` function is a pure virtual function in the `Shape` class, making it an abstract class.
- The `Triangle` class provides its own implementation of the `area()` function.
- You cannot instantiate an object of `Shape` directly, but you can create objects of derived classes like `Triangle`.

---

### Summary of Polymorphism Types:

| **Type of Polymorphism**       | **Explanation**                                                                                     | **Example**                          |
|---------------------------------|-----------------------------------------------------------------------------------------------------|--------------------------------------|
| **Compile-Time Polymorphism**   | Resolved at compile time. Uses function overloading and operator overloading.                       | Function Overloading, Operator Overloading  |
| **Run-Time Polymorphism**       | Resolved at runtime. Uses inheritance and virtual functions to allow dynamic method dispatch.       | Virtual Functions, Pure Virtual Functions (Abstract Classes) |

- **Compile-Time Polymorphism** provides more efficient code since the decision is made during compilation. However, it’s less flexible compared to run-time polymorphism.
- **Run-Time Polymorphism** offers flexibility and extensibility, particularly useful when working with class hierarchies and inheritance, allowing code to operate on base class pointers or references and still invoke derived class behavior.

Both types of polymorphism are essential in object-oriented design, enabling flexibility and maintainability of code.