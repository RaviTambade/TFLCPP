# What is a **Class**?

A **class** in C++ is a **user-defined data type**.  
It lets you **combine data (variables)** and **functions (methods)** that operate on that data into a **single unit**.

> Think of a class as a **blueprint**, and an object as the **real-world item** built from that blueprint.


### 📦 Example: Class and Object

```cpp
#include <iostream>
using namespace std;

// Define a class
class Animal {
public:
    // Data members (variables)
    string name;
    int age;

    // Member function
    void speak() {
        cout << name << " says Hello!" << endl;
    }
};

int main() {
    // Create an object
    Animal dog;
    dog.name = "Buddy";
    dog.age = 3;

    dog.speak();  // Output: Buddy says Hello!
    return 0;
}
```

### 🧠 Key Concepts of a Class

| Concept             | Description |
|---------------------|-------------|
| **Class**           | Blueprint/template |
| **Object**          | Instance of a class |
| **Data Members**    | Variables in the class |
| **Member Functions**| Functions defined inside the class |
| **Constructor**     | Special function to initialize objects |
| **Access Specifiers** | `public`, `private`, `protected` |

### 🔐 Access Specifiers (Quick Recap)

- `public`: Accessible from outside the class
- `private`: Only accessible inside the class
- `protected`: Like private, but accessible in derived classes

### 🧰 Constructor Example

```cpp
class Car {
public:
    string model;

    // Constructor
    Car(string m) {
        model = m;
    }

    void show() {
        cout << "Car model: " << model << endl;
    }
};

int main() {
    Car c("Tesla");
    c.show(); // Output: Car model: Tesla
}
```


### 💬 In Simple Words:
- Class = Plan
- Object = Actual thing
- You use classes to create **organized, reusable, clean code**.

