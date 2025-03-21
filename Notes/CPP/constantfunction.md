# Constant Functions

In C++, **constant functions** (often referred to as **const member functions**) are member functions that promise not to modify the object they are called on. They are declared using the `const` keyword at the end of the function declaration.

### Purpose of Constant Functions:
- **Maintain Object Integrity**: A constant function guarantees that the object's state (i.e., its member variables) will not be modified. This is useful when you want to read the data of an object without altering it.
- **Const Correctness**: Const correctness ensures that functions that are not supposed to modify the object are marked as `const`. This helps in creating more maintainable and predictable code.

### Syntax of a Constant Function:
A constant function is declared by appending `const` at the end of the function declaration.

```cpp
class MyClass {
public:
    int data;

    // Constant function
    void printData() const {
        std::cout << "Data: " << data << std::endl;
    }
};
```

In this example, `printData()` is a constant function because it is declared with the `const` keyword at the end. This means that `printData()` will not modify the `data` member or any other member variables of the object.

### Key Points:
1. **Const after function signature**: The `const` keyword goes at the end of the function declaration, after the parameter list.
2. **Cannot Modify Member Variables**: Inside a constant function, you cannot modify the object's member variables (unless they are marked as `mutable`).
3. **Can Only Call Other Constant Functions**: A constant function can only call other constant functions. It cannot call non-const member functions that modify the object.

### Example of Constant Functions:

```cpp
#include <iostream>

class MyClass {
private:
    int data;

public:
    MyClass(int val) : data(val) {}

    // Constant function: This will not modify the object
    int getData() const {
        return data;
    }

    // Constant function: This will not modify the object
    void printData() const {
        std::cout << "Data: " << data << std::endl;
    }

    // Non-constant function: This modifies the object
    void setData(int val) {
        data = val;
    }
};

int main() {
    MyClass obj(10);

    // Calling constant member function
    obj.printData();  // Output: Data: 10

    // Calling non-constant member function
    obj.setData(20);
    obj.printData();  // Output: Data: 20

    // Calling constant function to get the value of data
    std::cout << "Data from constant function: " << obj.getData() << std::endl;  // Output: 20

    return 0;
}
```

### Key Points in the Example:
- `getData()` and `printData()` are constant member functions, and they do not modify the internal state of the object.
- The `setData()` function is not constant and modifies the object’s state.
- When a constant function is called on a constant object, you cannot call non-const functions (which modify the object). For example, the following code would result in an error:

### Example with Constant Object:
```cpp
const MyClass obj(10);
obj.setData(20);  // Error: Cannot call non-const function on a const object
```

### `mutable` Keyword:
- By default, constant functions cannot modify member variables, but the `mutable` keyword allows a specific member variable to be modified even within a `const` function. This is typically used for caching or temporary internal data.

```cpp
class MyClass {
private:
    int data;
    mutable int cache;  // Mutable member that can be modified even in const functions

public:
    MyClass(int val) : data(val), cache(0) {}

    int getData() const {
        if (cache == 0) {
            cache = data;  // Modify mutable member within const function
        }
        return cache;
    }
};
```

### Summary of Constant Functions:
- **Const member functions**: Use the `const` keyword at the end of the function declaration to ensure that the object’s state is not modified.
- **Use cases**: Ideal for getter functions, read-only access, and ensuring that certain functions do not alter the object’s state.
- **Restriction**: Constant functions cannot modify member variables unless those variables are marked as `mutable`. They also cannot call non-constant member functions.

By using constant functions, you can ensure that your code adheres to **const correctness**, which helps in maintaining object integrity, especially in large projects where objects should not be unexpectedly modified.