# Stack and Heap memory

In C programming, understanding the concepts of stack and heap memory is crucial for managing memory effectively. Both stack and heap are areas of memory used for different purposes, and they have distinct characteristics and uses.

### Stack Memory

**Stack memory** is a region of memory used for managing function calls, local variables, and control flow. It operates in a Last In, First Out (LIFO) manner.

#### Characteristics of Stack Memory:

1. **Automatic Allocation and Deallocation**: Memory is automatically allocated and deallocated when functions are called and return, respectively. This is handled by the system and does not require explicit management from the programmer.

2. **Fixed Size**: The size of the stack is typically fixed and limited by the operating system. It's usually smaller compared to the heap.

3. **Fast Access**: Access to stack memory is very fast because it's managed with a simple pointer that moves up and down.

4. **Scope and Lifetime**: Variables on the stack are only available within the scope of the function or block in which they are declared. Once the function exits, the memory is automatically freed.

5. **Limitations**: Stack memory is limited in size, and large or deeply recursive function calls can lead to stack overflow.

#### Example of Stack Usage:

```c
#include <stdio.h>

void stackExample() {
    int localVar = 10; // localVar is allocated on the stack
    printf("Local variable: %d\n", localVar);
}

int main() {
    stackExample();
    return 0;
}
```

In this example, `localVar` is a local variable allocated on the stack when `stackExample` is called. It is automatically deallocated when the function returns.

### Heap Memory

**Heap memory** is a region of memory used for dynamic memory allocation. It is managed manually by the programmer.

#### Characteristics of Heap Memory:

1. **Dynamic Allocation**: Memory is allocated and deallocated manually using functions like `malloc`, `calloc`, `realloc`, and `free`.

2. **Variable Size**: The size of the heap is generally much larger than the stack and is only limited by the system's available memory.

3. **Slower Access**: Access to heap memory can be slower compared to stack memory due to the overhead of dynamic memory management.

4. **Scope and Lifetime**: Variables in the heap persist until explicitly deallocated with `free`. This means they can be used across function calls and for as long as needed, but require manual management.

5. **Memory Leaks**: Improper management of heap memory (e.g., forgetting to call `free`) can lead to memory leaks, where memory is allocated but not freed, causing the program to consume more and more memory over time.

#### Example of Heap Usage:

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *heapVar = (int *)malloc(sizeof(int)); // Allocate memory on the heap
    if (heapVar == NULL) {
        perror("Failed to allocate memory");
        return EXIT_FAILURE;
    }

    *heapVar = 20; // Use the allocated memory
    printf("Heap variable: %d\n", *heapVar);

    free(heapVar); // Deallocate memory
    return 0;
}
```

In this example, `heapVar` is a pointer to memory allocated on the heap. The memory is manually managed and freed when no longer needed.

### Summary

- **Stack Memory**:
  - Managed automatically.
  - Fixed size.
  - Fast access.
  - Local to functions; deallocated when function exits.
  - Limited in size, can cause stack overflow with deep recursion or large allocations.

- **Heap Memory**:
  - Managed manually.
  - Variable size.
  - Slower access.
  - Persistent until explicitly freed.
  - Potential for memory leaks if not managed properly.

Understanding the differences between stack and heap memory helps in making informed decisions about memory management and optimizing performance in C programs.