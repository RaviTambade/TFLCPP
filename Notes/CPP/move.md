## 🔄 What is Move Semantics?

Move semantics allows you to **"steal" resources** from one object to another **instead of copying** them.

### 🔧 Copying vs Moving:
- **Copy**: Duplicates resources (slow for big data).
- **Move**: Transfers ownership (fast, no duplication).


## ✨ Real-life Analogy:
Think of copying as **photocopying a document** and moving as **handing over the original**. With a move, you give it away, and the source becomes "empty" or invalid (but still safe).


## 🧪 Example:

```cpp
#include <iostream>
#include <vector>

void printSize(std::vector<int>& v) {
    std::cout << "Size: " << v.size() << '\n';
}

int main() {
    std::vector<int> a = {1, 2, 3, 4, 5};
    std::vector<int> b = std::move(a); // Move semantics

    printSize(b); // Size: 5
    printSize(a); // Size: 0 (a is now "moved-from")
}
```

Here, instead of copying all the elements of `a` into `b`, the **internal memory (like the dynamic array)** is transferred. It’s efficient.


## ⚙️ How It Works Internally

To support move semantics, a class must define:
```cpp
ClassName(ClassName&& other);            // Move constructor
ClassName& operator=(ClassName&& other); // Move assignment
```

## 🧱 Custom Example with Resource:

```cpp
class Buffer {
    int* data;
    size_t size;

public:
    Buffer(size_t sz) : size(sz) {
        data = new int[size];
        std::cout << "Resource acquired\n";
    }

    // Move constructor
    Buffer(Buffer&& other) noexcept
        : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
        std::cout << "Resource moved\n";
    }

    // Destructor
    ~Buffer() {
        delete[] data;
        std::cout << "Resource released\n";
    }
};
```


## ✅ Why Use Move Semantics?

- Avoid deep copies of large objects (e.g., vectors, strings, files)
- Better performance (especially in return values, containers)
- Safe and efficient resource handling


## 🧠 Bonus Tip: `std::move()`
You use `std::move()` to **cast an object to an rvalue**, signaling it can be moved.

```cpp
std::string a = "hello";
std::string b = std::move(a); // a is now empty
```
