 
# 🧪 **Lab: Object-Oriented Design with Inheritance & Polymorphism (C++)**

### **Domain: Human Resources (HR)**

### **Theme: “One Interface, Many Behaviors”**

## 🎯 **Lab Objective (Why this lab exists)**

In real software systems, **different roles perform different work**, yet they all belong to the same organization.

This lab helps you understand how **object-oriented programming models real-world roles** using:

* **Abstraction** (what every employee *must* do)
* **Inheritance** (how roles evolve)
* **Method overriding** (role-specific behavior)
* **Runtime polymorphism** (decisions at execution time, not compile time)

By the end of this lab, you will clearly understand:

> How **one base pointer** can represent **many concrete objects**
> and how **behavior is chosen at runtime**, not by the variable type.


## 🧩 **Problem Statement**

You are building a **simplified HR Payroll & Work Management system** for an organization.

The organization has different types of employees, but **all employees share common identity and salary structure**.

However:

* The **nature of work**
* The **way salary is calculated**
* The **responsibilities**

👉 differ based on the employee’s role.

Your task is to **design and implement this system using Object-Oriented Principles in C++**.

## 🏢 **Business Requirements**

### 1️⃣ Employee (Abstract Concept)

Every employee in the organization:

* Has basic personal and salary details
* Must perform some kind of work
* Must have a way to calculate their salary

But…

❌ An `Employee` itself **cannot exist independently**
✅ It is only a **conceptual role**

➡️ Therefore, `Employee` must be **abstract**


### 2️⃣ SalesEmployee (Specialized Role)

A **Sales Employee**:

* Is an employee
* Works on sales targets
* Earns incentives when targets are achieved

Business rules:

* Salary = Basic Pay + Allowances
* Incentive is added **only if sales target is met**
* Work behavior is different from a general employee

### 3️⃣ SalesManager (Leadership Role)

A **Sales Manager**:

* Is also a sales employee
* Manages a team
* Drives strategy and performance
* Receives an additional **bonus**

Business rules:

* Salary includes:

  * Base salary
  * Incentives (if applicable)
  * Managerial bonus
* Work responsibility is different from SalesEmployee

## 🧠 **Design Constraints (Important)**

To align with **industry-grade OOP design**, your solution must:

* Use **abstract base class** for `Employee`
* Use **virtual functions** for behavior that changes
* Use **method overriding** in derived classes
* Use **base class pointers** to store derived objects
* Demonstrate **runtime polymorphism**
* Include a **virtual destructor**

⚠️ Hardcoding logic in `main()` is **not allowed**

## 🧱 **Conceptual Class Hierarchy**

```
Employee (Abstract)
   |
SalesEmployee
   |
SalesManager
```

> This hierarchy mirrors how **roles grow**, not how code duplicates.

## ▶ **Execution Scenario (What should happen at runtime)**

1. Create different employee objects:

   * One SalesEmployee
   * One SalesManager

2. Store both objects using **Employee pointers**

3. Invoke:

   * `DoWork()`
   * `ComputePay()`

4. Observe:

   * Same function calls
   * Different behaviors
   * Different salary calculations

➡️ This difference must occur **without checking object type manually**



## ✅ **Expected Learning Outcomes**

After completing this lab, students should be able to:

- ✔ Explain **why abstract classes are needed**
- ✔ Justify **virtual destructors**
- ✔ Demonstrate **runtime polymorphism** confidently
- ✔ Map C# OOP concepts to **modern C++**
- ✔ Design role-based systems using inheritance
- ✔ Answer interview questions on polymorphism with clarity

## 🔍 **Real-World Mapping**

| Real World HR          | OOP Concept          |
| ---------------------- | -------------------- |
| Employee role          | Abstract base class  |
| Job responsibility     | Virtual method       |
| Role variation         | Method override      |
| Payroll logic          | Polymorphic behavior |
| Organization hierarchy | Inheritance          |


## 🌱 **Mentor Note (Transflower Style)**

> Many students think polymorphism is about syntax.
> It is not.
>
> Polymorphism is about **trusting the interface**
> and letting the **object decide its behavior**.
>
> If you understand *this lab*,
> you don’t just know C++ —
> **you understand software design.**
 

### *(HR Domain)*

## 🧠 C# → C++ Concept Mapping (Teach This First)

| C# Concept       | C++ Equivalent                    |
| ---------------- | --------------------------------- |
| `Object`         | `std::ostream`, RTTI (`typeid`)   |
| `abstract class` | Class with pure virtual functions |
| `virtual`        | `virtual`                         |
| `override`       | `override` (C++11+)               |
| `base()`         | Base-class constructor call       |
| `ToString()`     | `operator<<` overload             |
| Polymorphism     | Base pointer/reference            |

## 🏗 Inheritance Hierarchy

```
Employee (abstract)
   |
SalesEmployee
   |
SalesManager
```
## 📁 Suggested Folder Structure

```
HR/
├── Employee.h
├── SalesEmployee.h
├── SalesManager.h
└── main.cpp
```

## 🧩 Step 1: Abstract Base Class — `Employee`

### 📄 `Employee.h`

