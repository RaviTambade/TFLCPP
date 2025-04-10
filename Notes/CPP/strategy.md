# **command handler** example in C++ that uses:

- ✅ Traditional **function pointers**
- ✅ Modern **`std::function`**
- ✅ Clean, flexible **lambdas**
- ✅ Bonus: **Member function pointers**

This small app will act like a **command-line tool** where users type commands, and the correct function is called.

---

### 🛠️ Step-by-Step: Command Handler App

#### 🎯 Objective:

- User enters commands like `"add"` or `"multiply"`.
- Program maps those strings to functions.
- Executes the correct function with parameters.

---

### ✅ Final Version: Using `std::function` + Lambdas + Member Functions

```cpp
#include <iostream>
#include <unordered_map>
#include <functional>
#include <string>

using namespace std;

class MathOps {
public:
    int add(int a, int b) { return a + b; }
    int multiply(int a, int b) { return a * b; }
};

int main() {
    MathOps math;

    // Map of commands to functions
    unordered_map<string, function<int(int, int)>> commandMap;

    // Add regular functions (can also use free functions here)
    commandMap["add"] = bind(&MathOps::add, &math, placeholders::_1, placeholders::_2);
    commandMap["multiply"] = bind(&MathOps::multiply, &math, placeholders::_1, placeholders::_2);

    // Add lambda directly
    commandMap["power"] = [](int a, int b) {
        int result = 1;
        for (int i = 0; i < b; ++i)
            result *= a;
        return result;
    };

    // User input simulation
    string command;
    int x, y;

    while (true) {
        cout << "\nEnter command (add, multiply, power) or 'exit': ";
        cin >> command;
        if (command == "exit") break;

        cout << "Enter two numbers: ";
        cin >> x >> y;

        if (commandMap.find(command) != commandMap.end()) {
            int result = commandMap[command](x, y);
            cout << "Result: " << result << endl;
        } else {
            cout << "Unknown command!" << endl;
        }
    }

    return 0;
}
```

### 🔍 Highlights:

- 🔗 `std::function<int(int, int)>` allows flexible callable storage.
- 🔁 `std::bind` is used to wrap **class member functions**.
- 🪄 Lambdas make inline logic easy (`power` is an inline function).
- 💬 Commands are string-based, dynamic, and easily extendable.

---

### 💡 Want to Extend This?

Here are some cool ideas:
- Add division or modulus with proper error checks.
- Handle commands with **1 argument** using function overloading.
- Add `help` command to list available operations.
- Use `std::variant` to support different signatures.
- Turn the whole thing into a class-based command router.
