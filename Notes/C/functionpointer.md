 # Function Pointer

 Function pointers are actually a powerful and useful feature  — especially when you want to **pass functions as arguments**, implement **callbacks**, or even create **dynamic behavior**.

Let’s break it down simply, like you're teaching it in a class.

---

## 🧠 What is a Function Pointer

A **function pointer** is a **variable that stores the address of a function**.

> 💡 Just like you can store the address of a variable using a pointer,  
> you can store the **address of a function** and call it later.

---

### 🔧 Syntax

Here’s the basic syntax:

```cpp
return_type (*pointer_name)(parameter_list);
```

Example:

```cpp
int add(int a, int b) {
    return a + b;
}

int (*funcPtr)(int, int); // function pointer declaration

funcPtr = add;            // assign function address to pointer

int result = funcPtr(5, 3);  // call the function using pointer
```

---

### 💬 In Simple Words:

- `int (*funcPtr)(int, int)` means:
  > “`funcPtr` is a pointer to a function that takes two `int`s and returns an `int`.”

---

### 🎯 Real-World Analogy (Classroom Friendly)

Imagine:

- You have **multiple tools** (functions), and
- A **remote control** (function pointer) that can switch and use any tool dynamically.

```cpp
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }

void apply(int x, int y, int (*operation)(int, int)) {
    cout << "Result: " << operation(x, y) << endl;
}

int main() {
    apply(10, 5, add);       // Result: 15
    apply(10, 5, subtract);  // Result: 5
}
```

🎉 Here, `apply` can **dynamically choose** which operation to perform using a function pointer.

---

### ✅ When to Use Function Pointers?

- **Callback mechanisms** (like in UI, events, etc.)
- **Strategy design pattern** (choose behavior at runtime)
- **Plugin systems**
- **Custom sorting (like `qsort()` in C)**

---

### ⚡ Bonus: Modern Alternative

In modern C++, you can also use:
- **`std::function`** (more flexible)
- **Lambda expressions** (more concise)

But knowing function pointers is still essential — especially for:
- Embedded systems
- Legacy code
- Performance-critical applications

---

 
 Awesome choice! 💡 Let's build a **Mini Calculator** using **Function Pointers in C++**. This project is perfect to demonstrate:

- How to **store function addresses**
- How to **pass them around**
- How to **execute functions dynamically** (based on user input)

---

## 🧮 Mini Project: Function Pointer Based Calculator

### 🎯 Features:
- Performs **Addition, Subtraction, Multiplication, Division**
- Uses a **function pointer array** to map operations
- Simple CLI-based user interface

---

### 📦 Code:

```cpp
#include <iostream>
using namespace std;

// ==== Basic Operations ====
int add(int a, int b)       { return a + b; }
int subtract(int a, int b)  { return a - b; }
int multiply(int a, int b)  { return a * b; }
int divide(int a, int b)    {
    if (b == 0) {
        cout << "Error: Division by zero!\n";
        return 0;
    }
    return a / b;
}

// ==== Display Menu ====
void showMenu() {
    cout << "\n=== Calculator Menu ===\n";
    cout << "0. Add\n";
    cout << "1. Subtract\n";
    cout << "2. Multiply\n";
    cout << "3. Divide\n";
    cout << "4. Exit\n";
    cout << "Choose an operation: ";
}

// ==== Main Program ====
int main() {
    // Array of function pointers
    int (*operations[4])(int, int) = { add, subtract, multiply, divide };

    int choice, a, b;

    do {
        showMenu();
        cin >> choice;

        if (choice >= 0 && choice < 4) {
            cout << "Enter two numbers: ";
            cin >> a >> b;

            // Call the chosen function dynamically
            int result = operations[choice](a, b);
            cout << "Result: " << result << endl;
        }
        else if (choice != 4) {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    cout << "Goodbye!\n";
    return 0;
}
```

---

### 📌 What Students Will Learn:

| Concept              | Where Used                              |
|----------------------|------------------------------------------|
| Function Declaration | `int add(int, int)` etc.                 |
| Function Pointer     | `int (*operations[4])(int, int)`         |
| Dynamic Execution    | `operations[choice](a, b)`               |
| Basic CLI Logic      | Menu, input handling                     |

---

### 🧠 Bonus Challenge for Students:
Ask them to:
- Add support for **modulus (`%`)**
- Add support for **float operations** using overloaded functions
- Use **`std::function`** or **lambdas** for a modern twist

---

