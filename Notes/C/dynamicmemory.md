# Dynamic memory allocation

Dynamic memory allocation in C allows you to allocate memory during runtime, which is particularly useful when the size of data structures cannot be determined at compile time. The standard library provides several functions for dynamic memory allocation, primarily `malloc()`, `calloc()`, `realloc()`, and `free()`.

### Key Functions

1. **`malloc(size_t size)`**: Allocates a specified number of bytes and returns a pointer to the first byte. The memory is uninitialized.

   ```c
   int *arr = (int *)malloc(5 * sizeof(int)); // Allocate space for 5 integers
   ```

2. **`calloc(size_t num, size_t size)`**: Allocates memory for an array of `num` elements, each of `size` bytes. It initializes the memory to zero.

   ```c
   int *arr = (int *)calloc(5, sizeof(int)); // Allocate space for 5 integers, initialized to 0
   ```

3. **`realloc(void *ptr, size_t new_size)`**: Resizes a previously allocated memory block. It can also be used to allocate new memory.

   ```c
   arr = (int *)realloc(arr, 10 * sizeof(int)); // Resize the array to hold 10 integers
   ```

4. **`free(void *ptr)`**: Frees previously allocated memory, making it available for future allocations.

   ```c
   free(arr); // Free the allocated memory
   ```

### Example: Using Dynamic Memory Allocation

Here's a simple example that demonstrates dynamic memory allocation for an array of integers.

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for n integers
    arr = (int *)malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit if allocation fails
    }

    // Input elements
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Print elements
    printf("You entered:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(arr);

    return 0;
}
```

### Explanation

1. **User Input**: The program asks the user for the number of elements they want to store.
2. **Memory Allocation**: It allocates memory for an array of integers using `malloc()`.
3. **Error Checking**: It checks if the memory allocation was successful.
4. **Input and Output**: The user enters the elements, and the program prints them.
5. **Memory Deallocation**: Finally, it frees the allocated memory using `free()`.

### Important Notes

- Always check if the pointer returned by `malloc()` or `calloc()` is `NULL` to ensure that memory allocation succeeded.
- Use `free()` to prevent memory leaks by releasing memory that is no longer needed.
- Be cautious with `realloc()`, as it may return `NULL` if it fails, and if the original pointer is lost, it may lead to memory leaks.

Dynamic memory allocation is powerful but requires careful management to avoid memory leaks and segmentation faults. 