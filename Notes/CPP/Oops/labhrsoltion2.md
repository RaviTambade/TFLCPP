 

## Lab Problem : Interface Inheritance & Polymorphism in HR Domain (C++)

  

## 🧠 Learning Context (Why this lab?)

In real-world enterprise systems, **roles are not defined only by hierarchy**, but by **capabilities**.

An employee may:

* Conduct appraisals
* Approve leaves
* Take interviews
* Train teams
* Be eligible for bonuses

These responsibilities **cut across hierarchies**.

This lab introduces **interface-based design** in C++, helping learners understand how large systems avoid rigid inheritance trees and instead rely on **capability-driven contracts**.

This mirrors how:

* HR systems
* ERP platforms
* Enterprise frameworks
  model responsibilities in a **loosely coupled** manner.

## 🎯 Learning Objectives

By completing this lab, learners will be able to:

* Understand **interfaces in C++** using pure abstract classes
* Apply **multiple inheritance safely** using interfaces
* Model real-world roles using **capability-based design**
* Use **interface inheritance** to group related responsibilities
* Implement **runtime polymorphism** using interface pointers
* Clearly differentiate **“what an object is” vs “what it can do”**

## 🧩 Problem Statement

Design and implement a **Human Resource (HR) role management system** in C++ that models employee responsibilities using **interface inheritance**.

The system must support multiple HR capabilities such as appraisal, bonus eligibility, interviewing, training, and managerial approvals, while maintaining **clean separation between identity and behavior**.

## 🏗️ System Design Requirements

### 1️⃣ Base Entity: Employee

* Represents the **identity** of an employee
* May contain shared data (e.g., base bonus)
* Must support safe polymorphic deletion


### 2️⃣ Capability Interfaces (Pure Abstract Classes)

Define interfaces representing **HR capabilities**, such as:

* Appraisal responsibility
* Bonus eligibility
* Interview panel participation
* Training responsibility

Each interface must:

* Contain only pure virtual functions
* Have no data members
* Act as a **contract**, not an implementation

### 3️⃣ Interface Inheritance (Managerial Capabilities)

Some roles require **combined responsibilities**.

Design an interface that:

* Inherits from multiple capability interfaces
* Represents **manager-specific benefits**
* Adds additional managerial responsibilities

This models **capability aggregation**, not hierarchy.

### 4️⃣ Role Implementations

Implement HR roles such as:

* A role that supports **single responsibility**
* A managerial role that supports **multiple responsibilities**
* Roles must inherit:

  * From `Employee` for identity
  * From one or more interfaces for capabilities

## ⚙️ Technical Constraints

* Programming Language: **C++**
* Interface Representation: **Pure abstract classes**
* Polymorphism: Must use base-class pointers or references
* Multiple inheritance is allowed **only for interfaces**
* Virtual destructors are mandatory where polymorphism is used
* Console-based output is sufficient

## 🧪 Expected Behaviour

* Objects should be usable through different interface pointers
* Same object must respond differently based on interface type
* No ambiguity or duplication of data
* Code must demonstrate loose coupling and role-based behavior
* System must compile and execute safely

## 📦 Deliverables

1. Header files for:

   * Base employee
   * Capability interfaces
   * Interface inheritance
2. Concrete HR role implementations
3. Test program demonstrating interface polymorphism
4. Clear output validating role responsibilities
5. Proper folder structure and naming conventions

## 🧠 Concept Mapping (TLF Insight)

| Software Design Concept | HR Mapping                  |
| ----------------------- | --------------------------- |
| Abstract Class          | Employee identity           |
| Interface               | Capability / responsibility |
| Interface Inheritance   | Managerial benefits         |
| Multiple Inheritance    | Multiple capabilities       |
| Polymorphism            | Role-based behavior         |
| Loose Coupling          | Capability-driven design    |

## 📊 Evaluation Criteria

| Criteria                    | Weight |
| --------------------------- | ------ |
| Correct interface design    | 25%    |
| Interface inheritance usage | 20%    |
| Polymorphism demonstration  | 20%    |
| Safe multiple inheritance   | 15%    |
| Code structure & clarity    | 20%    |

## 🚀 Extension Tasks (Next TLF Level)

* Add more HR roles (HR Manager, Trainer, Recruiter)
* Introduce runtime role switching
* Convert capabilities into **service-based architecture**
* Map interfaces to **Java / C# equivalents**
* Compare interface-based design with deep inheritance trees

## 🧬 Mentor Insight (Transflower Signature)

> **Inheritance answers “what you are.”**
> **Interfaces answer “what you can do.”**

Strong systems are built on **capabilities**, not assumptions.

## Interface Inheritance in HR Domain

## 🧠 C++ Mapping Rule (Important for Students)

| C# Concept          | C++ Equivalent               |
| ------------------- | ---------------------------- |
| `interface`         | Pure abstract class          |
| Method without body | `= 0` (pure virtual)         |
| Multiple interfaces | Multiple inheritance         |
| Polymorphism        | Base-class pointer/reference |

## 📁 Folder Structure (Suggested)

```
HR/
├── Employee.h
├── SalesEmployee.h
├── SalesManager.h
├── Interfaces/
│   ├── IAppraisable.h
│   ├── IBonusEligible.h
│   ├── IInterviewPanel.h
│   ├── ITrainer.h
│   └── IManagerBenefits.h
└── main.cpp
```

