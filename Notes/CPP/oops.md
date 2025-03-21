Object-Oriented Programming (O O P) is a programming paradigm based on the concept of objects, which contain both data (attributes) and methods (functions) that operate on the data. C++ is an object-oriented language that supports several core OOP principles. These principles are designed to help organize and structure software to make it more reusable, scalable, and maintainable.

Here are the key OOP concepts in C++:

### 1. **Classes and Objects**
- **Class**: A class is a blueprint or template for creating objects. It defines the attributes and behaviors that the objects created from the class will have. A class can contain data members (variables) and member functions (methods).
- **Object**: An object is an instance of a class. Each object has its own copy of the data members defined by the class, and it can call the member functions to interact with the data.

#### Example:
```cpp
#include <iostream>
using namespace std;

// Define a class
class Car {
public:
    // Data members
    string brand;
    int year;

    // Member function
    void displayInfo() {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

int main() {
    // Create an object of the class
    Car car1;
    car1.brand = "Toyota";
    car1.year = 2021;

    // Call a member function
    car1.displayInfo();
}
```

### 2. **Encapsulation**
Encapsulation is the concept of bundling data (attributes) and methods (functions) that operate on the data within a single unit, i.e., a class. It restricts direct access to some of the object's components and protects the object from unintended modification. This is achieved by using **access specifiers**:

- **Public**: Members are accessible from outside the class.
- **Private**: Members are accessible only within the class.
- **Protected**: Members are accessible within the class and derived classes.

Encapsulation provides **data hiding**, ensuring that the internal state of an object is protected and can only be modified via controlled methods (getters and setters).

#### Example:
```cpp
class BankAccount {
private:
    double balance; // Private data member

public:
    // Getter
    double getBalance() {
        return balance;
    }

    // Setter
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }
};

int main() {
    BankAccount account;
    account.deposit(1000);  // Deposit 1000 into account
    cout << "Balance: " << account.getBalance() << endl;  // Access balance through getter
}
```

### 3. **Inheritance**
Inheritance allows a new class (derived class) to inherit the properties and behaviors (data members and member functions) of an existing class (base class). This promotes code reuse and creates a hierarchical relationship between classes.

- **Base class**: The class whose properties and behaviors are inherited.
- **Derived class**: The class that inherits properties and behaviors from the base class.

Inheritance supports the concept of **"is-a"** relationship (e.g., a "Dog" **is-a** "Animal").

#### Example:
```cpp
class Animal {
public:
    void speak() {
        cout << "Animal speaks" << endl;
    }
};

// Dog class inherits from Animal
class Dog : public Animal {
public:
    void bark() {
        cout << "Dog barks" << endl;
    }
};

int main() {
    Dog dog;
    dog.speak();  // Inherited function
    dog.bark();   // Dog's own function
}
```

### 4. **Polymorphism**
Polymorphism means "many forms" and allows objects of different classes to be treated as objects of a common base class. The most common forms of polymorphism in C++ are **compile-time (function overloading and operator overloading)** and **run-time (virtual functions)** polymorphism.

- **Compile-time polymorphism** (Method overloading, Operator overloading): The function or operator is determined at compile time based on the function signature or operator.
- **Run-time polymorphism** (Virtual functions): The function is determined at runtime based on the object’s actual type, enabling dynamic method dispatch.

#### Example (Run-time Polymorphism with Virtual Functions):
```cpp
class Animal {
public:
    virtual void speak() {   // Virtual function
        cout << "Animal speaks" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {  // Overridden function
        cout << "Dog barks" << endl;
    }
};

int main() {
    Animal* animalPtr;
    Dog dog;

    // Pointer of type Animal pointing to Dog object
    animalPtr = &dog;
    animalPtr->speak();  // Dog's version of speak is called, output: "Dog barks"
}
```

### 5. **Abstraction**
Abstraction is the concept of hiding the complex implementation details and exposing only the essential features to the user. It simplifies the interaction with complex systems by exposing only relevant information.

- **Abstract class**: A class that contains at least one pure virtual function. It cannot be instantiated, and it is used as a base class for other classes.

A pure virtual function is a function with no definition in the base class and is defined as `virtual void functionName() = 0;`

#### Example:
```cpp
class Shape {
public:
    // Pure virtual function for area
    virtual void area() = 0;
};

class Circle : public Shape {
public:
    void area() override {
        cout << "Area of Circle" << endl;
    }
};

class Square : public Shape {
public:
    void area() override {
        cout << "Area of Square" << endl;
    }
};

int main() {
    Shape* shape;
    Circle circle;
    Square square;

    shape = &circle;
    shape->area();  // Outputs "Area of Circle"

    shape = &square;
    shape->area();  // Outputs "Area of Square"
}
```

### 6. **Constructors and Destructors**
- **Constructor**: A special member function that is automatically called when an object is created. It is used to initialize objects.
- **Destructor**: A special member function that is automatically called when an object goes out of scope or is explicitly deleted. It is used to clean up any resources acquired by the object.

#### Example:
```cpp
class MyClass {
public:
    // Constructor
    MyClass() {
        cout << "Constructor is called!" << endl;
    }

    // Destructor
    ~MyClass() {
        cout << "Destructor is called!" << endl;
    }
};

int main() {
    MyClass obj;  // Constructor called when the object is created
}  // Destructor called when the object goes out of scope
```

### 7. **Friend Functions**
A friend function is a function that is not a member of a class, but it has access to the class's private and protected members. It is declared using the `friend` keyword inside the class definition.

#### Example:
```cpp
class Box {
private:
    double length;
public:
    Box() : length(5.0) {}
    friend void displayLength(Box);  // Friend function declaration
};

// Friend function definition
void displayLength(Box b) {
    cout << "Length: " << b.length << endl;
}

int main() {
    Box box;
    displayLength(box);  // Accessing private member via friend function
}
```

### Summary of OOP Concepts in C++:
1. **Classes and Objects**: Defines the structure and behavior of data.
2. **Encapsulation**: Protects data by hiding it and only allowing access through methods.
3. **Inheritance**: Allows a class to inherit properties and methods from another class.
4. **Polymorphism**: Enables the same function or operator to behave differently based on the object.
5. **Abstraction**: Hides complex details and exposes only the essential features.
6. **Constructors and Destructors**: Automatically initialize and clean up resources for objects.
7. **Friend Functions**: Allows external functions to access private and protected members of a class.

These principles make C++ a powerful object-oriented language that facilitates the creation of modular, reusable, and maintainable code.