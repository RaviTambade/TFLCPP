In C++, a **`vector`** is a part of the Standard Template Library (STL) and is one of the most commonly used **sequence containers**. It functions like a **dynamic array** that can **automatically resize** itself when elements are added or removed.

### Key Features of `vector`:
- **Dynamic resizing**: Unlike regular arrays, vectors grow or shrink as needed.
- **Contiguous memory**: Elements are stored in a contiguous block of memory (just like arrays).
- **Random access**: Fast access to elements using index (just like arrays).
- **Built-in functions**: Rich set of functions like `push_back`, `pop_back`, `insert`, `erase`, `size`, etc.
- **Type-safe**: `vector<int>`, `vector<string>`, etc. ensure type safety.

---

### Syntax:
```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers; // creates an empty vector of integers

    numbers.push_back(10);    // add elements to the end
    numbers.push_back(20);
    numbers.push_back(30);

    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";  // prints: 10 20 30
    }

    return 0;
}
```

---

### Common Member Functions:
| Function         | Description                                 |
|------------------|---------------------------------------------|
| `push_back(val)` | Adds `val` to the end of the vector         |
| `pop_back()`     | Removes the last element                    |
| `size()`         | Returns the number of elements              |
| `empty()`        | Returns true if vector is empty             |
| `clear()`        | Removes all elements                        |
| `at(index)`      | Accesses element at given index with bounds checking |
| `front()`        | First element                               |
| `back()`         | Last element                                |
| `insert()`       | Inserts elements                            |
| `erase()`        | Erases elements                             |

---

### Example with `for-each` loop:
```cpp
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<string> fruits = {"apple", "banana", "cherry"};

    for (const string &fruit : fruits) {
        cout << fruit << " ";
    }

    return 0;
}
```

Perfect! Let's compare a **regular array** and a **vector** in C++ side by side with a small example.

---

### 🔵 Using Regular Array (Fixed Size):
```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[3] = {10, 20, 30}; // fixed size array

    for (int i = 0; i < 3; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
```

#### Output:
```
10 20 30
```

✅ **Pros**: Simple and fast  
❌ **Cons**: Size is fixed. Can't grow or shrink dynamically.

---

### 🟢 Using Vector (Dynamic Size):
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }

    return 0;
}
```

#### Output:
```
10 20 30
```

✅ **Pros**: Dynamic size, rich set of functions, easy to use  
✅ Can `insert`, `erase`, `resize`, etc.  
✅ Works well with STL algorithms like `sort`, `find`, etc.

---
