# Operator Overloading

**Operator overloading** in C++ allows you to define custom behavior for operators (such as `+`, `-`, `*`, etc.) when they are applied to user-defined data types (like classes or structs). This makes it possible to use operators in a natural way, similar to how they work with built-in types.

### Key Points about Operator Overloading:
1. **Syntax**: You define a function that specifies how an operator works for a specific type. The function is called an **operator function**.
   
   Example:
   ```cpp
   class Complex {
   private:
       float real;
       float imag;

   public:
       Complex(float r, float i) : real(r), imag(i) {}

       // Overloading the '+' operator
       Complex operator+(const Complex& other) {
           return Complex(real + other.real, imag + other.imag);
       }

       void display() {
           std::cout << real << " + " << imag << "i" << std::endl;
       }
   };

   int main() {
       Complex c1(1.0, 2.0), c2(2.0, 3.0);
       Complex c3 = c1 + c2; // Using overloaded '+' operator
       c3.display();
   }
   ```
   In this example, the `+` operator is overloaded to add two `Complex` numbers.

2. **Operator Function**: The function that overloads the operator can be defined either as a member function or a non-member function (usually a friend function if it's not a member function).

3. **Overloading Rules**:
   - You cannot overload the following:
     - `::` (scope resolution operator)
     - `.` (member access operator)
     - `.*` (pointer-to-member operator)
     - `?:` (ternary operator)
   - Overloading operators should make logical sense and follow the principle of least surprise (e.g., overloading `+` for addition should not behave like subtraction).

4. **Operator Overloading for Common Operators**: Some commonly overloaded operators include:
   - Arithmetic operators (`+`, `-`, `*`, `/`)
   - Comparison operators (`==`, `!=`, `<`, `>`)
   - Assignment operator (`=`)
   - Stream insertion (`<<`) and extraction (`>>`)

### Example: Overloading the `+` Operator
Here's how you might overload the `+` operator to add two complex numbers.

```cpp
#include <iostream>

class Complex {
private:
    float real;
    float imag;

public:
    Complex(float r, float i) : real(r), imag(i) {}

    // Overloading the '+' operator as a member function
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    void display() {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};

int main() {
    Complex c1(3.0, 4.0), c2(1.0, 2.0);
    Complex c3 = c1 + c2;  // Using the overloaded '+' operator
    c3.display();  // Output: 4.0 + 6.0i
}
```

Operator overloading makes your code more intuitive when dealing with custom data types. However, it should be used judiciously, as misuse can lead to unclear or unexpected behavior.

In C++, there are a few operators that **cannot** be overloaded. These operators are either fundamental to the language or have a special purpose that cannot be redefined. Here’s a list of the operators that **cannot** be overloaded:

### 1. **Scope Resolution Operator (`::`)**
   - The `::` operator is used to define the scope in which a name resides, such as accessing a class's static members or global variables.
   - Example:
     ```cpp
     MyClass::myMethod();  // This can't be overloaded.
     ```

### 2. **Member Access Operator (`.`)**
   - The `.` operator is used to access members (variables or functions) of an object.
   - You cannot overload this operator for user-defined types.
   - Example:
     ```cpp
     myObject.myMethod();  // This cannot be overloaded.
     ```

### 3. **Pointer-to-Member Operator (`.*`)**
   - The `.*` operator is used to invoke a member function or access a member variable using a pointer to a member.
   - Example:
     ```cpp
     obj.*ptrToMember;  // This cannot be overloaded.
     ```

### 4. **Ternary Conditional Operator (`?:`)**
   - The ternary operator (`?:`) is a conditional operator with the form: `condition ? expression1 : expression2;`
   - This operator cannot be overloaded because it's a control flow operator.

### 5. **Sizeof Operator (`sizeof`)**
   - The `sizeof` operator is used to determine the size, in bytes, of a data type or object.
   - It cannot be overloaded because it is a compile-time operator.
   - Example:
     ```cpp
     sizeof(int);  // This cannot be overloaded.
     ```

### 6. **Typeid Operator (`typeid`)**
   - The `typeid` operator is used to get type information at runtime.
   - It cannot be overloaded because it is used for type identification and works at runtime.
   - Example:
     ```cpp
     typeid(myObject);  // This cannot be overloaded.
     ```

### 7. **New and Delete Operators (`new`, `delete`, `new[]`, `delete[]`)**
   - While you can overload `new` and `delete` for custom memory allocation and deallocation, you cannot overload `new` and `delete` as ordinary operators in an arbitrary way.
   - However, you can define special functions for custom memory management.
   - Example:
     ```cpp
     void* operator new(size_t size);  // You can overload this.
     void operator delete(void* pointer);  // You can overload this.
     ```

### Conclusion:
To summarize, these operators **cannot** be overloaded in C++:
- `::` (scope resolution)
- `.` (member access)
- `.*` (pointer-to-member)
- `?:` (ternary conditional)
- `sizeof` (size of operator)
- `typeid` (type identification)
- `new` and `delete` (although their behavior can be customized in terms of memory allocation)

These restrictions are in place to maintain the consistency and clarity of the language.