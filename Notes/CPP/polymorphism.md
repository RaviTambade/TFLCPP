# **Understanding Polymorphism in C++**

🧑‍🏫 \*“Imagine you’re teaching a class where one student plays guitar, one plays violin, and another plays tabla. You say ‘Perform!’ — and each one responds differently based on their skill.

That, my friends, is **Polymorphism** — one instruction, many forms!”\*

## 🎭 **What is Polymorphism?**

**Polymorphism** means *“many forms”*.
In C++, it allows us to use a single interface (like a function or method) to represent **different behaviors** depending on the data type or object it's acting upon.

## 🔍 Two Types of Polymorphism in C++

### ✅ **1. Compile-Time Polymorphism (Static Binding)**

📌 Achieved using:

* **Function Overloading**
* **Operator Overloading**

🔧 Behavior is determined **at compile time**.

#### 🛠️ Example – Function Overloading:

```cpp
class Printer {
public:
    void print(int i) {
        cout << "Printing int: " << i << endl;
    }
    void print(double d) {
        cout << "Printing double: " << d << endl;
    }
};
```

```cpp
Printer p;
p.print(10);     // Printing int
p.print(3.14);   // Printing double
```

👨‍🏫 *“The compiler picks the right `print()` version based on arguments — neat and quick!”*

### ✅ **2. Runtime Polymorphism (Dynamic Binding)**

📌 Achieved using:

* **Virtual Functions**
* **Function Overriding**
* **Base Class Pointers or References**

🔧 Behavior is determined **at runtime**.

#### 🛠️ Example – Virtual Function:

```cpp
class Animal {
public:
    virtual void sound() {
        cout << "Animal makes a sound\n";
    }
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Dog barks\n";
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "Cat meows\n";
    }
};
```

```cpp
Animal* a;
Dog d;
Cat c;

a = &d;
a->sound();  // Dog barks

a = &c;
a->sound();  // Cat meows
```

🎯 **Key point**: The function to be executed is chosen **at runtime** based on the actual object.

## ⚠️ Important Keywords

| Keyword    | Purpose                                  |
| ---------- | ---------------------------------------- |
| `virtual`  | Enables runtime polymorphism             |
| `override` | Ensures you're correctly overriding base |
| `final`    | Prevents further overriding              |

---

## 🎓 Mentor's Wisdom

> “Polymorphism is the soul of object-oriented design.
> It lets you write **flexible**, **extensible**, and **clean code**.

In real life, you say ‘drive’ — a car drives, a bus drives, a bike drives —
but each **drives differently**. That’s polymorphism in action!”

---

### 🔚 Wrap-Up:

* **Compile-time**: Same function name, different signatures.
* **Runtime**: Same function call, different object behavior.

💡 Mastering both gives you the power to design **truly object-oriented C++ applications**.


Shall we try building a small **Shape** example where `Circle`, `Square`, and `Triangle` all override `draw()`? 🎨


Polymorphism is one of the four pillars of Object-Oriented Programming (OOP), the others being **Encapsulation**, **Abstraction**, and **Inheritance**. It refers to the ability of a single function, method, or operator to operate on different types of objects or data. In simple terms, polymorphism allows objects of different types to be treated as objects of a common base type, especially when they share common behavior (like methods or functions).

#### Types of Polymorphism:
1. **Compile-time Polymorphism (Static Binding)**:
   - This is achieved using **function overloading** and **operator overloading**.
   - The compiler determines the method to be called at compile time based on the function signature or the operator used.
   
   Example:
   ```cpp
   class Printer {
   public:
       void print(int i) {
           std::cout << "Printing integer: " << i << std::endl;
       }
       void print(double d) {
           std::cout << "Printing double: " << d << std::endl;
       }
   };
   ```

2. **Run-time Polymorphism (Dynamic Binding)**:
   - This is achieved using **inheritance** and **virtual functions**.
   - The method that is executed is determined at runtime based on the actual object type, even if the object is referenced through a pointer or a reference to a base class.
   
   Example:
   ```cpp
   class Shape {
   public:
       virtual void draw() {
           std::cout << "Drawing a generic shape" << std::endl;
       }
   };

   class Circle : public Shape {
   public:
       void draw() override {
           std::cout << "Drawing a circle" << std::endl;
       }
   };

   class Rectangle : public Shape {
   public:
       void draw() override {
           std::cout << "Drawing a rectangle" << std::endl;
       }
   };

   int main() {
       Shape* shape1 = new Circle();
       Shape* shape2 = new Rectangle();
       shape1->draw();  // Outputs: Drawing a circle
       shape2->draw();  // Outputs: Drawing a rectangle
   }
   ```
   Here, even though both `shape1` and `shape2` are pointers to the base class `Shape`, the correct `draw()` method is called based on the actual object type (`Circle` or `Rectangle`).

