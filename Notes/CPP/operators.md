# Operators in C++
In C++, operators are symbols used to perform operations on variables and values. There are several types of operators in C++, and they can be categorized into different groups based on their functionality. Here are the **different types of operators** in C++:

### 1. **Arithmetic Operators**
These operators are used to perform basic arithmetic operations on numerical values.

- **`+`** (Addition)
- **`-`** (Subtraction)
- **`*`** (Multiplication)
- **`/`** (Division)
- **`%`** (Modulus, gives the remainder of division)

#### Example:
```cpp
int a = 10, b = 3;
int sum = a + b;        // sum = 13
int difference = a - b; // difference = 7
int product = a * b;    // product = 30
int quotient = a / b;   // quotient = 3
int remainder = a % b;  // remainder = 1
```

### 2. **Relational Operators**
These operators are used to compare two values and return a boolean result (`true` or `false`).

- **`==`** (Equal to)
- **`!=`** (Not equal to)
- **`<`** (Less than)
- **`>`** (Greater than)
- **`<=`** (Less than or equal to)
- **`>=`** (Greater than or equal to)

#### Example:
```cpp
int a = 5, b = 10;
bool result1 = (a == b);  // false
bool result2 = (a < b);   // true
```

### 3. **Logical Operators**
Logical operators are used to perform logical operations, typically with boolean values.

- **`&&`** (Logical AND)
- **`||`** (Logical OR)
- **`!`** (Logical NOT)

#### Example:
```cpp
bool x = true, y = false;
bool result1 = (x && y);  // false
bool result2 = (x || y);  // true
bool result3 = !x;        // false
```

### 4. **Bitwise Operators**
Bitwise operators work on the binary representations of integers and perform bit-level operations.

- **`&`** (Bitwise AND)
- **`|`** (Bitwise OR)
- **`^`** (Bitwise XOR)
- **`~`** (Bitwise NOT)
- **`<<`** (Left shift)
- **`>>`** (Right shift)

#### Example:
```cpp
int a = 5;  // Binary: 0101
int b = 3;  // Binary: 0011
int andResult = a & b;  // 1 (Binary: 0001)
int orResult = a | b;   // 7 (Binary: 0111)
int xorResult = a ^ b;  // 6 (Binary: 0110)
```

### 5. **Assignment Operators**
Assignment operators are used to assign values to variables.

- **`=`** (Simple assignment)
- **`+=`** (Add and assign)
- **`-=`** (Subtract and assign)
- **`*=`** (Multiply and assign)
- **`/=`** (Divide and assign)
- **`%=`** (Modulus and assign)
- **`&=`** (Bitwise AND and assign)
- **`|=`** (Bitwise OR and assign)
- **`^=`** (Bitwise XOR and assign)
- **`<<=`** (Left shift and assign)
- **`>>=`** (Right shift and assign)

#### Example:
```cpp
int a = 5;
a += 3;  // a = 8
a *= 2;  // a = 16
```

### 6. **Unary Operators**
Unary operators operate on a single operand.

- **`++`** (Increment)
- **`--`** (Decrement)
- **`+`** (Unary plus, indicates positive value)
- **`-`** (Unary minus, negates the value)
- **`!`** (Logical NOT, negates boolean values)
- **`~`** (Bitwise NOT)

#### Example:
```cpp
int a = 5;
a++;  // a = 6 (post-increment)
++a;  // a = 7 (pre-increment)
a--;  // a = 6 (post-decrement)
--a;  // a = 5 (pre-decrement)
```

### 7. **Ternary Operator (Conditional Operator)**
The ternary operator is a shorthand for an `if-else` statement.

- **`? :`** (Condition ? expression_if_true : expression_if_false)

#### Example:
```cpp
int a = 5, b = 10;
int result = (a > b) ? a : b;  // result = 10
```

### 8. **Typecast Operators**
Typecast operators are used to explicitly convert a variable from one type to another.

- **`(type)`** (Type casting, e.g., `(int) x`)

#### Example:
```cpp
double x = 5.75;
int y = (int) x;  // y = 5 (casts the float to int)
```

### 9. **Pointer Operators**
Pointer operators work with pointers and memory addresses.

- **`&`** (Address-of operator, returns the address of a variable)
- **`*`** (Dereference operator, accesses the value at the address)

#### Example:
```cpp
int a = 10;
int* ptr = &a;  // Pointer ptr stores the address of a
int value = *ptr;  // Dereference ptr to get the value stored at the address
```

### 10. **Sizeof Operator**
The `sizeof` operator is used to determine the size of a data type or object in memory (in bytes).

- **`sizeof`** (Sizeof operator)

#### Example:
```cpp
int a = 10;
std::cout << sizeof(a);  // Outputs the size of the integer (typically 4 bytes)
```

### 11. **Comma Operator**
The comma operator allows you to evaluate multiple expressions where only one expression is expected (usually used in loops).

- **`,`** (Comma operator)

#### Example:
```cpp
int x = 5;
int y = 10;
int z = (x++, y++, x + y);  // x and y are incremented, and z is assigned x + y = 12
```

### 12. **Member Access Operators**
These operators are used to access members of a class or structure.

- **`.`** (Dot operator, used to access members of an object)
- **`->`** (Arrow operator, used to access members of a pointer to an object)

#### Example:
```cpp
class Person {
public:
    std::string name;
    int age;
};

Person p;
p.name = "John";  // Dot operator

Person* ptr = &p;
ptr->age = 30;  // Arrow operator
```

### 13. **New and Delete Operators**
These operators are used for dynamic memory allocation and deallocation.

- **`new`** (Allocates memory on the heap)
- **`delete`** (Deallocates memory on the heap)

#### Example:
```cpp
int* ptr = new int;  // Allocates memory for an integer
*ptr = 5;
delete ptr;  // Deallocates memory
```

### 14. **Scope Resolution Operator**
The scope resolution operator `::` is used to define the scope of a function or variable, especially in the context of classes.

- **`::`** (Scope resolution operator)

#### Example:
```cpp
int a = 5;  // Global variable

class MyClass {
public:
    static int a;  // Static member variable
    void print() {
        std::cout << a << std::endl;  // Uses the class member a
    }
};

int MyClass::a = 10;  // Define the class member outside the class
```

### 15. **Exception Handling Operators**
Used in handling exceptions in C++.

- **`try`** (Marks the start of a block to handle exceptions)
- **`catch`** (Defines a block to catch and handle exceptions)
- **`throw`** (Used to throw an exception)

#### Example:
```cpp
try {
    throw 20;  // Throwing an exception
} catch (int e) {
    std::cout << "Caught exception: " << e << std::endl;  // Catching the exception
}
```

---

### Summary:
C++ provides a wide variety of operators to perform various operations, including arithmetic, comparison, logical, bitwise, assignment, and more. Understanding these operators is essential for writing efficient and effective C++ programs.