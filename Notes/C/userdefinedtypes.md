# User Defined Types

In C programming, user-defined types allow you to create complex data structures that better represent the problem domain of your application. This is achieved using several mechanisms, including `struct`, `union`, `enum`, and `typedef`. Here’s a detailed guide on how to use these user-defined types in C.

### 1. **Structs (Structures)**

A `struct` in C is a composite data type that groups together variables (members) under a single name. Each member can be of a different type.

**Defining and Using Structs:**

```c
#include <stdio.h>

// Define a struct
struct Person {
    char name[50];
    int age;
};

// Function to print person details
void printPerson(struct Person p) {
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
}

int main() {
    // Declare and initialize a struct variable
    struct Person john = {"John Doe", 30};

    // Access and modify struct members
    printf("Before modification:\n");
    printPerson(john);

    john.age = 31; // Modify age

    printf("After modification:\n");
    printPerson(john);

    return 0;
}
```

### 2. **Unions**

A `union` is a data structure that can store different data types in the same memory location. A union allows you to use the same memory location for multiple types, but only one type can be used at a time.

**Defining and Using Unions:**

```c
#include <stdio.h>

// Define a union
union Data {
    int i;
    float f;
    char str[20];
};

int main() {
    union Data data;

    // Store an integer
    data.i = 10;
    printf("data.i = %d\n", data.i);

    // Store a float (overwrites the previous value)
    data.f = 220.5;
    printf("data.f = %f\n", data.f);

    // Store a string (overwrites the previous value)
    sprintf(data.str, "Hello, world!");
    printf("data.str = %s\n", data.str);

    // Note that accessing other members after storing the string will be incorrect
    printf("data.i after storing string = %d\n", data.i); // Undefined behavior
    printf("data.f after storing string = %f\n", data.f); // Undefined behavior

    return 0;
}
```

### 3. **Enums (Enumerations)**

An `enum` is a user-defined type that consists of a set of named integer constants. Enums make code more readable by using descriptive names instead of numeric values.

**Defining and Using Enums:**

```c
#include <stdio.h>

// Define an enum
enum Weekday {
    SUNDAY,    // Default is 0
    MONDAY,    // 1
    TUESDAY,   // 2
    WEDNESDAY, // 3
    THURSDAY,  // 4
    FRIDAY,    // 5
    SATURDAY   // 6
};

int main() {
    enum Weekday today = WEDNESDAY;

    // Use the enum in a switch statement
    switch (today) {
        case MONDAY:
            printf("Today is Monday.\n");
            break;
        case WEDNESDAY:
            printf("Today is Wednesday.\n");
            break;
        case FRIDAY:
            printf("Today is Friday.\n");
            break;
        default:
            printf("It's a different day.\n");
            break;
    }

    return 0;
}
```

### 4. **Typedef**

`typedef` is used to create an alias for an existing type, which can make complex type definitions easier to manage and more readable.

**Using Typedef:**

```c
#include <stdio.h>

// Define a new type using typedef
typedef struct {
    char name[50];
    int age;
} Person;

// Function to print person details
void printPerson(Person p) {
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
}

int main() {
    // Declare and initialize a Person
    Person john = {"John Doe", 30};

    printPerson(john);

    return 0;
}
```

### **Summary**

- **Structs**: Group related variables of different types together.
- **Unions**: Store different data types in the same memory location, but only one type can be used at a time.
- **Enums**: Define a set of named integer constants for better code readability.
- **Typedef**: Create aliases for existing types to simplify complex type definitions.

These user-defined types are fundamental for creating more organized, readable, and maintainable C programs. They help model real-world entities more effectively and make code easier to understand and work with.