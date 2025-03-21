In C programming, a **function** is a block of code that performs a specific task. Functions allow you to break your program into smaller, manageable pieces, promoting reusability and organization.

Here’s an overview of how functions work in C:

### 1. **Function Definition**
A function definition consists of:
- **Return Type**: Specifies what type of value the function returns (e.g., `int`, `float`, `char`, `void`).
- **Function Name**: The name used to call the function.
- **Parameters**: Values passed into the function. (Optional)
- **Body**: Contains the code that defines what the function does.

#### Syntax:
```c
return_type function_name(parameter_list) {
    // body of the function
    // code statements
}
```

### 2. **Function Declaration (or Prototype)**
Before using a function in `main()` or another function, you should declare it, especially if the function is defined after its first use. This is also known as the function prototype.

#### Syntax:
```c
return_type function_name(parameter_list);
```

### 3. **Function Call**
A function is called by its name, followed by parentheses containing arguments (if any).

#### Syntax:
```c
function_name(arguments);
```

### Example:

Here’s an example of defining, declaring, and calling a simple function:

```c
#include <stdio.h>

// Function declaration
int add(int, int);

int main() {
    int result;

    // Function call
    result = add(5, 3);

    printf("The result is: %d\n", result);
    
    return 0;
}

// Function definition
int add(int num1, int num2) {
    return num1 + num2;
}
```

### Explanation:
- **Function Declaration**: `int add(int, int);` informs the compiler about the function `add`, which takes two `int` parameters and returns an `int`.
- **Function Definition**: The body of the `add` function takes two integer inputs and returns their sum.
- **Function Call**: In `main()`, the function is called with `add(5, 3)`, and the returned value is stored in `result`.

### 4. **Return Types**
- If a function returns a value, you specify the return type (e.g., `int`, `float`, etc.). 
- If the function does not return anything, use the `void` return type.

#### Example of `void` function:
```c
#include <stdio.h>

void printMessage() {
    printf("Hello, World!\n");
}

int main() {
    printMessage(); // Function call
    return 0;
}
```

### 5. **Parameters in Functions**
Functions can accept parameters, which are the inputs the function uses to perform its task.

- **Formal Parameters**: Defined in the function declaration.
- **Actual Parameters**: Values passed when calling the function.

#### Example with parameters:
```c
#include <stdio.h>

void greet(char name[]) {
    printf("Hello, %s!\n", name);
}

int main() {
    greet("Alice"); // Function call with an argument
    return 0;
}
```

### 6. **Recursion**
Functions in C can call themselves, which is known as **recursion**. It is useful for problems that can be broken down into smaller instances of the same problem.

#### Example of recursion:
```c
#include <stdio.h>

int factorial(int n) {
    if (n == 0) {
        return 1;  // base case
    }
    return n * factorial(n - 1);  // recursive case
}

int main() {
    int result = factorial(5);
    printf("Factorial of 5 is %d\n", result);
    return 0;
}
```

In this case, the `factorial` function calls itself until it reaches the base case (`n == 0`).

---

This is a basic overview of functions in C.