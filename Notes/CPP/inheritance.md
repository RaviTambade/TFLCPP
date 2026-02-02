# **Inheritance in C++**
 

🧑‍🏫 *“Imagine a royal family where every generation passes down knowledge, traditions, and responsibilities to the next. The prince learns from the king, just like a child learns from a parent. In programming, this idea is beautifully captured through **inheritance**.”*

Let me take you into the kingdom of **Object-Oriented Programming in C++**, where **inheritance** is the royal tradition.

## 👑 What is Inheritance?

In C++, **inheritance** is a mechanism where a new class (called the **derived class**) acquires the properties and behaviors (i.e., data and functions) of an existing class (called the **base class**).

🧬 This enables:

* **Code reusability** – No need to rewrite common logic.
* **Hierarchy** – Organizes and models real-world relationships.
* **Extensibility** – Easily add or override features in new classes.

## 🏰 Royal Analogy: The Tale of the Employee Dynasty

Let’s say there’s a kingdom called **SoftwareCorp**.

At its heart is a class called `Employee`. This class defines common traits: a name, an ID, and a method to display info.

Now, the company has a special class of people — `Manager`, `Engineer`, `Intern` — each with their own roles, but all of them are still `Employees`.

### 🔧 Here’s how we implement it in C++:

```cpp
#include <iostream>
using namespace std;

class Employee {
public:
    string name;
    int id;

    void displayInfo() {
        cout << "Name: " << name << ", ID: " << id << endl;
    }
};

class Manager : public Employee {
public:
    void approveLeave() {
        cout << name << " approved the leave." << endl;
    }
};
```

### 🧪 In `main()`:

```cpp
int main() {
    Manager m;
    m.name = "Rajesh";
    m.id = 101;

    m.displayInfo();      // Inherited from Employee
    m.approveLeave();     // Specific to Manager

    return 0;
}
```

## 🧠 Mentor Explains...

👨‍🏫 *“See how the Manager automatically gets everything that the Employee has? That’s the beauty of inheritance. You write once, reuse many times — just like family values passed down generations.”*


## ⚙️ Types of Inheritance in C++

C++ supports various forms of inheritance:

| Type         | Description                                  | Example                              |
| ------------ | -------------------------------------------- | ------------------------------------ |
| Single       | One base class, one derived class            | `Manager` from `Employee`            |
| Multilevel   | Inheritance in layers                        | `SeniorManager → Manager → Employee` |
| Multiple     | Derived class from **multiple** base classes | `Engineer : public Coder, Tester`    |
| Hierarchical | Multiple classes from the same base class    | `Manager`, `Intern` from `Employee`  |
| Hybrid       | Combination of above types                   | Complex real-world systems           |


## 🔍 Real-World Example

🎓 Consider a `Person` class:

* `Student` and `Teacher` can **inherit** from `Person`.

🏥 In a hospital system:

* `Doctor`, `Nurse`, `Receptionist` can inherit from a common `Staff` class.

## 🔒 Access Specifiers in Inheritance

* **`public` inheritance**: "is-a" relationship is preserved (most common).
* **`protected` inheritance**: restricts external access.
* **`private` inheritance**: behaves more like "has-a", internal to class.

## 🎯 Practice Time for Students

Build a mini system where:

* You have a base class `Vehicle`
* Derived classes `Car`, `Truck`, and `Bike`
* Add one unique method in each derived class
* Call base and derived methods in `main()`

## 💡 Mentor's Final Words:

> *“Inheritance is not just a feature. It’s a design philosophy. It teaches you to think hierarchically, reuse responsibly, and extend elegantly.”*

Write classes like you’re building a legacy — because in OOP, **you are**. 💫

#### **Syntax for Inheritance**:

```cpp
class BaseClass {
    // Base class members (variables and functions)
};

class DerivedClass : accessSpecifier BaseClass {
    // Derived class members
};
```

- **BaseClass** is the class from which properties and behaviors are inherited.
- **DerivedClass** is the class that inherits from the base class.
- The **accessSpecifier** (e.g., `public`, `protected`, `private`) determines the level of access the derived class has to the base class members.

### **Types of Inheritance in C++**

There are **five types of inheritance** in C++:

1. **Single Inheritance**
2. **Multiple Inheritance**
3. **Multilevel Inheritance**
4. **Hierarchical Inheritance**
5. **Hybrid Inheritance**

Let's go through each type in detail:

### **1. Single Inheritance**

In single inheritance, a derived class inherits from only one base class. This is the simplest form of inheritance.

#### **Example of Single Inheritance**:
```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "Eating food." << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Barking!" << endl;
    }
};

int main() {
    Dog dog;
    dog.eat();  // Inherited from Animal
    dog.bark(); // Defined in Dog
    return 0;
}
```

**Explanation**:
- The `Dog` class is derived from the `Animal` class.
- The `Dog` class inherits the `eat()` function from the `Animal` class.
- `Dog` can also define its own unique behavior, like `bark()`.

### **2. Multiple Inheritance**

In multiple inheritance, a derived class inherits from more than one base class. This allows the derived class to have members from multiple base classes.

