# Resource Acquisition Is Initialization (RAII)

 In C++, **RAII** (Resource Acquisition Is Initialization) is a design principle that ties **resource management** to **object lifetime**. It helps avoid resource leaks and ensures proper cleanup.

### 📌 Basic Idea:
**Acquire the resource in the constructor, and release it in the destructor.**

### ✅ Resources can be:
- Memory
- File handles
- Database connections
- Mutex locks
- Network sockets, etc.

---

### 🔧 Example:
```cpp
#include <iostream>
#include <fstream>

void readFile() {
    std::ifstream file("data.txt"); // File is opened (resource acquired)
    if (!file) {
        std::cerr << "File open failed\n";
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << '\n';
    }
    // File is automatically closed when 'file' goes out of scope
} // <- RAII: Destructor of std::ifstream releases the file
```

---

### 💡 Benefits:
- **Automatic cleanup** (no need to manually `delete` or `close`)
- **Exception safety**: Cleanup happens even if exceptions are thrown
- Helps write **robust and leak-free code**

---

### 🧱 Custom RAII Example:

```cpp
class FileHandler {
    FILE* file;
public:
    FileHandler(const char* filename, const char* mode) {
        file = fopen(filename, mode); // Acquire
    }

    ~FileHandler() {
        if (file) fclose(file); // Release
    }

    FILE* get() const { return file; }
};
```

-