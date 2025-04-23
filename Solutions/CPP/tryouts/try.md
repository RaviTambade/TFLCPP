# walk through the code step-by-step and break it down:

---

### 🔧 **Headers and Namespace**

```cpp
#include <iostream>    // For input/output
#include <sstream>     // For string stream operations (parsing strings)
#include <string>      // For std::string
#include <vector>      // For std::vector (dynamic array)

using namespace std;
```

These are standard C++ headers. The `using namespace std;` line allows you to use standard library types (`string`, `cout`, etc.) without prefixing them with `std::`.

---

### 👤 **Class Definition: Person**

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

This defines a `Person` class with:
- Three public data members: `age`, `name`, and `gpa`.
- A constructor to initialize those values.
- A `display()` method to print the details of a person.

---

### 🧪 **Main Function Logic**

```cpp
int main() {
    std::string line = "45 Nikita 44.5,56 Ravi 44.5,98 Kajal 44.5,36 Sarthak 88.5";
    std::istringstream iss(line);
```

- `line` holds a string of data representing multiple people, each separated by a comma.
- `iss` is a string stream used to read this line like an input stream.

---

### 🔁 **Data Extraction Loop**

```cpp
vector<Person> people;
Person thePerson(0, "", 0.0f); // Dummy object for reuse
```

- `people` is a vector to store `Person` objects.
- `thePerson` is initialized with dummy/default values.

Now comes the main parsing logic:

```cpp
while (iss) {
    std::string temp;
    std::getline(iss, temp, ','); // Get substring up to the next comma

    if (temp.empty()) break;

    std::istringstream tempStream(temp); // Stream to parse age, name, and gpa
    tempStream >> thePerson.age >> thePerson.name >> thePerson.gpa;

    people.push_back(thePerson); // Add parsed person to the vector
}
```

- Splits the input line at each comma using `getline()`.
- Parses each part (like `"45 Nikita 44.5"`) using another string stream.
- Reads values into `thePerson`, and adds a copy to the `people` vector.

---

### 📤 **Displaying Data**

```cpp
for (const auto& person : people) {
    person.display(); // Print each person's details
}
```

Loops through all stored people and calls their `display()` method.

---

### ✅ **Output for Given Input**

Input:
```
"45 Nikita 44.5,56 Ravi 44.5,98 Kajal 44.5,36 Sarthak 88.5"
```

Output:
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

### 💡 Notes

- Reusing `thePerson` is okay because `push_back()` makes a copy each time.

