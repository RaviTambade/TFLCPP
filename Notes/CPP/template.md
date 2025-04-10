 
##  **What is a template in C++?**

A **template** lets you write **generic and reusable code**. Instead of writing the same function or class multiple times for different types (`int`, `double`, etc.), you write it **once**, and the compiler generates the needed versions automatically.

---

### 🛠️ **Types of templates:**

1. **Function Templates**  
   Write a single function to work with different data types.

   ```cpp
   template <typename T>
   T maxValue(T a, T b) {
       return (a > b) ? a : b;
   }
   ```

2. **Class Templates**  
   Create generic classes (e.g., containers like stacks, queues).

   ```cpp
   template <typename T>
   class Box {
   public:
       T value;
       Box(T v) : value(v) {}
       void show() { cout << "Value: " << value << endl; }
   };
   ```

---

### 🎯 **Why use templates?**

| Benefit | Description |
|--------|-------------|
| ✅ **Code Reuse** | Avoid repeating the same code for multiple types. |
| 🚀 **Type Flexibility** | Work with user-defined types and built-in types seamlessly. |
| 🔒 **Type Safety** | Errors are caught at compile-time, not runtime. |
| 📦 **STL Ready** | Templates power the **Standard Template Library (STL)** — `vector`, `map`, `stack`, etc., are all template-based. |

---

### 📦 Example in real life:

Let’s say you want a stack of integers, a stack of strings, and a stack of doubles. Instead of writing 3 classes, you can write **one class template** and use it like:

```cpp
Stack<int> intStack;
Stack<string> stringStack;
Stack<double> doubleStack;
```

---



Awesome! Let’s dive into **class templates** — a super useful tool in C++ for building **generic data structures** like stacks, queues, linked lists, etc.

---

### 📦 **What is a class template?**

A **class template** allows you to define a class where **data types are parameters**. You can then use this class with any type (like `int`, `double`, `string`, or even custom classes).

---

### ✅ Basic Syntax:

```cpp
template <typename T>
class MyClass {
public:
    T data;
    MyClass(T value) : data(value) {}

    void display() {
        cout << "Data: " << data << endl;
    }
};
```

### 🔍 Usage:

```cpp
int main() {
    MyClass<int> obj1(42);
    MyClass<string> obj2("Hello");

    obj1.display();  // Output: Data: 42
    obj2.display();  // Output: Data: Hello

    return 0;
}
```

---

### 💡 Real Example: A simple generic Stack

```cpp
#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    T arr[100];
    int top;

public:
    Stack() : top(-1) {}

    void push(T val) {
        if (top < 99) {
            arr[++top] = val;
        }
    }

    T pop() {
        if (top >= 0) {
            return arr[top--];
        }
        throw out_of_range("Stack Underflow");
    }

    bool isEmpty() {
        return top == -1;
    }
};
```

### 🔧 Using the `Stack`:

```cpp
int main() {
    Stack<int> s;
    s.push(10);
    s.push(20);
    cout << s.pop() << endl;  // Output: 20
    cout << s.pop() << endl;  // Output: 10

    Stack<string> strStack;
    strStack.push("Hi");
    strStack.push("World");
    cout << strStack.pop() << endl;  // Output: World
}
```

---

### 🧠 Why use class templates?
- Define a **single version** of a class that works with **any data type**.
- Great for building **generic containers** (like in STL).
- Saves time and makes code cleaner and reusable.

---

Want to go deeper with:
- **Multiple template parameters**?
- **Specializing templates** for custom behavior?
- **Template + inheritance**?

Let me know your vibe 😄