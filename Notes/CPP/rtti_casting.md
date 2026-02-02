## 🧑‍🏫   Polymorphism, RTTI, and Casting

“Okay students, today we are diving into **polymorphism, runtime type information (RTTI), and method overriding**. Now listen carefully, because this is the magic that allows objects in a hierarchy to behave differently depending on their type.
 

### 1️⃣ Polymorphism and Method Overriding

Imagine a company:

* `Employee` is your base class.
* `SalesEmployee` and `SalesManager` are derived classes.

All of them have a function called `doWork()`.

* For `SalesEmployee`, `doWork()` might mean **visiting customers and closing sales**.
* For `SalesManager`, `doWork()` might mean **tracking sales targets and guiding the team**.

Here’s the beauty: the **function name is the same**, but the **behavior depends on the actual object type**.

This is **runtime polymorphism**—the program figures out which function to call **when the program is running**, not when it's compiled.

```
Employee* e1 = new SalesEmployee();
Employee* e2 = new SalesManager();

e1->doWork();  // calls SalesEmployee version
e2->doWork();  // calls SalesManager version
```

Notice that **both objects are referenced as `Employee*`**, but the actual function executed is based on the runtime type.
 

### 2️⃣ RTTI – Run-Time Type Information

Now, sometimes you want to **check the type of an object at runtime**.

C++ gives you **RTTI** for this. Tools like:

* `dynamic_cast` → safely cast to derived types.
* `typeid` → find the actual type of an object.
* `reinterpret_cast` → low-level casting (use with caution).
* `static_cast` → compile-time safe cast.

Under the hood, RTTI works by storing a **type identifier in the object’s memory** (like a hidden tag in the vtable for polymorphic classes).
 

### 3️⃣ Method Overloading vs. Method Overriding

* **Overloading:** same function name, **different parameters** in the same class.

```
void calculate(int a);
void calculate(int a, int b);
```

* **Overriding:** same function name and parameters, but in **derived class**, changes behavior.

```
class Employee { virtual void doWork(); };
class SalesManager : public Employee { void doWork() override; };
```

Remember: overriding is **runtime polymorphism**, overloading is **compile-time polymorphism**.


### 4️⃣ Function Pointers and Delegates

Now, let’s talk about **function pointers**.

* A function pointer stores the **address of a function**.
* You can **call a function indirectly**, like this:

```
void greet() { printf("Hello!"); }
void (*fp)() = &greet;
fp(); // calls greet()
```

In C# or Java, you don’t see pointers directly. Instead, we use **delegates, events, or listeners**:

* **C#** → `Action` delegate.
* **Java** → `ActionListener` or callbacks.
* **Node.js** → function passed as a callback to `http.createServer()`.

This is how **callbacks work in event-driven programming**—the function is executed indirectly based on events.


### 5️⃣ Why This Matters

1. You can **write generic code** for a hierarchy of objects.
2. You can **decide behavior at runtime**, not compile-time.
3. It’s the **foundation of frameworks** like **MVC, delegates, and event-driven systems**.
4. Strong understanding of **pointers and memory** lets you optimize and debug effectively.

 
### 🔑 Mentor Tip:

> “Every object carries its identity. Polymorphism and RTTI help you **respect that identity at runtime**. Overloading and overriding are just tools to let objects behave differently depending on **who they are** and **how they are used**.”

 

### Employee Hierarchy with Polymorphism & RTTI

```
                 +----------------+
                 |   Employee     |  <-- Base class
                 |----------------|
                 | + doWork()     |  <-- virtual function
                 +----------------+
                          |
          ---------------------------------
          |                               |
+----------------+               +----------------+
| SalesEmployee  |               | SalesManager   |  <-- Derived classes
|----------------|               |----------------|
| + doWork()     |               | + doWork()     |  <-- overridden
+----------------+               +----------------+
          |                               |
          v                               v
   [VTable Pointer]                  [VTable Pointer]
          |                               |
          v                               v
    +-------------+                   +-------------+
    | VTable      |                   | VTable      |
    |-------------|                   |-------------|
    | doWork() -> SalesEmployee::doWork() | doWork() -> SalesManager::doWork() |
    +-------------+                   +-------------+

```
 

