In C++, **static members** refer to class members (variables and functions) that are shared by all instances (objects) of the class, rather than having a separate copy for each instance. Static members belong to the class itself, not to any specific object of the class. This can be useful when you need a member that should be shared across all instances, such as a counter tracking the number of objects created.

### Types of Static Members

1. **Static Member Variables**
2. **Static Member Functions**

### 1. **Static Member Variables**
A static member variable is declared using the `static` keyword inside a class. It is shared by all objects of the class, meaning that there is only one copy of the static variable, no matter how many instances of the class are created. 

- **Syntax**:
   ```cpp
   class ClassName {
   public:
       static int staticVariable;
   };
   ```

- **Initialization**:
   Static variables are not initialized in the class definition. They need to be defined outside the class, typically in a `.cpp` file.

   ```cpp
   // Outside the class definition
   int ClassName::staticVariable = 0;  // Initialize static variable
   ```

- **Accessing Static Variables**:
   You can access a static member variable using the class name or an object of the class.

   ```cpp
   ClassName::staticVariable = 10;  // Accessing via class name
   obj.staticVariable = 20;         // Accessing via object (not recommended)
   ```

- **Example**:
   ```cpp
   class Counter {
   public:
       static int count;  // Static member variable

       Counter() {
           count++;  // Increment the static count every time an object is created
       }

       static int getCount() {
           return count;  // Static member function can access static variable
       }
   };

   int Counter::count = 0;  // Initialize the static variable

   int main() {
       Counter c1, c2, c3;
       std::cout << "Object count: " << Counter::getCount() << std::endl;  // Output will be 3
   }
   ```

### 2. **Static Member Functions**
A static member function is a function that belongs to the class rather than to any specific object. It can only access other static members of the class (variables or other functions) and cannot access instance (non-static) members.

- **Syntax**:
   ```cpp
   class ClassName {
   public:
       static void staticFunction() {
           // Static function code
       }
   };
   ```

- **Accessing Static Functions**:
   Static member functions can be called using the class name, without creating an object. You can also call them using an object, but this is less common.

   ```cpp
   ClassName::staticFunction();  // Calling the static function via class name
   obj.staticFunction();         // Calling the static function via object (not recommended)
   ```

- **Example**:
   ```cpp
   class Math {
   public:
       static int add(int a, int b) {
           return a + b;
       }
   };

   int main() {
       std::cout << Math::add(3, 4) << std::endl;  // Output will be 7
   }
   ```

### Key Characteristics of Static Members:

1. **Shared Among Objects**:
   Static members are shared by all instances of the class. There is only one copy of static variables, and static functions can access static variables.

2. **Accessed via Class Name**:
   Static members can be accessed without creating an instance of the class. They are usually accessed using the class name.

3. **Memory**:
   Static variables are stored in a fixed location in memory and retain their value between function calls. They are initialized only once, when the program starts or when the class is first used.

4. **Cannot Access Non-static Members**:
   Static member functions cannot access non-static member variables or non-static member functions because they are not tied to any specific object instance.

5. **Can Be Used for Utility Functions**:
   Static functions are commonly used for utility functions or class-wide features, such as factory methods, that don't require an object.

### Example with Both Static Variable and Static Function:
```cpp
#include <iostream>

class BankAccount {
public:
    static double interestRate;  // Static member variable

    BankAccount(double balance) : balance(balance) {}

    void deposit(double amount) {
        balance += amount;
    }

    double getBalance() const {
        return balance;
    }

    static void setInterestRate(double rate) {  // Static member function
        interestRate = rate;
    }

    static double getInterestRate() {  // Static member function
        return interestRate;
    }

private:
    double balance;
};

// Define static variable outside the class
double BankAccount::interestRate = 0.05;

int main() {
    BankAccount account1(1000);
    BankAccount account2(2000);

    // Use static function to change the interest rate
    BankAccount::setInterestRate(0.07);

    std::cout << "Account 1 balance: $" << account1.getBalance() << std::endl;
    std::cout << "Account 2 balance: $" << account2.getBalance() << std::endl;
    std::cout << "Current interest rate: " << BankAccount::getInterestRate() << "%" << std::endl;

    return 0;
}
```

### Output:
```
Account 1 balance: $1000
Account 2 balance: $2000
Current interest rate: 0.07
```

### Summary:
- Static member variables are shared across all objects of a class.
- Static member functions can only access static members of the class.
- Static members allow class-wide behavior without needing to instantiate an object.