Perfect! Since you're on **Windows** and have **g++ version 14** (likely via **MSYS2**, **MinGW-w64**, or manually installed), here's exactly how you can use `nlohmann/json` with it.

---

## ✅ Use `nlohmann/json` with `g++-14` on Windows

You can choose between:

- 🔸 **Option A: Manual (Simplest)**
- 🔹 **Option B: Using `vcpkg` with g++**

---

## 🔸 Option A: Manual Integration (Best for Quick Use)

### 🔹 Step 1: Download the Header

Go to the [official GitHub page](https://github.com/nlohmann/json/releases), and download the single header file:

📁 Download: [https://github.com/nlohmann/json/releases/latest/download/json.hpp](https://github.com/nlohmann/json/releases/latest/download/json.hpp)

Put this file next to your `.cpp` file.

### 🔹 Step 2: Example `main.cpp`

```cpp
#include <iostream>
#include "json.hpp"

using json = nlohmann::json;

int main() {
    std::string data = R"({"id": 101, "name": "Laptop", "price": 899.99})";
    json j = json::parse(data);

    int id = j["id"];
    std::string name = j["name"];
    double price = j["price"];

    std::cout << "ID: " << id << ", Name: " << name << ", Price: " << price << std::endl;
    return 0;
}
```

### 🔹 Step 3: Compile with g++-14

Assuming you're using MSYS2 or MinGW-w64:

```bash
g++-14 -std=c++17 main.cpp -o main.exe
./main.exe
```

---

## 🔹 Option B: Using `vcpkg` with `g++-14`

This is if you want package management.

### 🔹 Step 1: Clone and Setup vcpkg

```bash
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat
```

### 🔹 Step 2: Install `nlohmann-json`

```bash
.\vcpkg install nlohmann-json
```

### 🔹 Step 3: Compile using g++-14 with vcpkg include

```bash
g++-14 -std=c++17 -I .\vcpkg\installed\x64-windows\include main.cpp -o main.exe
```

✅ That's it! Run with:

```bash
./main.exe
```

---


Great question!

The `R` in:

```cpp
std::string data = R"({"id": 101, "name": "Laptop", "price": 899.99})";
```

is part of a **raw string literal** in C++.

---

## 🔍 What is a Raw String Literal?

A **raw string literal** allows you to include characters like:

- quotes (`"`)
- backslashes (`\`)
- newlines

**without escaping them**.

---

### 🔥 Without `R""` (Standard string):

```cpp
std::string data = "{\"id\": 101, \"name\": \"Laptop\", \"price\": 899.99}";
```

You must escape every double quote inside the string. 😓

---

### ✅ With `R""` (Raw string literal):

```cpp
std::string data = R"({"id": 101, "name": "Laptop", "price": 899.99})";
```

No escaping! Much cleaner and readable — especially helpful with JSON, regex, XML, HTML, etc.

---

### 🧠 Syntax Breakdown:

```cpp
R"delimiter(content)delimiter"
```

- `R` → Indicates a raw string.
- `()` → Encloses the string.
- You can add custom **delimiters** like `R"json(...your text...)json"` to avoid conflicts.

---

### 📝 Example with newlines:

```cpp
std::string html = R"(
<html>
  <body>Hello, World!</body>
</html>
)";
```

No escaping `\n`, `\"`, etc.

---

So, `R"(...)"` just makes your life easier when dealing with complex strings — like JSON in your case.



Awesome question! Let's break this down 👇

---

## 📄 Why is the external library file named `.hpp` instead of `.h`?

### 🔹 `.hpp` = C++ Header File  
It stands for **Header Plus Plus**. It’s just a convention that means:

> "This header is meant to be used in C++, not in plain C."

---

## 🔍 Difference Between `.h` and `.hpp`

| Feature                | `.h`                        | `.hpp`                         |
|------------------------|-----------------------------|--------------------------------|
| Language               | Mostly for C                | Specifically for C++          |
| Usage                  | Functions, structs          | Classes, templates, namespaces |
| Can use C++ features   | ❌ Not guaranteed            | ✅ Yes, like `namespace`, `template`, `class`, etc. |
| Convention             | C-style libraries           | C++-style libraries            |

---

## 🧠 Why does `nlohmann/json` use `.hpp`?

Because it's a **header-only, template-based C++ library**, which uses:

- `class`, `struct`, `template`
- `namespace nlohmann`
- operator overloading
- and more C++-only features

So `.hpp` makes it clear:  
🗣️ “Hey! This header is not C-compatible, it's meant for **C++** only.”

---

## ✅ How to Use `.hpp` Files?

Same as `.h`:

```cpp
#include "json.hpp"
```

> The compiler doesn’t care much about the extension — it’s mostly for **humans** and **code editors**.

---
