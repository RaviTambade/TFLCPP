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

---

Let me know if you want visual diagrams or animations to make it even more fun to learn!