### **Abstract Class** in C++

An **abstract class** is a class that cannot be instantiated (i.e., you cannot create objects of this class directly). It is used as a base class for other classes and defines the common interface for all derived classes. An abstract class typically includes **pure virtual functions**, which must be overridden by any derived class.

#### Key Features of Abstract Classes:
1. **Pure Virtual Functions**:
   - A function is made pure virtual by assigning `= 0` to its declaration. A pure virtual function has no implementation in the abstract class itself and must be implemented in any derived class.
   
   Example:
   ```cpp
   class Shape {
   public:
       virtual void draw() = 0;  // Pure virtual function
   };
   ```

2. **Cannot Instantiate**:
   - You cannot create an object of an abstract class directly. It serves only as a base class for other classes.
   
   Example:
   ```cpp
   // Shape is an abstract class
   Shape s;  // This will give a compile-time error
   ```

3. **Provides Common Interface**:
   - Abstract classes define a common interface for derived classes. Derived classes must provide their own implementation of the pure virtual functions.
   
4. **Can Have Non-Pure Virtual Functions**:
   - Abstract classes can also have non-pure virtual functions (i.e., functions with implementation). This allows derived classes to either override these functions or use the base class's implementation.
   
   Example:
   ```cpp
   class Shape {
   public:
       virtual void draw() = 0;  // Pure virtual function
       
       void display() {          // Non-pure virtual function
           std::cout << "Displaying shape" << std::endl;
       }
   };
   ```
### **Example of Polymorphism with Abstract Classes**

Let's combine the concepts of **polymorphism** and **abstract classes** in a simple example:

```cpp
#include <iostream>

// Abstract class Shape
class Shape {
public:
    virtual void draw() = 0;  // Pure virtual function
    virtual ~Shape() {}        // Virtual destructor for proper cleanup
};

// Derived class Circle
class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a Circle" << std::endl;
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a Rectangle" << std::endl;
    }
};

int main() {
    Shape* shape1 = new Circle();      // Polymorphism: Base class pointer, derived class object
    Shape* shape2 = new Rectangle();   // Polymorphism: Base class pointer, derived class object
    
    shape1->draw();  // Outputs: Drawing a Circle
    shape2->draw();  // Outputs: Drawing a Rectangle
    
    delete shape1;  // Clean up memory
    delete shape2;  // Clean up memory
    
    return 0;
}
```

### **Explanation of the Code**:
- **Abstract Class (`Shape`)**:
  - It defines a pure virtual function `draw()`, making `Shape` an abstract class.
  - You cannot create an instance of `Shape`, but you can create pointers to it (`Shape*`).
  
- **Derived Classes (`Circle` and `Rectangle`)**:
  - Both classes provide their own implementation of the `draw()` function.
  
- **Polymorphism**:
  - We use **runtime polymorphism** to call the correct `draw()` function based on the actual object type (`Circle` or `Rectangle`), even though we're using a pointer to the base class (`Shape*`).
  
- **Memory Management**:
  - Proper memory cleanup is done using `delete` to avoid memory leaks.


### **Key Points to Remember**:

- **Polymorphism** enables methods to act differently based on the object type, even when using pointers or references to base classes.
- **Abstract classes** provide a base structure that enforces derived classes to implement specific methods (pure virtual functions). They cannot be instantiated but can be used to define a common interface for different types of objects.
- **Runtime polymorphism** (or dynamic polymorphism) is achieved using virtual functions and inheritance, and it allows for more flexible and scalable code.



In C++, you can implement an abstract concept using a base class, `Account`, and create derived classes such as `SavingAccount` and `CurrentAccount`. The base class will have pure virtual functions (abstract methods) that are specific to accounts, such as deposit, withdraw, and display balance.

Here's an example of how you can design such an abstract class hierarchy:

### C++ Example with `Account`, `SavingAccount`, and `CurrentAccount`

