# Shallow Copy Vs. Deep Copy

In C++, **shallow copy** and **deep copy** refer to two different approaches when copying objects, particularly in cases where objects contain dynamic memory or pointers.

### **Shallow Copy:**
A **shallow copy** means copying the values of the data members of the object as they are, without creating independent copies of dynamically allocated memory. If the object contains pointers, the shallow copy will simply copy the pointer values, meaning both the original and the copied objects will point to the same memory location.

**Problem with Shallow Copy:** If two objects share a pointer (via shallow copy), and one of the objects is deleted or modified, it may cause unintended side effects for the other object (e.g., double deletion of memory or unintended modification).

### **Deep Copy:**
A **deep copy** means creating a new independent copy of all the data members of the object, including dynamically allocated memory. This ensures that each object has its own copy of the dynamically allocated memory, so modifying one object doesn't affect the other.

### Example of Shallow Copy and Deep Copy:

Let’s look at an example where we have a class `Person` with a dynamically allocated member (a string).

#### **1. Shallow Copy:**

In the case of a shallow copy, the pointer is copied, but not the actual memory it points to.

```cpp
#include <iostream>
#include <cstring>

class Person {
private:
    char* name;

public:
    // Constructor to initialize the name
    Person(const char* n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    // Shallow Copy Constructor
    Person(const Person& other) {
        name = other.name;  // Just copy the pointer (shallow copy)
    }

    // Destructor to delete the memory
    ~Person() {
        delete[] name;
    }

    void display() const {
        std::cout << "Name: " << name << std::endl;
    }
};

int main() {
    Person p1("John");
    Person p2 = p1;  // Shallow copy, both p1 and p2 share the same memory

    p1.display();  // Output: Name: John
    p2.display();  // Output: Name: John

    // Deleting p1 will also affect p2, as they share the same memory
    return 0;
}
```

**Problem with Shallow Copy:**
- In the example above, `p1` and `p2` will both point to the same memory location for the `name` string. When one of the objects (`p1`) is destroyed, the memory will be deleted, and trying to access `p2` afterward will cause undefined behavior (dangling pointer).
- The destruction of `p1` will also delete the memory for `p2`, which is not the intended behavior.

#### **2. Deep Copy:**

In the case of a deep copy, we ensure that each object gets its own copy of the dynamically allocated memory.

```cpp
#include <iostream>
#include <cstring>

class Person {
private:
    char* name;

public:
    // Constructor to initialize the name
    Person(const char* n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    // Deep Copy Constructor
    Person(const Person& other) {
        name = new char[strlen(other.name) + 1];  // Allocate new memory
        strcpy(name, other.name);  // Copy the actual string data
    }

    // Destructor to delete the memory
    ~Person() {
        delete[] name;
    }

    void display() const {
        std::cout << "Name: " << name << std::endl;
    }
};

int main() {
    Person p1("John");
    Person p2 = p1;  // Deep copy, p1 and p2 have separate memory

    p1.display();  // Output: Name: John
    p2.display();  // Output: Name: John

    // Now p1 and p2 can be safely deleted without affecting each other
    return 0;
}
```

**Benefits of Deep Copy:**
- `p1` and `p2` each have their own copy of the `name` string, so when `p1` is destroyed, it won't affect `p2`.
- Both objects are independent of each other, and modifying one does not impact the other.

### **Key Differences Between Shallow and Deep Copy:**

| **Feature**                | **Shallow Copy**                                              | **Deep Copy**                                                  |
|----------------------------|---------------------------------------------------------------|---------------------------------------------------------------|
| **What is copied?**         | Only the values of the data members (including pointers).     | Copies all data members, including dynamically allocated memory. |
| **Memory sharing**          | Objects share memory for dynamically allocated resources.    | Objects have their own separate memory for dynamically allocated resources. |
| **Risk**                    | May cause issues like double deletion, undefined behavior.   | No risk of unintended side effects, as each object owns its memory. |
| **Use case**                | Suitable when the object does not own dynamic memory.        | Required when the object manages its own memory (e.g., pointers). |

### **When to Use Shallow vs. Deep Copy:**
- **Shallow Copy**: You can use shallow copy when your class does not manage dynamic memory or does not have pointers to dynamically allocated memory. It’s also acceptable for small objects where copying is simple and there’s no risk of shared memory problems.
  
- **Deep Copy**: Deep copy should be used when your class contains pointers to dynamically allocated memory (like arrays, objects, etc.). This ensures that each object has its own copy of the dynamically allocated memory, preventing issues such as double deletion or accidental modification.

### **Summary:**
- **Shallow Copy** copies the values of the members, including pointers, without allocating new memory. This can lead to problems when objects share the same dynamically allocated resources.
- **Deep Copy** creates a completely independent copy, including allocating new memory for dynamically allocated resources, ensuring that each object manages its own memory without interfering with other objects.

In cases where dynamic memory is involved, **deep copy** is generally preferred to avoid unintended side effects.