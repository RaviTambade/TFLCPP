# Design principles

**Design principles** are a set of **guidelines or rules** that help designers (whether in software, architecture, graphic design, or any other field) create systems, products, or experiences that are **effective, efficient, and aesthetically pleasing**.

In simple terms:  
👉 They are like **"best practices"** that help you make good design decisions.

#### ✅ Common Software Design Principles:

1. **SOLID principles** (used in OOP):
   - **S** – Single Responsibility Principle  
   - **O** – Open/Closed Principle  
   - **L** – Liskov Substitution Principle  
   - **I** – Interface Segregation Principle  
   - **D** – Dependency Inversion Principle  

2. **DRY** – Don't Repeat Yourself  
   *Avoid writing the same code again and again.*

3. **KISS** – Keep It Simple, Stupid  
   *Simpler designs are usually better and easier to maintain.*

4. **YAGNI** – You Aren’t Gonna Need It  
   *Don't add functionality unless it's absolutely necessary.*

5. **Separation of Concerns**  
   *Each part of your system should focus on one thing only.*

---

### If you mean in a **general design** context (like visual or product design):

Some core design principles are:
- **Balance**
- **Contrast**
- **Emphasis**
- **Alignment**
- **Repetition**
- **Proximity**
- **White Space**

These help in making the design visually clear, attractive, and user-friendly.

### 🔹 1. **Single Responsibility Principle (SRP)**  
> *A class or function should have only one reason to change.*

**Example:**  
Imagine you have a `User` class that does:
- User data handling  
- Logging user activity  
- Sending emails

🔻 **Bad Design:**
```cpp
class User {
    void saveData();
    void logActivity();
    void sendWelcomeEmail();
};
```

✅ **Good Design:**
```cpp
class UserDataHandler { void saveData(); };
class Logger { void logActivity(); };
class EmailService { void sendWelcomeEmail(); };
```
Each class has one responsibility — this makes code easier to maintain and test.

---

### 🔹 2. **DRY (Don't Repeat Yourself)**  
> *Avoid duplicating code or logic.*

**Example:**  
🔻 **Bad Design:**
```c
int calculateTaxForEmployee1(int salary) {
    return salary * 0.1 + 500;
}

int calculateTaxForEmployee2(int salary) {
    return salary * 0.1 + 500;
}
```

✅ **Good Design:**
```c
int calculateTax(int salary) {
    return salary * 0.1 + 500;
}
```
Reuse instead of duplicating logic.

---

### 🔹 3. **KISS (Keep It Simple, Stupid)**  
> *Simplicity makes code easier to understand and maintain.*

🔻 **Overcomplicated Example:**
```cpp
int compute(int x, int y, bool flag) {
    if (flag) return x > y ? x : y;
    else return x < y ? x : y;
}
```

✅ **Simpler Version:**
```cpp
int max(int x, int y) {
    return x > y ? x : y;
}
```

---

### 🔹 4. **Open/Closed Principle**  
> *Software should be open for extension but closed for modification.*

**Example:**
Suppose you’re calculating area for shapes:

🔻 **Bad Design:**
```cpp
double calculateArea(string shapeType) {
    if (shapeType == "circle") { ... }
    else if (shapeType == "square") { ... }
}
```

✅ **Good Design:**
```cpp
class Shape {
    virtual double getArea() = 0;
};

class Circle : public Shape {
    double getArea() override { ... }
};

class Square : public Shape {
    double getArea() override { ... }
};
```

You can now add new shapes without modifying `calculateArea()`.

---

### 🔹 5. **YAGNI (You Aren’t Gonna Need It)**  
> *Don’t write code for features that aren’t needed yet.*

**Bad Practice:**
```cpp
void buildPaymentGateway() {
    // Adding crypto payment even though not required yet...
}
```

✅ Focus only on current requirements. If the feature is never used, it’s wasted effort.
 

 