```cpp
#pragma once
#include <iostream>
#include <string>
#include <ctime>

class Employee {
protected:
    int id;
    std::string firstName;
    std::string lastName;
    std::string email;
    std::string phone;
    std::string location;
    std::tm birthDate{};
    double basicSalary;
    double hra;
    double da;

public:
    // Constructor (constructor chaining base equivalent)
    Employee(int id,
             std::string firstName,
             std::string lastName,
             std::string email,
             std::string phone,
             std::string location,
             std::tm birthDate,
             double basicSalary,
             double hra,
             double da)
        : id(id),
          firstName(firstName),
          lastName(lastName),
          email(email),
          phone(phone),
          location(location),
          birthDate(birthDate),
          basicSalary(basicSalary),
          hra(hra),
          da(da) {}

    // Abstract methods
    virtual void DoWork() = 0;

    // Virtual method
    virtual double ComputePay() const {
        return basicSalary + hra + da;
    }

    // Virtual destructor (CRITICAL)
    virtual ~Employee() = default;

    // ToString equivalent
    friend std::ostream& operator<<(std::ostream& os, const Employee& e) {
        os << "Employee [ID=" << e.id
           << ", Name=" << e.firstName << " " << e.lastName
           << ", Email=" << e.email
           << ", Location=" << e.location << "]";
        return os;
    }
};
```

📌 **Teaching Insight**

* `= 0` → abstract method
* `virtual ~Employee()` → mandatory for polymorphism
* `operator<<` replaces `ToString()`

## 🧩 Step 2: `SalesEmployee` (Inheritance + Override)

### 📄 `SalesEmployee.h`

```cpp
#pragma once
#include "Employee.h"

class SalesEmployee : public Employee {
protected:
    double incentive;
    double salesTarget;
    double salesAchieved;

public:
    SalesEmployee(int id,
                  std::string firstName,
                  std::string lastName,
                  std::string email,
                  std::string phone,
                  std::string location,
                  std::tm birthDate,
                  double basicSalary,
                  double hra,
                  double da,
                  double incentive,
                  double salesTarget,
                  double salesAchieved)
        : Employee(id, firstName, lastName, email, phone, location,
                   birthDate, basicSalary, hra, da),
          incentive(incentive),
          salesTarget(salesTarget),
          salesAchieved(salesAchieved) {}

    void DoWork() override {
        std::cout << "SalesEmployee selling products and achieving targets.\n";
    }

    double ComputePay() const override {
        double salary = Employee::ComputePay();
        if (salesAchieved >= salesTarget) {
            salary += incentive;
        }
        return salary;
    }
};
```

📌 **Key Learning**

* `Employee::ComputePay()` reuse
* Conditional incentive logic
* Clean override

## 🧩 Step 3: `SalesManager` (Multi-level Inheritance)

### 📄 `SalesManager.h`

```cpp
#pragma once
#include "SalesEmployee.h"

class SalesManager : public SalesEmployee {
    double bonus;

public:
    SalesManager(int id,
                 std::string firstName,
                 std::string lastName,
                 std::string email,
                 std::string phone,
                 std::string location,
                 std::tm birthDate,
                 double basicSalary,
                 double hra,
                 double da,
                 double incentive,
                 double salesTarget,
                 double salesAchieved,
                 double bonus)
        : SalesEmployee(id, firstName, lastName, email, phone, location,
                        birthDate, basicSalary, hra, da,
                        incentive, salesTarget, salesAchieved),
          bonus(bonus) {}

    void DoWork() override {
        std::cout << "SalesManager managing team and driving strategy.\n";
    }

    double ComputePay() const override {
        return SalesEmployee::ComputePay() + bonus;
    }
};
```

📌 **Design Insight**

> Managers don’t rewrite logic — they extend it.

## ▶ Step 4: Runtime Polymorphism Test

### 📄 `main.cpp`

```cpp
#include <iostream>
#include "SalesEmployee.h"
#include "SalesManager.h"

std::tm createDate(int year, int month, int day) {
    std::tm t{};
    t.tm_year = year - 1900;
    t.tm_mon = month - 1;
    t.tm_mday = day;
    return t;
}

int main() {

    Employee* emp1 = new SalesEmployee(
        1, "Amit", "Sharma", "amit@company.com",
        "9999999999", "Mumbai",
        createDate(1995, 5, 12),
        1000, 5000, 20000,
        100000, 120000
    );

    Employee* emp2 = new SalesManager(
        2, "Neha", "Patil", "neha@company.com",
        "8888888888", "Pune",
        createDate(1990, 3, 22),
        1500, 7000, 30000,
        200000, 250000, 10000
    );

    emp1->DoWork();
    emp2->DoWork();

    std::cout << *emp1 << "\nSalary: " << emp1->ComputePay() << "\n\n";
    std::cout << *emp2 << "\nSalary: " << emp2->ComputePay() << "\n";

    delete emp1;
    delete emp2;

    return 0;
}
```
## 🧠 What Students Observe (Same as C#)

✔ Same base pointer
✔ Different runtime behavior
✔ Method selection decided **at runtime**
✔ Clean inheritance hierarchy

📌 **This is runtime polymorphism**


## 🔍 Exam & Interview Mapping (C++)

| Concept              | Where                                |
| -------------------- | ------------------------------------ |
| Abstraction          | `Employee` (pure virtual)            |
| Inheritance          | `SalesEmployee : Employee`           |
| Polymorphism         | `Employee* emp = new SalesManager()` |
| Constructor chaining | Base constructor call                |
| Override             | `override` keyword                   |
| Object behavior      | `operator<<`                         |

## 🌱 Mentor Note (Transflower Style)

> Languages change.
> Syntax changes.
> **Object thinking does not.**
>
> If you understand this lab in C++,
> Java, C#, Python become *variations*, not obstacles.
