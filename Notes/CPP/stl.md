# STL (Standard Template Library) in C++

STL (Standard Template Library)  in C++ as a **Collection Framework** — similar to Java’s collection framework if you're familiar with that.

---

## 📚 **STL as a Collection Framework in C++**

### ✅ What is STL?

**STL (Standard Template Library)** is a powerful **collection of generic classes and functions** in C++ that help you work with **data structures (collections)** and **algorithms** efficiently.

---

## 🧰 Think of STL as C++'s **Collection Framework**, which includes:

### 1. **Containers**  
Hold collections of objects (like Java's List, Set, Map).

### 2. **Algorithms**  
Work on containers (like sort, search, reverse, etc.).

### 3. **Iterators**  
Point to elements in containers (like pointers, or Java's iterators).

---

## 🧺 STL Containers: Types

| Category         | Examples                          | Purpose                           |
|------------------|-----------------------------------|-----------------------------------|
| **Sequence**     | `vector`, `list`, `deque`         | Linear collection (like array)    |
| **Associative**  | `set`, `map`, `multiset`, `multimap` | Key-based sorted collections   |
| **Unordered**    | `unordered_set`, `unordered_map`  | Fast key-based (hash tables)      |
| **Adapters**     | `stack`, `queue`, `priority_queue`| Special-purpose wrappers          |

---

## ⚙️ STL Algorithms
STL provides built-in functions for:
- Sorting: `sort()`
- Searching: `find()`, `binary_search()`
- Modifying: `reverse()`, `count()`, `replace()`

These work seamlessly with containers using iterators.

---

## 🔁 Iterators
- Help access and traverse elements in containers.
- Work like smart pointers.
- Types: `begin()`, `end()`, `rbegin()`, `const_iterator`, etc.

---

## 💡 Why Use STL?

- ✅ Saves time — No need to write data structures from scratch.
- ✅ Type-safe — Uses templates.
- ✅ Reusable and fast — Optimized implementations.
- ✅ Industry standard — Widely used in competitive coding and real-world development.

---

## 🧠 Summary

STL in C++ =  
🔹 **Containers** (hold data)  
+ 🔹 **Algorithms** (process data)  
+ 🔹 **Iterators** (access data)  

➡️ Together, they make C++ as powerful as any modern language’s collection framework.

---

Want a small diagram, flowchart, or cheat sheet for STL concepts?


# ✅ What is STL?
STL (Standard Template Library) is a powerful set of C++ **template classes and functions** that provide **ready-to-use data structures** and **algorithms**.

---

### 📦 **Main Components of STL**:

1. **Containers** – Store data
2. **Algorithms** – Operate on data (like sort, search)
3. **Iterators** – Access elements inside containers

---

## 📁 1. **Containers**

### 👉 Types of Containers:

| Category        | Examples                              | Description                       |
|----------------|----------------------------------------|-----------------------------------|
| **Sequence**    | `vector`, `list`, `deque`             | Linear data structures            |
| **Associative** | `set`, `map`, `multiset`, `multimap`  | Store elements with keys          |
| **Unordered**   | `unordered_set`, `unordered_map`      | Fast access using hash tables     |
| **Adapter**     | `stack`, `queue`, `priority_queue`    | Built on top of other containers  |

---

### 🧱 **Most Common Containers**:

#### 🔹 `vector<T>` – Dynamic array  
- Fast random access  
- Grows automatically  
```cpp
vector<int> v = {10, 20};
v.push_back(30);
```

#### 🔹 `list<T>` – Doubly linked list  
- Fast insert/delete at any position  
```cpp
list<int> l = {1, 2, 3};
```

#### 🔹 `set<T>` – Sorted unique elements  
```cpp
set<int> s;
s.insert(5);
```

#### 🔹 `map<Key, Value>` – Key-value pairs, sorted by key  
```cpp
map<string, int> age;
age["John"] = 25;
```

#### 🔹 `stack<T>` – LIFO  
```cpp
stack<int> s;
s.push(10);
s.pop();
```

#### 🔹 `queue<T>` – FIFO  
```cpp
queue<int> q;
q.push(5);
q.pop();
```

---

## ⚙️ 2. **Algorithms**

STL includes many useful algorithms:

```cpp
#include <algorithm>
```

| Algorithm         | Example                    |
|------------------|----------------------------|
| `sort()`         | `sort(v.begin(), v.end());` |
| `reverse()`      | `reverse(v.begin(), v.end());` |
| `find()`         | `find(v.begin(), v.end(), x);` |
| `count()`        | `count(v.begin(), v.end(), x);` |
| `binary_search()`| `binary_search(v.begin(), v.end(), x);` |

---

## 🔁 3. **Iterators**

- Work like pointers to access container elements.
```cpp
vector<int>::iterator it;
for (it = v.begin(); it != v.end(); ++it) {
    cout << *it << " ";
}
```

You can also use range-based for loop:
```cpp
for (int x : v) {
    cout << x;
}
```

---

## 📝 Example Program
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {3, 1, 4, 2};

    sort(nums.begin(), nums.end());

    for (int x : nums) {
        cout << x << " ";
    }

    return 0;
}
```

