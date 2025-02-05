# Pointers

Pointers are a fundamental concept in C++ that allow you to directly access and manipulate memory.  

### 1. Declaration and Initialization

A pointer is declared by specifying the type it points to, followed by an asterisk `*`. 

```cpp
int main() {
    int marks = 10;          // A normal integer variable
    int* ptrMarks = &marks;       // Pointer ptrMarks holds the address of variable marks

    return 0;
}
```

### 2. Dereferencing

Dereferencing a pointer means accessing the value at the address the pointer is pointing to.

```cpp
#include <iostream>

int main() {
    int a = 10;
    int* p = &a;

    std::cout << "Value of a: " << a << std::endl;        // Outputs 10
    std::cout << "Value through pointer p: " << *p << std::endl; // Outputs 10

    *p = 20; // Changing the value of a through the pointer
    std::cout << "New value of a: " << a << std::endl;  // Outputs 20

    return 0;
}
```

### 3. Pointer Arithmetic

You can perform arithmetic operations on pointers. This is especially useful when working with arrays.

```cpp
#include <iostream>

int main() {
    int arr[] = {10, 20, 30};
    int* p = arr; // Points to the first element of the array

    for (int i = 0; i < 3; i++) {
        std::cout << "Value at arr[" << i << "] = " << *(p + i) << std::endl;
    }

    return 0;
}
```

### 4. Pointers and Dynamic Memory

C++ provides the `new` and `delete` operators to manage dynamic memory.

```cpp
#include <iostream>

int main() {
    int* p = new int;   // Dynamically allocate memory for an integer
    *p = 30;            // Assign a value

    std::cout << "Dynamically allocated value: " << *p << std::endl;

    delete p;          // Free the allocated memory

    return 0;
}
```

### 5. Pointers to Functions

You can use pointers to point to functions, allowing for callback mechanisms.

```cpp
#include <iostream>

void display(int x) {
    std::cout << "Value: " << x << std::endl;
}

int main() {
    void (*funcPtr)(int) = &display; // Pointer to function display
    funcPtr(50); // Call display function using pointer

    return 0;
}
```

### Summary

- **Declaration**: Use `*` to declare a pointer.
- **Dereferencing**: Use `*` to access the value at the pointer's address.
- **Pointer Arithmetic**: You can perform arithmetic to navigate through arrays.
- **Dynamic Memory**: Use `new` to allocate and `delete` to free memory.
- **Function Pointers**: You can point to functions and call them indirectly.

Pointers are powerful but must be used carefully to avoid issues like memory leaks and dangling pointers.