# 🧪 Lab 4 (C++ Version)

Below is a **faithful C++ conversion of Lab 4**, preserving:

* abstraction
* constructor chaining
* virtual / override
* multi-level inheritance
* runtime polymorphism
* HR domain meaning


## Object-Oriented Programming with Inheritance & Polymorphism

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

---

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


