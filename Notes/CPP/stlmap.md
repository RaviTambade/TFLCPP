# map
---

## 🗺️ What is `map` in C++ STL?

A `map` is an **associative container** that stores **key-value pairs**.  
It’s like a **dictionary**: each key maps to a specific value.

### 🔑 Key Properties:
- **Unique keys only**
- **Automatically sorted by keys** (ascending order by default)
- Implemented using a **Red-Black Tree** (balanced BST)

---

## ✅ Basic Syntax:
```cpp
#include <map>

map<key_type, value_type> map_name;
```

Example:
```cpp
map<string, int> age;
```

---

## 🚀 Example: Basic Usage
```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> age;

    age["Alice"] = 25;
    age["Bob"] = 30;
    age["Charlie"] = 22;

    for (auto p : age) {
        cout << p.first << " : " << p.second << endl;
    }

    return 0;
}
```

🟢 **Output:**
```
Alice : 25
Bob : 30
Charlie : 22
```

(Notice: Sorted by key)

---

## 🧰 Useful Functions in `map`

| Function              | Description                             |
|-----------------------|-----------------------------------------|
| `m[key] = value`      | Inserts or updates value for `key`      |
| `m.at(key)`           | Returns value of key (throws if not found) |
| `m.find(key)`         | Returns iterator to key if exists       |
| `m.erase(key)`        | Removes entry by key                    |
| `m.size()`            | Number of key-value pairs               |
| `m.empty()`           | Checks if map is empty                  |
| `m.clear()`           | Removes all elements                    |

---

## 🔍 Searching in a Map
```cpp
if (age.find("Alice") != age.end()) {
    cout << "Found Alice";
} else {
    cout << "Not found";
}
```

---

## 🌀 Iterating Over a Map
```cpp
for (auto it = age.begin(); it != age.end(); ++it) {
    cout << it->first << " = " << it->second << endl;
}
```

Or:
```cpp
for (auto [key, value] : age) {
    cout << key << " -> " << value << endl;
}
```

---

## 🔻 Want Descending Order by Key?

```cpp
map<string, int, greater<string>> age;
```

---

## 🆚 Difference between `map` and `unordered_map`

| Feature          | `map`                  | `unordered_map`           |
|------------------|------------------------|----------------------------|
| Order            | Sorted by key          | No order                  |
| Implementation   | Red-Black Tree         | Hash Table                |
| Time Complexity  | O(log n)               | Average O(1), Worst O(n)  |
| Supports Custom Key Sort | ✅ Yes         | ❌ No                     |

---

