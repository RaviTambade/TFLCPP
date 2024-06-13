# Inheritance

Inheritance is a fundamental concept in object-oriented programming (OOP) that allows a class (called a derived class or subclass) to inherit properties and behavior from another class (called a base class or superclass). This enables code reuse and promotes the creation of hierarchical relationships between classes.

In C++, inheritance is implemented using the `class` keyword, followed by a colon `:` and the access specifier (public, protected, or private), and then the name of the base class. Here's a basic syntax:

```cpp
class BaseClass {
    // Base class members
};

class DerivedClass : access_specifier BaseClass {
    // Derived class members
};
```

In this syntax:

- `BaseClass` is the name of the base class.
- `DerivedClass` is the name of the derived class.
- `access_specifier` determines the access level for the inheritance relationship (`public`, `protected`, or `private`). By default, if no access specifier is provided, it is `private`.

There are three types of inheritance in C++:

1. **Public Inheritance:** In public inheritance, public members of the base class remain public in the derived class, protected members remain protected, and private members remain inaccessible. It represents an "is-a" relationship, where the derived class is a type of the base class.

2. **Protected Inheritance:** In protected inheritance, public and protected members of the base class become protected in the derived class, and private members remain inaccessible. Protected inheritance is less common and represents a weaker form of encapsulation.

3. **Private Inheritance:** In private inheritance, all members of the base class become private in the derived class, regardless of their original access level. Private inheritance is used when you want to hide the implementation details of the base class and is more about implementation inheritance than interface inheritance.

Inheritance facilitates code reuse by allowing derived classes to inherit properties and behavior from base classes. It promotes modularity, extensibility, and polymorphism in object-oriented designs. However, it should be used judiciously, and the class hierarchy should be carefully designed to avoid excessive coupling and to promote flexibility and maintainability in the codebase.