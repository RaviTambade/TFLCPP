**RTTI** (Run-Time Type Information) in C++ is a mechanism that allows the type of an object to be determined during the execution of a program. RTTI provides information about the type of an object when you work with polymorphic types (i.e., classes that use inheritance and have virtual functions). It enables features such as **dynamic type identification** and **dynamic casting**.

### Key Concepts in RTTI:

1. **`typeid` Operator**:
   The `typeid` operator is used to get the type information of an object at runtime. It can be used on objects of polymorphic classes (those with at least one virtual function). The result of `typeid` is an object of type `type_info` that contains the type information.

   Example:
   ```cpp
   #include <iostream>
   #include <typeinfo>

   class Base {
   public:
       virtual ~Base() {}  // Ensure polymorphism
   };

   class Derived : public Base {
   public:
       void display() { std::cout << "Derived class" << std::endl; }
   };

   int main() {
       Base* basePtr = new Derived();
       
       // Use typeid to check the actual type of the object
       std::cout << "Type of object: " << typeid(*basePtr).name() << std::endl;

       delete basePtr;
       return 0;
   }
   ```

   - **`typeid(*basePtr).name()`** returns the type information of the object that `basePtr` is pointing to at runtime (which is `Derived` in this case).

2. **`dynamic_cast`**:
   RTTI enables **safe downcasting** using the `dynamic_cast` operator. It allows you to safely convert pointers or references of base class types to derived class types. If the cast is not valid (e.g., casting a pointer of an unrelated type), `dynamic_cast` will return `nullptr` for pointers or throw `std::bad_cast` for references.

   Example:
   ```cpp
   #include <iostream>
   #include <typeinfo>

   class Base {
   public:
       virtual void show() { std::cout << "Base class" << std::endl; }
       virtual ~Base() {}
   };

   class Derived : public Base {
   public:
       void show() override { std::cout << "Derived class" << std::endl; }
   };

   int main() {
       Base* basePtr = new Derived();
       
       // Safe downcast to Derived
       Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);

       if (derivedPtr) {
           derivedPtr->show();  // Derived class method
       } else {
           std::cout << "Invalid cast" << std::endl;
       }

       delete basePtr;
       return 0;
   }
   ```

   - **`dynamic_cast<Derived*>(basePtr)`** safely downcasts `basePtr` to a pointer of type `Derived*`. Since `basePtr` points to an object of type `Derived`, the cast is successful, and we can call the `Derived` class method.

3. **Polymorphism**:
   RTTI is most useful when dealing with polymorphic objects (objects of classes that inherit from other classes and have virtual functions). The `typeid` operator and `dynamic_cast` help you identify and safely downcast objects to their actual types at runtime.

### Why RTTI is Useful:
1. **Type Safety**: RTTI provides a way to ensure safe casting in a polymorphic class hierarchy (e.g., using `dynamic_cast`).
2. **Debugging and Diagnostics**: You can use `typeid` to determine the actual type of an object during debugging.
3. **Design Patterns**: RTTI can be useful in implementing certain design patterns, such as the **Visitor Pattern** or **Factory Pattern**, where you may need to know the actual type of an object at runtime.

### Example Using `typeid` and `dynamic_cast`:

```cpp
#include <iostream>
#include <typeinfo>

class Base {
public:
    virtual void show() { std::cout << "Base class" << std::endl; }
    virtual ~Base() {}
};

class Derived : public Base {
public:
    void show() override { std::cout << "Derived class" << std::endl; }
};

class AnotherClass {};

int main() {
    Base* basePtr = new Derived();

    // Using typeid to get the actual type of the object
    std::cout << "Type of basePtr: " << typeid(*basePtr).name() << std::endl;  // Output: Derived

    // Using dynamic_cast to safely downcast
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    if (derivedPtr) {
        derivedPtr->show();  // Derived class method
    } else {
        std::cout << "Invalid cast" << std::endl;
    }

    // Invalid downcast to unrelated class
    AnotherClass* anotherPtr = dynamic_cast<AnotherClass*>(basePtr);
    if (!anotherPtr) {
        std::cout << "Invalid cast to AnotherClass" << std::endl;
    }

    delete basePtr;
    return 0;
}
```

### Output:
```
Type of basePtr: Derived
Derived class
Invalid cast to AnotherClass
```

### Important Points:
1. **RTTI Requires Polymorphism**: RTTI only works with polymorphic classes (classes with at least one virtual function). If a class has no virtual functions, `typeid` will not return the actual type of the object, and `dynamic_cast` will not be available.
   
2. **Performance Overhead**: RTTI can incur a slight runtime performance overhead because the compiler adds mechanisms to store and manage type information.

3. **Disabling RTTI**: You can disable RTTI in your compiler settings (e.g., using `-fno-rtti` with GCC/Clang or `/GR-` with MSVC). This might be useful in performance-critical applications where RTTI is not required.

### Summary:
- **RTTI** allows runtime type identification, helping you determine the actual type of an object at runtime and safely cast between different types.
- It is primarily used with **polymorphic** classes (those with virtual functions).
- **`typeid`** is used to obtain type information, while **`dynamic_cast`** is used for safe casting.