## 🧩 Step 1: Base Employee (Assumed from Lab 4)

### 📄 `Employee.h`

```cpp
#pragma once
#include <string>

class Employee {
protected:
    float Bonus = 5000.0f;

public:
    virtual ~Employee() = default;
};
```

📌 `virtual destructor` is **mandatory** for polymorphism in C++.

---

## 🧩 Step 2: Define Interfaces (Pure Abstract Classes)

### 📄 `Interfaces/IAppraisable.h`

```cpp
#pragma once

class IAppraisable {
public:
    virtual void ConductAppraisal() = 0;
    virtual ~IAppraisable() = default;
};
```

### 📄 `Interfaces/IBonusEligible.h`

```cpp
#pragma once

class IBonusEligible {
public:
    virtual float CalculateBonus() = 0;
    virtual ~IBonusEligible() = default;
};
```

### 📄 `Interfaces/IInterviewPanel.h`

```cpp
#pragma once

class IInterviewPanel {
public:
    virtual void TakeInterview() = 0;
    virtual ~IInterviewPanel() = default;
};
```

### 📄 `Interfaces/ITrainer.h`

```cpp
#pragma once

class ITrainer {
public:
    virtual void Train() = 0;
    virtual ~ITrainer() = default;
};
```

## 🧩 Step 3: Interface Inheritance

### 📄 `Interfaces/IManagerBenefits.h`

```cpp
#pragma once
#include "IBonusEligible.h"
#include "IAppraisable.h"

class IManagerBenefits : public IBonusEligible, public IAppraisable {
public:
    virtual void ApproveLeave() = 0;
    virtual ~IManagerBenefits() = default;
};
```

📌 **Key Learning (Same as C#):**

* Interfaces can inherit other interfaces
* No implementation, only contracts

## 🧩 Step 4: Implement Interfaces in HR Classes

### ✅ `SalesEmployee`

📌 Implements **single interface**

### 📄 `SalesEmployee.h`

```cpp
#pragma once
#include <iostream>
#include "Employee.h"
#include "Interfaces/IAppraisable.h"

class SalesEmployee : public Employee, public IAppraisable {
public:
    void ConductAppraisal() override {
        std::cout << "Sales Employee appraisal completed." << std::endl;
    }
};
```

### ✅ `SalesManager`

📌 Implements **interface inheritance + multiple interfaces**

### 📄 `SalesManager.h`

```cpp
#pragma once
#include <iostream>
#include "SalesEmployee.h"
#include "Interfaces/IManagerBenefits.h"
#include "Interfaces/IInterviewPanel.h"
#include "Interfaces/ITrainer.h"

class SalesManager : public SalesEmployee,
                     public IManagerBenefits,
                     public IInterviewPanel,
                     public ITrainer {
public:
    float CalculateBonus() override {
        return Bonus;
    }

    void ConductAppraisal() override {
        std::cout << "Manager appraisal completed." << std::endl;
    }

    void ApproveLeave() override {
        std::cout << "Leave approved by Sales Manager." << std::endl;
    }

    void TakeInterview() override {
        std::cout << "Sales Manager conducting interview." << std::endl;
    }

    void Train() override {
        std::cout << "Sales Manager training sales team." << std::endl;
    }
};
```

📌 Multiple inheritance here is **safe** because:

* Interfaces have **no state**
* Only behavior contracts

## ▶ Step 5: Test Interface Polymorphism

### 📄 `main.cpp`

```cpp
#include <iostream>
#include "SalesManager.h"
#include "Interfaces/IAppraisable.h"
#include "Interfaces/IBonusEligible.h"
#include "Interfaces/IInterviewPanel.h"
#include "Interfaces/ITrainer.h"

int main() {

    SalesManager manager;

    IAppraisable* appraisable = &manager;
    appraisable->ConductAppraisal();

    IBonusEligible* bonusEligible = &manager;
    std::cout << "Bonus: " << bonusEligible->CalculateBonus() << std::endl;

    IInterviewPanel* panel = &manager;
    panel->TakeInterview();

    ITrainer* trainer = &manager;
    trainer->Train();

    return 0;
}
```

## 🧠 Key Observations (C++ Perspective)

| Concept              | Observation                    |
| -------------------- | ------------------------------ |
| Multiple inheritance | Allowed for interfaces         |
| Loose coupling       | Code depends on abstract types |
| Polymorphism         | Base pointer → derived object  |
| Safety               | Virtual destructor required    |
| Design clarity       | “Can-do” modeled cleanly       |

## 🔍 Abstract Class vs Interface (C++ Lens)

| Feature              | Abstract Class | Interface (Pure Abstract) |
| -------------------- | -------------- | ------------------------- |
| Data members         | ✅              | ❌                      |
| Constructors         | ✅              | ❌                      |
| Multiple inheritance | ⚠️ Risky       | ✅ Safe                  |
| Implementation       | Partial        | None                      |
| Purpose              | Identity       | Capability                |

## 🌱 Transflower Mentor Insight (C++)

> **Inheritance answers “what you are.”**
> **Interfaces answer “what you can do.”**
>
> C++ gives you both — discipline decides correctness.