```cpp
#include <iostream>
#include <string>

// Abstract base class Account
class Account {
protected:
    std::string accountHolder;
    double balance;

public:
    // Constructor to initialize account details
    Account(std::string holder, double initialBalance)
        : accountHolder(holder), balance(initialBalance) {}

    // Pure virtual function to deposit money
    virtual void deposit(double amount) = 0;

    // Pure virtual function to withdraw money
    virtual void withdraw(double amount) = 0;

    // Virtual function to display account details
    virtual void display() const {
        std::cout << "Account Holder: " << accountHolder << std::endl;
        std::cout << "Balance: $" << balance << std::endl;
    }

    // Virtual destructor
    virtual ~Account() {}
};

// Derived class SavingAccount
class SavingAccount : public Account {
private:
    double interestRate;

public:
    // Constructor to initialize SavingAccount details
    SavingAccount(std::string holder, double initialBalance, double rate)
        : Account(holder, initialBalance), interestRate(rate) {}

    // Implement deposit for SavingAccount
    void deposit(double amount) override {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited $" << amount << " into SavingAccount." << std::endl;
        } else {
            std::cout << "Deposit amount must be positive." << std::endl;
        }
    }

    // Implement withdraw for SavingAccount
    void withdraw(double amount) override {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrew $" << amount << " from SavingAccount." << std::endl;
        } else {
            std::cout << "Insufficient balance or invalid amount." << std::endl;
        }
    }

    // Display account details, including interest rate
    void display() const override {
        Account::display();
        std::cout << "Interest Rate: " << interestRate << "%" << std::endl;
    }
};

// Derived class CurrentAccount
class CurrentAccount : public Account {
private:
    double overdraftLimit;

public:
    // Constructor to initialize CurrentAccount details
    CurrentAccount(std::string holder, double initialBalance, double overdraft)
        : Account(holder, initialBalance), overdraftLimit(overdraft) {}

    // Implement deposit for CurrentAccount
    void deposit(double amount) override {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited $" << amount << " into CurrentAccount." << std::endl;
        } else {
            std::cout << "Deposit amount must be positive." << std::endl;
        }
    }

    // Implement withdraw for CurrentAccount
    void withdraw(double amount) override {
        if (amount > 0 && balance - amount >= -overdraftLimit) {
            balance -= amount;
            std::cout << "Withdrew $" << amount << " from CurrentAccount." << std::endl;
        } else {
            std::cout << "Insufficient balance or overdraft limit exceeded." << std::endl;
        }
    }

    // Display account details, including overdraft limit
    void display() const override {
        Account::display();
        std::cout << "Overdraft Limit: $" << overdraftLimit << std::endl;
    }
};

// Main function to demonstrate the functionality
int main() {
    // Create a SavingAccount object
    SavingAccount saveAcc("John Doe", 1000, 2.5);
    saveAcc.display();
    saveAcc.deposit(500);
    saveAcc.withdraw(200);
    saveAcc.display();

    std::cout << std::endl;

    // Create a CurrentAccount object
    CurrentAccount currAcc("Jane Doe", 1000, 500);
    currAcc.display();
    currAcc.deposit(200);
    currAcc.withdraw(1200);  // This should be allowed due to overdraft
    currAcc.display();

    return 0;
}
```

### Explanation:

1. **Abstract Base Class `Account`:**
   - **Pure Virtual Functions:** `deposit(double amount)` and `withdraw(double amount)` are declared as pure virtual functions, meaning that derived classes must implement them.
   - **Common Properties:** The `Account` class holds common properties like `accountHolder` and `balance`, which are shared across all derived account types.
   - **Virtual Destructor:** The destructor is marked as virtual, ensuring that derived class destructors are called properly when deleting an object through a pointer to the base class.

2. **Derived Class `SavingAccount`:**
   - Implements the `deposit()` and `withdraw()` methods specific to savings accounts.
   - Additionally, it includes an `interestRate` property to demonstrate specialization for savings accounts.

3. **Derived Class `CurrentAccount`:**
   - Implements the `deposit()` and `withdraw()` methods specific to current accounts.
   - The `CurrentAccount` has an `overdraftLimit` property, allowing the account to go into a negative balance up to a specified limit.

4. **Main Function:**
   - In the `main()` function, we create objects of both `SavingAccount` and `CurrentAccount`.
   - We demonstrate the deposit and withdrawal operations, along with displaying account information for both types of accounts.

### Sample Output:

```
Account Holder: John Doe
Balance: $1000
Interest Rate: 2.5%
Deposited $500 into SavingAccount.
Withdrew $200 from SavingAccount.
Account Holder: John Doe
Balance: $1300
Interest Rate: 2.5%

Account Holder: Jane Doe
Balance: $1000
Overdraft Limit: $500
Deposited $200 into CurrentAccount.
Withdrew $1200 from CurrentAccount.
Account Holder: Jane Doe
Balance: $0
Overdraft Limit: $500
```

### Key Concepts Demonstrated:
- **Abstract Class:** `Account` is an abstract class because it has pure virtual functions.
- **Polymorphism:** Methods like `deposit()`, `withdraw()`, and `display()` are overridden in the derived classes. You can use pointers or references to the base class (`Account`) to work with objects of different derived classes.
- **Encapsulation:** Each account type has its own behavior for deposit, withdrawal, and specific features (interest rate, overdraft limit).

This structure provides a clean, extensible way to represent various types of accounts while ensuring that the core functionality is shared across all derived classes.