#### **Example of Multiple Inheritance**:
```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "Eating food." << endl;
    }
};

class Mammal {
public:
    void walk() {
        cout << "Walking on land." << endl;
    }
};

class Dog : public Animal, public Mammal {
public:
    void bark() {
        cout << "Barking!" << endl;
    }
};

int main() {
    Dog dog;
    dog.eat();   // Inherited from Animal
    dog.walk();  // Inherited from Mammal
    dog.bark();  // Defined in Dog
    return 0;
}
```

**Explanation**:
- The `Dog` class inherits from both the `Animal` and `Mammal` classes.
- It has access to the members from both base classes (`eat()` from `Animal`, `walk()` from `Mammal`) and its own function (`bark()`).

### **3. Multilevel Inheritance**

In multilevel inheritance, a class is derived from another derived class, creating a chain of inheritance. The derived class inherits from a base class, and then a subclass inherits from the derived class.

#### **Example of Multilevel Inheritance**:
```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "Eating food." << endl;
    }
};

class Mammal : public Animal {
public:
    void giveBirth() {
        cout << "Giving birth to live young." << endl;
    }
};

class Dog : public Mammal {
public:
    void bark() {
        cout << "Barking!" << endl;
    }
};

int main() {
    Dog dog;
    dog.eat();       // Inherited from Animal
    dog.giveBirth(); // Inherited from Mammal
    dog.bark();      // Defined in Dog
    return 0;
}
```

**Explanation**:
- The `Dog` class inherits from the `Mammal` class, which in turn inherits from the `Animal` class.
- The `Dog` class can access members from both `Animal` and `Mammal`, as well as its own members.

### **4. Hierarchical Inheritance**

In hierarchical inheritance, multiple derived classes inherit from a single base class. This allows different classes to share a common base class but extend their own unique functionality.

#### **Example of Hierarchical Inheritance**:
```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "Eating food." << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Barking!" << endl;
    }
};

class Cat : public Animal {
public:
    void meow() {
        cout << "Meowing!" << endl;
    }
};

int main() {
    Dog dog;
    dog.eat();  // Inherited from Animal
    dog.bark(); // Defined in Dog

    Cat cat;
    cat.eat();  // Inherited from Animal
    cat.meow(); // Defined in Cat

    return 0;
}
```

**Explanation**:
- Both `Dog` and `Cat` classes inherit from the same `Animal` class.
- Each derived class (`Dog` and `Cat`) can add its own specific functionality, such as `bark()` for `Dog` and `meow()` for `Cat`, while still inheriting common functionality like `eat()` from `Animal`.

### **5. Hybrid Inheritance**

Hybrid inheritance is a combination of two or more types of inheritance. It allows a derived class to inherit properties from multiple classes in different ways (e.g., a combination of multiple and multilevel inheritance).

#### **Example of Hybrid Inheritance**:
```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "Eating food." << endl;
    }
};

class Mammal {
public:
    void giveBirth() {
        cout << "Giving birth to live young." << endl;
    }
};

class Dog : public Animal, public Mammal {
public:
    void bark() {
        cout << "Barking!" << endl;
    }
};

class Labrador : public Dog {
public:
    void specialBehavior() {
        cout << "Labrador special behavior!" << endl;
    }
};

int main() {
    Labrador lab;
    lab.eat();             // Inherited from Animal
    lab.giveBirth();       // Inherited from Mammal
    lab.bark();            // Inherited from Dog
    lab.specialBehavior(); // Defined in Labrador

    return 0;
}
```

**Explanation**:
- `Labrador` inherits from `Dog`, which in turn inherits from `Animal` and `Mammal`.
- This creates a hybrid inheritance structure combining multiple inheritance (`Animal` and `Mammal`) and multilevel inheritance (`Labrador` → `Dog` → `Animal`).


### **Access Specifiers in Inheritance**

When inheriting from a base class, C++ allows you to specify the level of access for the base class members. This is done using **access specifiers**:

- **`public` inheritance**: Public members of the base class become public members of the derived class. Private and protected members remain inaccessible to the derived class.
  
- **`protected` inheritance**: Public and protected members of the base class become protected members in the derived class.

- **`private` inheritance**: Public and protected members of the base class become private members of the derived class.

---

### **Summary of Types of Inheritance**

| **Type of Inheritance**      | **Description**                                                                 | **Example**                              |
|------------------------------|---------------------------------------------------------------------------------|------------------------------------------|
| **Single Inheritance**        | A class inherits from only one base class.                                      | `class Dog : public Animal {}`           |
| **Multiple Inheritance**      | A class inherits from more than one base class.                                 | `class Dog : public Animal, public Mammal {}` |
| **Multilevel Inheritance**    | A class is derived from another derived class.                                 | `class Dog : public Mammal {}`           |
| **Hierarchical Inheritance**  | Multiple classes inherit from a single base class.                             | `class Dog : public Animal {}`, `class Cat : public Animal {}` |
| **Hybrid Inheritance**        | A combination of two or more types of inheritance.                             | `class Labrador : public Dog, public Mammal {}` |

### Conclusion

Inheritance in C++ allows for the creation of hierarchical relationships between classes, facilitating code reuse and modularity. Depending on the structure and needs of your program, you can choose the appropriate type of inheritance. C++ supports a variety of inheritance types, including single, multiple, multilevel, hierarchical, and hybrid inheritance, each providing different ways to organize and extend functionality.