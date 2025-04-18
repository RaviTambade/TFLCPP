# set  in C++ STL
set is  a super useful container when you want to store **unique** elements in **sorted order**.

---

## 🌿 What is a `set` in C++ STL?

A `set` is an **ordered container** in STL that:
- Stores **unique elements only** (no duplicates)
- Keeps elements in **sorted** order (by default in ascending)
- Is implemented as a **self-balancing binary search tree (Red-Black Tree)**

---

## ✅ Basic Syntax:
```cpp
#include <set>

set<int> s;
```

---

## 🚀 Example: Basic Usage
```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;

    s.insert(10);
    s.insert(5);
    s.insert(20);
    s.insert(10); // duplicate, won't be added

    for (int x : s) {
        cout << x << " ";
    }

    return 0;
}
```

🟢 **Output:**
```
5 10 20
```

---

## 🧰 Useful Functions in `set`

| Function              | Description                              |
|-----------------------|------------------------------------------|
| `insert(x)`           | Inserts `x` if not already present       |
| `erase(x)`            | Removes `x` if present                   |
| `find(x)`             | Returns iterator to `x` if found         |
| `count(x)`            | Returns 1 if `x` is in the set, else 0   |
| `size()`              | Number of elements                       |
| `empty()`             | Returns true if set is empty             |
| `clear()`             | Removes all elements                     |
| `begin(), end()`      | Iterators to loop over set               |

---

## 🔍 Searching in `set`
```cpp
if (s.find(10) != s.end()) {
    cout << "Found";
} else {
    cout << "Not found";
}
```

---

## 🔁 Iterating Over a Set
```cpp
for (auto it = s.begin(); it != s.end(); ++it) {
    cout << *it << " ";
}
```

---

## 🔻 Want Descending Order?

Use `greater<T>`:
```cpp
set<int, greater<int>> s;
```

---

## ✨ Summary

| Feature        | Value                      |
|----------------|----------------------------|
| Duplicates     | ❌ Not allowed              |
| Order          | ✅ Sorted (ascending by default) |
| Time Complexity| 🔁 O(log n) for insert/find/erase |

---
