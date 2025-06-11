👨‍🏫 **Understanding Templates in C++**


🧑‍🏫 *"One day in class, I asked, 'How many of you have copy-pasted the same logic for `int`, `float`, and `double` just by changing the data type?'*

😅 Most students smiled sheepishly.
*'Well… what if I told you C++ has a way to write that logic only **once**, and it’ll still work for all types? That’s the power of **templates**!'*


## 🧰 What is a Template in C++?

A **template** is a blueprint — a way to write **generic and type-independent code**.

With templates, you can create a single function or class to work with **any data type**, and the compiler will generate the exact version based on how it’s used.


## 🧠 Think of it like this:

> You design **one mold** for a key,
> but it can be used to create keys for a **car, bike, or door** —
> just by supplying different materials (types)!


## ✨ Function Template Example

```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}
```

```cpp
cout << add(3, 4);       // Outputs: 7 (int)
cout << add(2.5, 3.7);   // Outputs: 6.2 (double)
```

👨‍🏫 *"You wrote the logic once, and it worked for both `int` and `double`. The compiler does the rest!"*


## 🏗️ Class Template Example

```cpp
template <typename T>
class Box {
    T value;
public:
    Box(T v) : value(v) {}
    void show() {
        cout << "Value: " << value << endl;
    }
};
```

```cpp
Box<int> b1(10);
b1.show();  // Value: 10

Box<string> b2("Hello");
b2.show();  // Value: Hello
```

## 💡 Why Use Templates?

✅ **Reusability**
✅ **Type safety**
✅ **Cleaner code**
✅ **Performance** (no runtime overhead)


## ⚠️ Common Mistakes to Avoid

🚫 Forgetting to use `template<typename T>` syntax
🚫 Assuming `T` supports all operations (not all types support `+`, `-`, etc.)
🚫 Compiling template code without using it (templates are only compiled when instantiated)

## 🧭 Mentor Wisdom

> “Templates are like magic spells. You write one incantation — and it transforms itself to suit the need, whether you summon `int`, `float`, or even custom types.” ✨

So next time you're writing similar logic for multiple types, stop and ask:

> *Can I make this a template?*
> If yes, you’ve just leveled up in C++! 🎮💻🔥

Let’s go write a `swap()` template function next, shall we?


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

### 🎯 **Why use templates?**

| Benefit | Description |
|--------|-------------|
| ✅ **Code Reuse** | Avoid repeating the same code for multiple types. |
| 🚀 **Type Flexibility** | Work with user-defined types and built-in types seamlessly. |
| 🔒 **Type Safety** | Errors are caught at compile-time, not runtime. |
| 📦 **STL Ready** | Templates power the **Standard Template Library (STL)** — `vector`, `map`, `stack`, etc., are all template-based. |

### 📦 Example in real life:

Let’s say you want a stack of integers, a stack of strings, and a stack of doubles. Instead of writing 3 classes, you can write **one class template** and use it like:

```cpp
Stack<int> intStack;
Stack<string> stringStack;
Stack<double> doubleStack;
```


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