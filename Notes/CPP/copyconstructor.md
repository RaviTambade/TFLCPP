# Copy Constructor

In C++, a **copy constructor** is a special constructor used to create a new object by copying an existing object of the same class. It allows for the creation of a new object that is a copy of an existing object, and is typically used when passing or returning objects by value, or when an object is initialized with another object of the same type.

### Key Features of a Copy Constructor:
1. **Creates a Copy**: The primary purpose of a copy constructor is to create a new object as a copy of an existing object. This copy should have the same values as the original, but be a separate object in memory.
   
2. **Automatic or Explicit**: If you don't define a copy constructor, C++ will automatically provide a default one. However, if your class manages dynamic memory or requires special handling when copying, you should define your own copy constructor.

3. **Used in Certain Scenarios**:
   - **Pass-by-Value**: When an object is passed by value to a function.
   - **Return-by-Value**: When an object is returned from a function by value.
   - **Object Initialization**: When one object is initialized with another.

### Syntax of a Copy Constructor:
A copy constructor takes a reference to an object of the same class as its argument. The general syntax is:

```cpp
ClassName(const ClassName& other);
```

- `const` ensures the object being passed cannot be modified.
- `&` ensures that the object is passed by reference (to avoid unnecessary copying).
- `other` is the object being copied.

### Example of a Copy Constructor:
Let’s define a simple `Point` class with a copy constructor:

```cpp
#include <iostream>

class Point {
private:
    int x, y;
    
public:
    // Constructor to initialize the point
    Point(int x_val, int y_val) : x(x_val), y(y_val) {}

    // Copy constructor
    Point(const Point& other) {
        x = other.x;
        y = other.y;
        std::cout << "Copy constructor called!" << std::endl;
    }

    void display() const {
        std::cout << "Point(" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    Point p1(10, 20);  // Regular constructor
    Point p2 = p1;      // Copy constructor called here

    p1.display();       // Output: Point(10, 20)
    p2.display();       // Output: Point(10, 20)
    
    return 0;
}
```

### How the Copy Constructor Works:
- **p1** is initialized with `Point(10, 20)`.
- When **p2** is initialized with `p1`, the copy constructor is invoked, copying the values of `x` and `y` from `p1` to `p2`.
- The message `"Copy constructor called!"` is printed to indicate when the copy constructor is used.

### When Is the Copy Constructor Called?
1. **Pass-by-Value**: When you pass an object by value to a function.
   ```cpp
   void printPoint(Point p) {
       p.display();
   }

   int main() {
       Point p1(5, 10);
       printPoint(p1);  // Copy constructor is called
   }
   ```

2. **Return-by-Value**: When an object is returned from a function by value.
   ```cpp
   Point createPoint() {
       Point p(1, 2);
       return p;  // Copy constructor is called (possibly optimized away by Return Value Optimization)
   }

   int main() {
       Point p1 = createPoint();  // Copy constructor is called
   }
   ```

3. **Object Initialization**: When an object is initialized with another object.
   ```cpp
   Point p1(2, 3);
   Point p2 = p1;  // Copy constructor is called
   ```

### Default vs. User-Defined Copy Constructor:
- **Default Copy Constructor**: If you don't define a copy constructor, the compiler generates one for you. The default copy constructor performs a **shallow copy**, meaning it simply copies the values of each member of the object.
  
- **User-Defined Copy Constructor**: When your class manages dynamic memory (e.g., uses pointers), you may need to define a custom copy constructor to perform a **deep copy**. A shallow copy could result in issues such as double deletion of memory if both objects delete the same memory upon destruction.

### Example of Deep Copy with Copy Constructor:
If your class uses dynamic memory (e.g., pointers), you should implement a **deep copy** in the copy constructor to avoid issues like double freeing memory.

```cpp
#include <iostream>
#include <cstring>

class String {
private:
    char* str;
    
public:
    // Constructor to initialize the string
    String(const char* s) {
        str = new char[strlen(s) + 1];  // Allocate memory
        strcpy(str, s);  // Copy the string
    }

    // Copy constructor (deep copy)
    String(const String& other) {
        str = new char[strlen(other.str) + 1];  // Allocate new memory
        strcpy(str, other.str);  // Copy the string
    }

    // Destructor to free the memory
    ~String() {
        delete[] str;
    }

    void display() const {
        std::cout << str << std::endl;
    }
};

int main() {
    String s1("Hello");
    String s2 = s1;  // Copy constructor is called (deep copy)
    
    s1.display();  // Output: Hello
    s2.display();  // Output: Hello
    
    return 0;
}
```

### Conclusion:
The **copy constructor** in C++ is used to create a new object as a copy of an existing object. It is essential when dealing with dynamic memory or when objects are passed/returned by value. The default copy constructor performs a shallow copy, but when dealing with dynamic memory or pointers, a user-defined copy constructor is necessary to perform a **deep copy** and prevent memory management issues like double deletion.