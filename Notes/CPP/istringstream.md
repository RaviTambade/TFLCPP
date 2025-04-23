#  Using std::istringstream  class 

`std::istringstream` is a part of the C++ Standard Library, found in the `<sstream>` header. It's used to treat a `std::string` like an input stream (like `std::cin`), allowing you to extract data from it using the `>>` operator or other stream methods.

### ✅ Use Cases of `std::istringstream`

1. **Parsing strings** into individual components:
   - Especially useful for tokenizing strings (e.g., breaking a line into words or values).
2. **Converting string to numbers**:
   - Instead of `stoi()` or `stof()`, it can safely extract multiple values of different types.
3. **Reading structured data from strings**:
   - Like reading CSV or space-separated values from a line.

---

### 🔧 Example 1: Basic token extraction

```cpp
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string line = "25 John 5.75";
    std::istringstream iss(line);

    int age;
    std::string name;
    float gpa;

    iss >> age >> name >> gpa;

    std::cout << "Age: " << age << "\nName: " << name << "\nGPA: " << gpa << std::endl;
}
```

---

### 🔧 Example 2: Splitting words in a string

```cpp
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string sentence = "C++ is a powerful language";
    std::istringstream iss(sentence);
    std::string word;

    while (iss >> word) {
        std::cout << word << std::endl;
    }
}
```

---

### 🔧 Example 3: Safe number parsing

```cpp
#include <iostream>
#include <sstream>
#include <string>

bool parseInt(const std::string& str, int& number) {
    std::istringstream iss(str);
    return (iss >> number) && iss.eof();  // ensures full conversion
}

int main() {
    std::string input = "123";
    int num;
    if (parseInt(input, num)) {
        std::cout << "Parsed number: " << num << std::endl;
    } else {
        std::cout << "Invalid input!" << std::endl;
    }
}
```