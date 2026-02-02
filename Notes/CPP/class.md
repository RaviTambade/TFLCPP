# What is a **Class**?

A **class** in C++ is a **user-defined data type**.  
It lets you **combine data (variables)** and **functions (methods)** that operate on that data into a **single unit**.

> Think of a class as a **blueprint**, and an object as the **real-world item** built from that blueprint.


### 📦 Example: Class and Object

```cpp
  #include <iostream>
using namespace std;

// Define a class
class Patient {
public:
    // Data members (attributes)
    string name;
    int age;
    string disease;

    // Member function (behavior)
    void showDetails() {
        cout << "Patient Name : " << name << endl;
        cout << "Age          : " << age << endl;
        cout << "Disease      : " << disease << endl;
    }
};

int main() {
    // Create an object of Patient class
    Patient patient1;

    patient1.name = "Ravi Kumar";
    patient1.age = 45;
    patient1.disease = "Diabetes";

    patient1.showDetails();

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





### 💬 In Simple Words:
- Class = Plan### 🧰 Constructor Example

```cpp
#include <iostream>
using namespace std;

class Patient {
public:
    string name;
    int age;
    string disease;

    // Constructor
    Patient(string n, int a, string d) {
        name = n;
        age = a;
        disease = d;
    }

    void showDetails() {
        cout << "Patient Name : " << name << endl;
        cout << "Age          : " << age << endl;
        cout << "Disease      : " << disease << endl;
    }
};

int main() {
    // Object creation using constructor
    Patient p1("Anita Sharma", 38, "Hypertension");

    p1.showDetails();

    return 0;
}

```

- Object = Actual thing
- You use classes to create **organized, reusable, clean code**.

