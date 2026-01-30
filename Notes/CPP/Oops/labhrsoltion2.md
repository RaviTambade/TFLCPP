
# 🧪 Lab 5 (C++ Version)

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
