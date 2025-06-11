
## Exception Handling in C++**

🧑‍🏫 *“Imagine you are riding a bike on a mountain trail… you’re enjoying the view, pedaling smoothly — but suddenly, a rock appears on the path. What do you do?”*

> You could fall and get hurt — **or** — you could anticipate the risk and wear a helmet, gloves, and know how to hit the brakes safely.

In **C++ programming**, that *rock* is the **unexpected error** — and the **helmet and brakes** are your **exception handling** tools!

Let me take you into the world of **Exception Handling in C++**, where your application doesn’t crash when it hits a bump — it responds smartly.


### 🎯 **The Problem**

Say you have a program that divides two numbers:

```cpp
int divide(int a, int b) {
    return a / b;
}
```

What happens if `b` is 0?

🧨 Boom! The program crashes.

As responsible developers, we don't want our users to face unexpected crashes. Instead, we want to handle such cases **gracefully**. That’s where C++ gives us the trio of:

### 🔑 **Keywords of Exception Handling**

1. **`try`** — Here we write code that might cause problems.
2. **`throw`** — We raise or throw an exception when something goes wrong.
3. **`catch`** — This is where we handle the problem — like a safety net.

### 🛠️ **Example: Safe Division**

```cpp
#include <iostream>
using namespace std;

int divide(int a, int b) {
    if (b == 0)
        throw "Division by zero error!";
    return a / b;
}

int main() {
    try {
        int result = divide(10, 0); // risky!
        cout << "Result: " << result << endl;
    } catch (const char* msg) {
        cout << "Caught exception: " << msg << endl;
    }

    cout << "Program continues..." << endl;
    return 0;
}
```

### 🎬 **Behind the Scenes: What Happens?**

* `try` block checks for risky code.
* `throw` says — *“Hey, something’s wrong!”* and sends a message.
* `catch` grabs the message and deals with it — so the program doesn’t die!

### 📘 **Real Life Analogy**

Think of an **ATM** machine.

If the cash inside runs out, it doesn’t *explode* or *crash* — instead, it shows a message like *"Unable to dispense cash"*.

That's **exception handling in action** — in software **and** real life.


### 🚀 **Pro Tips for Students**

* Always validate user input and risky operations.
* Use **`throw`** with meaningful messages or error objects.
* **Never let exceptions propagate uncaught** — that’s like leaving a fire unattended.
* C++ also allows you to throw and catch custom **exception classes** (like `std::runtime_error`).


### 🧠 **Mini Practice Task**

Try writing a program where:

* You read an age from user input.
* If the age is negative, throw an exception.
* Catch and display a friendly message like: *“Age cannot be negative.”*


🎓 *“In real life, unexpected things happen. Great engineers design systems that don’t fail, but recover and inform. That’s what makes your code truly professional.”*

Let’s build software that’s not just functional — but **resilient**. 🌟


### 💪 What is **Robust Code**?

**Robust code** is code that:
- **Doesn’t crash** when something unexpected happens.
- **Handles errors** gracefully.
- **Continues running**, or exits cleanly with useful messages.
- Is **resilient** to edge cases, user input mistakes, hardware failures, or data corruption.

In short: **robust code = reliable, fault-tolerant, and safe to run in the real world**.



### 🔄 Why Use Exception Handling?

Without exception handling:
```cpp
ofstream file("data.txt");
file << "Hello"; // If file couldn't be opened? Program just keeps going (or crashes).
```

With exception handling:
```cpp
ofstream file;
file.exceptions(ofstream::failbit | ofstream::badbit);
try {
    file.open("data.txt");
    file << "Hello";
}
catch (const ofstream::failure& e) {
    cerr << "File error: " << e.what() << endl;
}
```

Now, even if something fails:
- You know what went wrong,
- You can inform the user,
- Or retry, log, or exit safely.

---

### 🧠 So in Summary:

| Concept | Purpose |
|--------|--------|
| **Robust Code** | Code that works reliably, even when something goes wrong. |
| **Exception Handling** | A feature in C++ that helps make your code robust by catching and handling runtime errors. |

### 🔧 Basic Structure:
```cpp
#include <iostream>
using namespace std;

int main() {
    try {
        // Code that might cause an exception
        int a = 10, b = 0;
        if (b == 0)
            throw runtime_error("Division by zero!");
        cout << "Result: " << a / b << endl;
    } 
    catch (const runtime_error& e) {
        // Code that handles the exception
        cout << "Caught an exception: " << e.what() << endl;
    }

    cout << "Program continues after exception handling." << endl;
    return 0;
}
```

### 💡 Key Points:
- **Any type** can be thrown (integers, strings, custom objects).
- You can catch exceptions by value, reference (recommended), or pointer.
- `std::exception` is the base class for most standard exceptions.

### 👷‍♂️ Custom Exceptions:
You can define your own exception classes by inheriting from `std::exception`:

```cpp
#include <iostream>
#include <exception>
using namespace std;

class MyException : public exception {
public:
    const char* what() const noexcept override {
        return "My custom exception!";
    }
};

int main() {
    try {
        throw MyException();
    }
    catch (const MyException& e) {
        cout << "Caught: " << e.what() << endl;
    }
}
```

### 🗂️ Real-World Scenario: Reading and Writing a Log File

You're building a C++ program that:
- Reads a list of messages from a file (`input.txt`)
- Appends each message to a `log.txt` file
- If any step fails (file missing, disk error, etc.), it handles the problem **gracefully**

---

### ✅ Robust Code with Exception Handling

```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void processLogs(const string& inputFileName, const string& logFileName) {
    ifstream inFile;
    ofstream outFile;

    // Enable exceptions
    inFile.exceptions(ifstream::failbit | ifstream::badbit);
    outFile.exceptions(ofstream::failbit | ofstream::badbit);

    try {
        // Open input file
        inFile.open(inputFileName);
        cout << "Reading from: " << inputFileName << endl;

        // Open log file in append mode
        outFile.open(logFileName, ios::app);
        cout << "Appending to: " << logFileName << endl;

        string line;
        while (getline(inFile, line)) {
            outFile << "LOG: " << line << endl;
        }

        inFile.close();
        outFile.close();

        cout << "Logs processed successfully." << endl;
    } 
    catch (const ifstream::failure& e) {
        cerr << "[ERROR] Reading input file failed: " << e.what() << endl;
    } 
    catch (const ofstream::failure& e) {
        cerr << "[ERROR] Writing to log file failed: " << e.what() << endl;
    }
    catch (...) {
        cerr << "[ERROR] An unknown error occurred." << endl;
    }
}
```

### 🧪 `main()` to Test:
```cpp
int main() {
    processLogs("input.txt", "log.txt");
    return 0;
}
```

---

### 🛡️ Why is This Code Robust?

- It doesn’t assume files always exist.
- If anything goes wrong:
  - It doesn’t crash.
  - It **tells the user what went wrong**.
- It **isolates risky operations** inside `try-catch`.
- It closes all files properly.

