In C++, when a class inherits from another, constructors play an important role in initializing the objects of both the base and derived classes. In the derived class, the constructor typically needs to invoke the constructor of the base class to initialize the base part of the object properly. 

### Constructors in Derived Classes

- **Base class constructor**: When a derived class object is created, the base class constructor is called first, followed by the derived class constructor.
- **Explicit constructor call**: If the base class has a parameterized constructor, the derived class constructor must explicitly call the base class constructor to initialize the base class part of the object.
- **Implicit call**: If the base class has a default constructor, it is automatically called unless you explicitly call another constructor in the base class.

### Basic Rules:
1. If the base class has a **default constructor**, it will be called automatically if not explicitly called in the derived class constructor.
2. If the base class has a **parameterized constructor**, you must explicitly call it from the derived class constructor.
3. If no constructor is defined in the derived class, the compiler will generate a default constructor for you.

### Example: Constructors in Derived Classes

#### 1. **Base Class Constructor Called Implicitly (Default Constructor)**

In this case, if the base class has a default constructor, it will be automatically called when an object of the derived class is created.

```cpp
#include <iostream>
using namespace std;

// Base class
class Base {
public:
    Base() {  // Default constructor
        cout << "Base class constructor called" << endl;
    }
};

// Derived class
class Derived : public Base {
public:
    Derived() {  // Default constructor
        cout << "Derived class constructor called" << endl;
    }
};

int main() {
    Derived obj;  // Create object of Derived class
    return 0;
}
```

**Output:**
```
Base class constructor called
Derived class constructor called
```

Here, the **default constructor** of `Base` is automatically called before the constructor of `Derived`.

#### 2. **Explicit Call to Base Class Constructor (Parameterized Constructor)**

When the base class has a **parameterized constructor**, you must explicitly call it from the derived class constructor.

```cpp
#include <iostream>
using namespace std;

// Base class
class Base {
public:
    Base(int a) {  // Parameterized constructor
        cout << "Base class constructor called with value: " << a << endl;
    }
};

// Derived class
class Derived : public Base {
public:
    Derived(int a, int b) : Base(a) {  // Calling base class constructor explicitly
        cout << "Derived class constructor called with value: " << b << endl;
    }
};

int main() {
    Derived obj(10, 20);  // Create object of Derived class
    return 0;
}
```

**Output:**
```
Base class constructor called with value: 10
Derived class constructor called with value: 20
```

In this case:
- The **parameterized constructor** of `Base` is called explicitly in the constructor initializer list of `Derived`.
- The `Derived` constructor takes two parameters, one of which is passed to the `Base` constructor.

#### 3. **Constructor Initialization Order**

In the derived class, the base class constructor is called **before** the derived class constructor's body is executed.

```cpp
#include <iostream>
using namespace std;

// Base class
class Base {
public:
    Base() {  // Default constructor
        cout << "Base class constructor called" << endl;
    }
};

// Derived class
class Derived : public Base {
public:
    Derived() {  // Default constructor
        cout << "Derived class constructor called" << endl;
    }
};

int main() {
    Derived obj;  // Create object of Derived class
    return 0;
}
```

**Output:**
```
Base class constructor called
Derived class constructor called
```

Here, the **Base class constructor** is called **first** even though the derived class constructor body is executed second. This ensures the base class part of the object is initialized before the derived class.

#### 4. **Constructor Overloading in Derived Classes**

A derived class can have multiple constructors, including overloaded constructors that accept different arguments. When a constructor is called, the appropriate constructor of the base class is selected.

```cpp
#include <iostream>
using namespace std;

// Base class
class Base {
public:
    Base() {  // Default constructor
        cout << "Base class default constructor" << endl;
    }

    Base(int a) {  // Parameterized constructor
        cout << "Base class constructor called with value: " << a << endl;
    }
};

// Derived class
class Derived : public Base {
public:
    Derived() : Base() {  // Calling the default constructor of Base
        cout << "Derived class default constructor" << endl;
    }

    Derived(int a) : Base(a) {  // Calling the parameterized constructor of Base
        cout << "Derived class constructor called with value: " << a << endl;
    }
};

int main() {
    Derived obj1;    // Calls default constructor
    Derived obj2(10);  // Calls parameterized constructor
    return 0;
}
```

**Output:**
```
Base class default constructor
Derived class default constructor
Base class constructor called with value: 10
Derived class constructor called with value: 10
```

In this case:
- The `Derived` class has two constructors, one that calls the **default constructor** of `Base` and another that calls the **parameterized constructor** of `Base`.

### Key Points:

1. **Base Class Constructor Calls**: When a derived class object is created, the base class constructor is always called first, followed by the derived class constructor.
   
2. **Constructor Initialization List**: The base class constructor is invoked in the initializer list of the derived class constructor.

3. **Default vs. Parameterized Constructors**: If the base class has a **default constructor**, it is automatically called. If it has a **parameterized constructor**, the derived class must explicitly call it.

4. **Constructor Overloading**: Derived classes can have multiple constructors that call different base class constructors depending on the arguments passed.

5. **Initialization Order**: The base class part of the object is always initialized first, followed by the derived class initialization.

By properly using constructors in derived classes, we can ensure the correct initialization of objects in a class hierarchy and manage the resources effectively.