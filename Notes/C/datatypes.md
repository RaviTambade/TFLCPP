# Data Types
 Data types are fundamental because they define the kind of data a variable can hold. They determine the amount of memory allocated and the operations that can be performed on the data. Here's a breakdown of the primary data types in C:

### 1. **Basic Data Types**
- **`int`**: Used to store integers. The size of `int` can vary depending on the system, but it’s typically 4 bytes (32 bits) on most modern systems.
  ```c
  int age = 25;
  ```

- **`char`**: Used to store single characters. It typically takes 1 byte (8 bits) of memory.
  ```c
  char letter = 'A';
  ```

- **`float`**: Used to store floating-point numbers (numbers with decimal points). It usually occupies 4 bytes (32 bits) of memory.
  ```c
  float temperature = 36.6;
  ```

- **`double`**: Used to store double-precision floating-point numbers. It typically takes 8 bytes (64 bits) of memory.
  ```c
  double pi = 3.14159265358979;
  ```

### 2. **Modifiers**
Data types in C can be modified using type modifiers to alter their size or range. Common modifiers include:

- **`short`**: Used with `int` to store smaller integers. It usually takes 2 bytes (16 bits).
  ```c
  short int smallNumber = 1000;
  ```

- **`long`**: Used with `int` to store larger integers. It can be 4 or 8 bytes depending on the system.
  ```c
  long int largeNumber = 100000L;
  ```

- **`unsigned`**: Can be used with integer types (`int`, `short`, `long`) to store only non-negative values, effectively doubling the upper limit of positive values.
  ```c
  unsigned int positiveNumber = 3000U;
  ```

### 3. **Derived Data Types**
Derived data types are built from basic data types. Some common derived types include:

- **`array`**: A collection of elements of the same type.
  ```c
  int numbers[5] = {1, 2, 3, 4, 5};
  ```

- **`pointer`**: Stores the address of another variable.
  ```c
  int *ptr;
  int value = 10;
  ptr = &value;
  ```

- **`structure`**: A user-defined type that groups related variables of different types.
  ```c
  struct Person {
      char name[50];
      int age;
  };
  struct Person person1;
  ```

- **`union`**: A user-defined type that allows storing different data types in the same memory location.
  ```c
  union Data {
      int intValue;
      float floatValue;
  };
  union Data data;
  data.intValue = 10;
  ```

### 4. **Enumeration**
Enumerations define a set of named integer constants, improving code readability.
```c
enum Weekday { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };
enum Weekday today = Wednesday;
```

### 5. **Void**
The `void` type represents the absence of value. It is used in functions that do not return a value and as a generic pointer type.
```c
void functionName() {
    // Function code
}
void *ptr;
```

### Example Code
Here’s a small example demonstrating the use of different data types in a C program:

```c
#include <stdio.h>

int main() {
    int age = 30;
    float salary = 50000.50;
    double pi = 3.14159265358979;
    char grade = 'A';

    printf("Age: %d\n", age);
    printf("Salary: %.2f\n", salary);
    printf("Pi: %.15f\n", pi);
    printf("Grade: %c\n", grade);

    return 0;
}
```

In this example:
- `int` is used for `age`.
- `float` is used for `salary`.
- `double` is used for `pi`.
- `char` is used for `grade`.

Understanding these data types helps in writing efficient and effective C programs.