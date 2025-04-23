# Reading person records from a **CSV file**, stores them in a vector, and displays them:

---

### 🔧 **Header Files and Namespace**
```cpp
#include <iostream>   // For console I/O
#include <fstream>    // For file input/output
#include <sstream>    // For parsing lines with istringstream
#include <string>     // For std::string
#include <vector>     // For std::vector

using namespace std;
``>
These headers give you access to:
- File operations (`ifstream`)
- String parsing (`istringstream`)
- Container (`vector`)
- String and console I/O

---

### 👤 **Class Definition: `Person`**
```cpp
class Person {
public:
    int age;
    std::string name;
    float gpa;

    Person(int a, const std::string& n, float g) : age(a), name(n), gpa(g) {}

    void display() const {
        std::cout << "Age: " << age << "\nName: " << name << "\nGPA: " << gpa << std::endl;
    }
};
```

This defines a class `Person` with:
- Three public data members: `age`, `name`, and `gpa`.
- A constructor that initializes these members.
- A `display()` function that prints the person's details.

---

### 🧾 **Main Function: Read CSV File**

```cpp
std::ifstream file("people.csv");
```
Opens a file named `people.csv` for reading.

```cpp
if (!file.is_open()) {
    std::cerr << "Failed to open file!" << std::endl;
    return 1;
}
```
Checks if the file was successfully opened. If not, prints an error and exits.

---

### 🗃️ **Reading and Parsing Data**

```cpp
std::vector<Person> people;
std::string line;
```
Declares:
- A vector to store `Person` objects.
- A string to hold each line from the file.

```cpp
while (std::getline(file, line)) {
    if (line.empty()) continue;
```
Reads the file line-by-line. Skips empty lines.

```cpp
    std::istringstream iss(line);
    int age;
    std::string name;
    float gpa;

    iss >> age >> name >> gpa;
```
- Wraps each line in a `std::istringstream` for parsing.
- Extracts `age`, `name`, and `gpa` from the line assuming space-separated format (e.g., `25 Nikita 88.5`).

```cpp
    people.emplace_back(age, name, gpa);
```
Creates a `Person` object **in-place** inside the `vector` using the parsed data (more efficient than `push_back()`).

---

### 📤 **Display All People**

```cpp
file.close(); // Close file

for (const auto& person : people) {
    person.display();
}
```
- Closes the file after reading.
- Loops through the vector and displays each `Person` using the `display()` method.

---

### 📌 Expected Input (File Content: `people.csv`)
```
45 Nikita 44.5
56 Ravi 44.5
98 Kajal 44.5
36 Sarthak 88.5
```

### ✅ Output
```
Age: 45
Name: Nikita
GPA: 44.5
Age: 56
Name: Ravi
GPA: 44.5
Age: 98
Name: Kajal
GPA: 44.5
Age: 36
Name: Sarthak
GPA: 88.5
```

---

### ✅ Summary
- **Reads a structured text file (CSV-style)**
- **Parses each line into meaningful objects**
- **Efficiently stores and processes data**

Let me know if you'd like to support comma-separated values (`45,Nikita,44.5`) instead of space-separated!

# emplace_back()` Vs `push_back()`   methods of vector<> in STL

---

### 🔧 `emplace_back()` vs `push_back()`

Both are methods used to add elements to the **end of a `std::vector`**. But there's a key difference in how they work:

---

### ✅ `push_back()`
```cpp
Person p(25, "Nikita", 88.5);
people.push_back(p);
```

- You **create an object first**, then pass it to `push_back`.
- It may involve **copying or moving** the object into the vector (depending on compiler optimizations and if move constructors are available).

---

### 🚀 `emplace_back()`
```cpp
people.emplace_back(25, "Nikita", 88.5);
```

- You **construct the object directly inside** the vector.
- No extra copy or move. It's more **efficient**, especially for complex objects.

---

### 🎯 When to Use `emplace_back()`

Use `emplace_back()` when:
- You want to avoid creating a temporary object.
- You're adding an object that can be built from constructor arguments.
- You want to write cleaner and faster code.

---

### 💡 Simple Analogy

Think of:
- `push_back()` as: **“Bring a fully built car and park it.”**
- `emplace_back()` as: **“Send the car parts and build it right in the garage.”**

---

### 🧪 Example

```cpp
std::vector<std::pair<int, std::string>> data;

// Using push_back
std::pair<int, std::string> p = {1, "hello"};
data.push_back(p);

// Using emplace_back
data.emplace_back(2, "world");
```

