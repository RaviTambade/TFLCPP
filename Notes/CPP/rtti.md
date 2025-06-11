👨‍🏫 **Understanding RTTI (Run-Time Type Information) in C++**

🧑‍🏫 *“Let me tell you a little story…*

In our C++ kingdom, there were many creatures: 🐶 `Dog`, 🐱 `Cat`, 🦁 `Tiger` — all inherited from the mighty `Animal` class.

Now imagine you had a pointer to an `Animal`, but during runtime, you wanted to know which *actual creature* it pointed to.

How would you find out?

That’s where the **magic of RTTI** comes in.”


## 🔍 What is RTTI?

**RTTI (Run-Time Type Information)** lets you:

* Identify the **actual type** of an object during **runtime**.
* Use **`typeid`** to query type information.
* Use **`dynamic_cast`** to safely downcast polymorphic objects.

🧠 It only works with **polymorphic classes** — that is, classes with **at least one virtual function**.

## 🧪 Use Case: Why do we need RTTI?

Let’s say you’re designing a **zoo management system**. You have a list of `Animal*`, but at runtime, you want to:

* Log what kind of animal each pointer is actually pointing to.
* Call special functions only if the animal is a `Tiger`.

## 🔑 RTTI Tools in C++

### 1. **`typeid` Operator**

Used to retrieve the **type info** of an object.

```cpp
#include <iostream>
#include <typeinfo>
using namespace std;

class Animal {
public:
    virtual void speak() {}
};

class Dog : public Animal { };
class Cat : public Animal { };

int main() {
    Animal* a = new Dog;

    cout << "Actual type: " << typeid(*a).name() << endl;
}
```

🧠 Output: Might show `Dog` (depends on the compiler/mangled name)


### 2. **`dynamic_cast` Operator**

Used to **safely cast** a base class pointer to a derived class.

```cpp
Animal* a = new Cat;

Cat* c = dynamic_cast<Cat*>(a);
if (c != nullptr) {
    cout << "It's a Cat!" << endl;
}
```

✅ If the cast is valid, you get a pointer.
❌ If not, `dynamic_cast` returns `nullptr` (for pointers) or throws `bad_cast` (for references).


## 🚦 RTTI vs Static Cast

| Feature       | `static_cast` | `dynamic_cast` (RTTI)   |
| ------------- | ------------- | ----------------------- |
| Type checked? | ❌ No          | ✅ Yes (safe at runtime) |
| Cost          | 🔋 Low        | ⚡ Slight overhead       |
| Works on      | Any type      | Polymorphic types only  |

## 🧭 Mentor’s Analogy

> “RTTI is like checking someone's ID card before you trust them to enter a secure room.
> If they’re really a `Tiger` and not just any `Animal`, then let them roar!”

RTTI helps us **make safe decisions** at runtime about what type we’re actually dealing with — especially when working with **pointers to base classes**.

## 🏁 Final Words

RTTI makes your code:

* **Safe** (avoids invalid downcasts)
* **Smart** (acts based on real type)
* **Flexible** (works with polymorphism)

So next time you're unsure what your base pointer is really pointing to —
don’t guess… just **ask the RTTI system!** 🙌

 

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
