 
## Lab: Printer Management System using OOP in C++

**Transflower Learning Framework (TLF)–style Lab Problem**, written exactly the way you usually position labs: **context → objectives → task → constraints → deliverables → evaluation**.


## 🧠 Learning Context (Why this lab?)

In real-world software systems, devices such as **printers** are modeled using **inheritance hierarchies** where common behavior is shared, and specialized behavior is overridden.

This lab helps learners understand how:

* A **base device abstraction** can be designed
* Different device types extend behavior
* **Polymorphism** enables flexible runtime behavior
* **Friend functions** can be used for controlled access to class internals

This lab mirrors how **drivers, device managers, and hardware abstraction layers** are implemented in system-level software.

## 🎯 Learning Objectives

By completing this lab, learners will be able to:

* Design a **base class and derived classes**
* Implement **virtual functions and method overriding**
* Apply **runtime polymorphism**
* Use **friend functions** to access protected members
* Model a **real-world system** using OOP principles

## 🧩 Problem Statement

Design and implement a **Printer Management System** in C++ using Object-Oriented Programming concepts.

The system should support different types of printers while sharing common behavior through a base class.


## 🏗️ System Design Requirements

### 1️⃣ Base Class: `Printer`

* Data Members:

  * `printerName` (protected)

* Member Functions:

  * Constructor to initialize printer name
  * `virtual void print()` to display generic printer information

* Friend Function:

  * `showPrinterDetails(Printer&)` to display printer name

### 2️⃣ Derived Class: `InkjetPrinter`

* Inherits from `Printer`

* Additional Data Member:

  * `inkLevel` (percentage)

* Member Functions:

  * Constructor to initialize printer name and ink level
  * Override `print()` to show inkjet-specific printing details

* Friend Function:

  * `showInkjetDetails(InkjetPrinter&)`


### 3️⃣ Derived Class: `LaserPrinter`

* Inherits from `Printer`

* Additional Data Member:

  * `tonerLevel` (percentage)

* Member Functions:

  * Constructor to initialize printer name and toner level
  * Override `print()` to show laser-printer-specific printing details

* Friend Function:

  * `showLaserDetails(LaserPrinter&)`



## ⚙️ Functional Requirements

* Polymorphic behavior must be demonstrated using overridden `print()` functions
* Friend functions must access protected members legally
* Base-class friend function must be reused inside derived-class friend functions
* Program must compile and run without warnings


## 🔧 Lab Tasks (Step-by-Step)

1. Create the `Printer` base class with a virtual `print()` method
2. Implement the `InkjetPrinter` class by extending `Printer`
3. Implement the `LaserPrinter` class by extending `Printer`
4. Declare and define friend functions for all classes
5. Create objects of each printer type in `main()`
6. Call `print()` functions to demonstrate polymorphism
7. Use friend functions to display detailed printer information


## 🧪 Sample Execution Flow

```
Printing from Inkjet Printer: HP Inkjet with ink level 75%
Printing from Laser Printer: Canon Laser with toner level 50%

Printer Name: HP Inkjet
Ink Level: 75%

Printer Name: Canon Laser
Toner Level: 50%
```


## 📦 Deliverables

* `printer_system.cpp`
* Well-structured code with meaningful comments
* Successful execution output
 

## 🧠 Concept Mapping (TLF Insight)

| Concept          | Mapping                    |
| ---------------- | -------------------------- |
| Base Class       | Device abstraction         |
| Derived Classes  | Specialized devices        |
| Virtual Function | Runtime behavior           |
| Friend Function  | Controlled internal access |
| Polymorphism     | Plug-and-play design       |

 

## 📊 Evaluation Criteria

| Criteria                    | Weight |
| --------------------------- | ------ |
| Correct class design        | 25%    |
| Proper use of inheritance   | 20%    |
| Polymorphism implementation | 20%    |
| Friend function usage       | 20%    |
| Code clarity & output       | 15%    |

 

## 🚀 Extension Tasks (Optional – Advanced)

* Add a `scan()` virtual function
* Introduce a `PrinterManager` class
* Store printers in a base-class pointer array
* Add resource validation (low ink / low toner warning)



```cpp

#include <iostream>
#include <string>
using namespace std;

// Base class Printer
class Printer {
protected:
    string printerName;

public:
    // Constructor
    Printer(string name) : printerName(name) {}

    // Virtual function to print the type of printer
    virtual void print() {
        cout << "Printing from Printer: " << printerName << endl;
    }

    // Friend function declaration
    friend void showPrinterDetails(Printer& printer);
};

// Derived class InkjetPrinter
class InkjetPrinter : public Printer {
protected:
    int inkLevel;

public:
    // Constructor
    InkjetPrinter(string name, int ink) : Printer(name), inkLevel(ink) {}

    // Override the print function
    void print() override {
        cout << "Printing from Inkjet Printer: " << printerName << " with ink level " << inkLevel << "%" << endl;
    }

    // Friend function declaration
    friend void showInkjetDetails(InkjetPrinter& inkjet);
};

// Derived class LaserPrinter
class LaserPrinter : public Printer {
protected:
    int tonerLevel;

public:
    // Constructor
    LaserPrinter(string name, int toner) : Printer(name), tonerLevel(toner) {}

    // Override the print function
    void print() override {
        cout << "Printing from Laser Printer: " << printerName << " with toner level " << tonerLevel << "%" << endl;
    }

    // Friend function declaration
    friend void showLaserDetails(LaserPrinter& laser);
};

// Friend function to display Printer details
void showPrinterDetails(Printer& printer) {
    cout << "Printer Name: " << printer.printerName << endl;
}

// Friend function to display Inkjet Printer details
void showInkjetDetails(InkjetPrinter& inkjet) {
    showPrinterDetails(inkjet);  // Calling the friend function of base class
    cout << "Ink Level: " << inkjet.inkLevel << "%" << endl;
}

// Friend function to display Laser Printer details
void showLaserDetails(LaserPrinter& laser) {
    showPrinterDetails(laser);  // Calling the friend function of base class
    cout << "Toner Level: " << laser.tonerLevel << "%" << endl;
}

int main() {
    // Create instances of printers
    InkjetPrinter inkjet("HP Inkjet", 75);
    LaserPrinter laser("Canon Laser", 50);

    // Demonstrate the print functions
    inkjet.print();
    laser.print();

    // Use friend functions to show printer details
    showInkjetDetails(inkjet);
    showLaserDetails(laser);

    return 0;
}


```