1. **Employee pointer points to object:**

   ```cpp
   Employee* e1 = new SalesEmployee();
   Employee* e2 = new SalesManager();
   ```

2. **At runtime:**

   * The pointer `e1` knows **it points to SalesEmployee**, because the object has a **VTable pointer**.
   * When you call `e1->doWork()`, the runtime **looks into the VTable**, finds the actual function **SalesEmployee::doWork()**, and executes it.
   * Similarly for `e2`.

3. **RTTI (Run-Time Type Information):**

   * `typeid(*e1)` → knows it’s `SalesEmployee`.
   * `dynamic_cast<SalesManager*>(e1)` → returns `nullptr`, because `e1` is not a `SalesManager`.

4. **Function pointers conceptually:**

   * VTable entries are **function pointers** pointing to the actual implementation.
   * This is how **runtime polymorphism** happens: call resolved at runtime, not compile-time.



### Optional Extension (if we include multiple layers)

```
Employee
   |
   +-- SalesEmployee
   |       |
   |       +-- InternSalesEmployee
   |
   +-- SalesManager
           |
           +-- RegionalManager
```

Each layer overrides `doWork()` → each object’s VTable points to its **own function implementation**.

  

**Imagine we are in a company:**

* You have a base class called **`Employee`**.
* Every employee can **doWork()**, but how they do work depends on the **specific type of employee** (SalesEmployee, SalesManager).
* This is the **is-a relationship**:

```text
SalesEmployee is an Employee
SalesManager is an Employee
```

* So, you can have a variable of type `Employee*` that **points to any derived object**:

```cpp
Employee* e1 = new SalesEmployee();
Employee* e2 = new SalesManager();
```

* When you call `e1->doWork()`, the **runtime decides** which function to execute.

 

### Why Polymorphism Works

1. **Abstract class:** Employee has a **pure virtual function `doWork()`**.
2. **Derived classes:** Override this function with **concrete implementations**.
3. **VPTR (Virtual Pointer):** Every object has a hidden pointer to its **VTable**.
4. **VTable:** A table of **function pointers** to the virtual functions of the class.

* This is the mechanism that enables **runtime polymorphism**: the object knows which function to call **at runtime**.
* **RTTI (Run-Time Type Information)** allows you to query the **actual type** of the object at runtime, e.g., `typeid(*e1)`.

 

### ASCII Diagram: Employee Hierarchy + VTable + VPTR

```
          Abstract Base Class
                 Employee
          +------------------+
          | +doWork() = 0    |  <-- pure virtual
          +------------------+
                   ^
                   |
        -------------------------
        |                       |
  SalesEmployee             SalesManager
  +----------------+       +----------------+
  | +doWork()      |       | +doWork()      |
  +----------------+       +----------------+
          |                       |
          v                       v
       [VPTR]                   [VPTR]
          |                       |
          v                       v
       +----------------+     +----------------+
       |   VTable       |     |   VTable       |
       |----------------|     |----------------|
       | doWork() --->  |     | doWork() --->  |
       | SalesEmployee::|     | SalesManager::|
       +----------------+     +----------------+
```


* **Employee pointer points to object** → calls go through **VPTR → VTable → function pointer**.
* **Polymorphism** is the "magic" that lets us **write generic code for Employees**, but the **correct behavior executes automatically**.
* **Function pointers in VTable:** The reason the **runtime can call the correct overridden method**.
* **RTTI:** Lets you check the **exact type** of object at runtime and safely cast using `dynamic_cast`.


### Analogy

* **VPTR:** GPS of your object → points to the **map of available functions**.
* **VTable:** Map of functions → tells the object **which function belongs to it**.
* **Polymorphism:** Your employee may be a manager or a sales employee, but **you don’t need to know**; calling `doWork()` automatically does the right thing.
* **RTTI:** Detective → “Who exactly are you at runtime?”
