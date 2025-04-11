#Smart Pointer

A **smart pointer** is a **C++ object that behaves like a regular pointer**, but with **automatic memory management**.

### ✨ Think of it like this:
> A smart pointer is a "smart" wrapper around a raw pointer (`int*`, `Account*`, etc.) that automatically deletes the object it points to when it's no longer needed.

---

## 💥 Why do we need it?

Raw pointers require **manual memory management**:
```cpp
Account* acc = new Account();
// ...
delete acc; // You MUST remember this
```

If you forget to call `delete`, it causes a **memory leak**. If you call `delete` twice, you get **undefined behavior**.

---

## ✅ Smart Pointer Benefits

- **No manual delete needed** ✅
- **Safer and cleaner code** ✅
- **Avoids memory leaks & dangling pointers** ✅

---

## 🚀 Types of Smart Pointers in C++

| Smart Pointer | Ownership Type    | Auto Deletes? | Use Case                             |
|---------------|-------------------|---------------|---------------------------------------|
| `unique_ptr`  | Single ownership  | Yes           | One owner. Fast, efficient.           |
| `shared_ptr`  | Shared ownership  | Yes           | Many can share ownership.             |
| `weak_ptr`    | No ownership      | No            | Used with `shared_ptr` to avoid loops.|

---

## 📦 Real-World Analogy

Imagine a **unique_ptr** is like a **house key** that only one person can have. When they drop it (go out of scope), the house gets demolished (memory freed).

A **shared_ptr** is like **a digital access code** — many people can access the house, but the house is demolished only when the last person stops using it.

---

## 🔧 Simple Example
```cpp
std::unique_ptr<Account> acc = std::make_unique<Account>("Alice", 1000);
// No need to call delete, it's automatic!
```

In C++, a **smart pointer** is an object that manages the lifetime and ownership of a dynamically allocated resource (usually memory). It acts like a regular pointer but automatically handles memory deallocation, preventing common issues like memory leaks and dangling pointers.

### 🔧 Why use smart pointers?
- **Automatic memory management**
- **Exception safety** (no memory leaks if an exception is thrown)
- **Clear ownership semantics**

### 🌟 Common types of smart pointers in C++
1. **`std::unique_ptr`**
   - Exclusive ownership (only one `unique_ptr` can own a resource).
   - Automatically deletes the object when it goes out of scope.
   ```cpp
   #include <memory>

   std::unique_ptr<int> ptr = std::make_unique<int>(10);
   ```

2. **`std::shared_ptr`**
   - Shared ownership (multiple `shared_ptr`s can own the same object).
   - Deletes the object when the last `shared_ptr` goes out of scope.
   ```cpp
   #include <memory>

   std::shared_ptr<int> ptr1 = std::make_shared<int>(20);
   std::shared_ptr<int> ptr2 = ptr1;  // shared ownership
   ```

3. **`std::weak_ptr`**
   - Non-owning reference to a `shared_ptr` object.
   - Prevents **cyclic references** (especially in graphs or trees).
   ```cpp
   #include <memory>

   std::shared_ptr<int> shared = std::make_shared<int>(30);
   std::weak_ptr<int> weak = shared;  // does not increase reference count
   ```

### 📌 Summary
| Type         | Ownership     | Auto-delete | Use case                           |
|--------------|---------------|-------------|------------------------------------|
| `unique_ptr` | Single owner  | ✅           | Simple and fast, sole ownership    |
| `shared_ptr` | Shared owner  | ✅           | Shared ownership, ref counting     |
| `weak_ptr`   | Non-owning    | ❌           | Avoiding cycles with `shared_ptr` |

Let me know if you want a demo example or want to see how they behave under the hood!



#include <iostream>
#include <memory>  // For smart pointers

class Account {
public:
    Account(const std::string& name, double balance)
        : name(name), balance(balance) {
        std::cout << "Account created for " << name << "\n";
    }

    ~Account() {
        std::cout << "Account destroyed for " << name << "\n";
    }

    void display() const {
        std::cout << "Account: " << name << ", Balance: $" << balance << "\n";
    }

private:
    std::string name;
    double balance;
};

int main() {
    std::unique_ptr<Account> accPtr = std::make_unique<Account>("Alice", 1000.0);
    accPtr->display();

    // No need to manually delete - happens automatically when accPtr goes out of scope
    return 0;
}


What happens here:
std::make_unique<Account> creates a new Account object.

When main() ends, accPtr goes out of scope, and the Account is automatically destroyed.

This avoids memory leaks compared to raw pointers.

