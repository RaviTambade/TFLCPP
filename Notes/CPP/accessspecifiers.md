# 🔐 Access Specifiers in C++

C++ has **three main access specifiers** that control visibility of class members:

| Specifier | Access Level | Usage |
|-----------|--------------|-------|
| `public`  | 🔓 Accessible from anywhere |
| `private` | 🔒 Only accessible inside the class |
| `protected` | 🛡️ Like `private`, but also accessible in derived (child) classes |

---

### 🚦Access Specifier Example:

```cpp
class Student {
private:
    int rollNo;  // Not accessible outside

protected:
    string grade; // Accessible in child class

public:
    string name;  // Accessible anywhere

    void setRollNo(int r) {
        rollNo = r;
    }

    void showInfo() {
        cout << "Name: " << name << ", Roll No: " << rollNo << endl;
    }
};
```

---

### 👶 Default Access Specifier:
- In a **class**, members are **private** by default.
- In a **struct**, members are **public** by default.

```cpp
class MyClass {
    int x; // private by default
};

struct MyStruct {
    int x; // public by default
};
```

---

### 🧠 Why Use Access Specifiers?

- **Encapsulation**: Hides internal details, protects data.
- Only allow controlled access via `getters` and `setters`.
- Prevent misuse or bugs from direct access.

---
 