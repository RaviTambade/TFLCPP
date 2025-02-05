# Array Iteration

Using pointers for array iteration in C is a powerful technique that allows you to navigate through arrays efficiently. Here’s how you can do it:

### Iterating Through an Array Using Pointers

Here’s a simple example that demonstrates how to iterate through an array using pointers:

```c
#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr; // Pointer to the first element of the array
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate number of elements in the array

    printf("Array elements using pointers:\n");
    
    // Iterate through the array using the pointer
    for (int i = 0; i < size; i++) {
        printf("%d ", *(ptr + i)); // Access the value at the pointer's offset
    }
    
    printf("\n");

    return 0;
}
```

### Explanation

1. **Array Declaration**:
   - An array `arr` of integers is declared and initialized.

2. **Pointer Initialization**:
   - A pointer `ptr` is initialized to point to the first element of the array (`arr`).

3. **Calculating Size**:
   - The size of the array is calculated by dividing the total size of the array by the size of one element.

4. **Iteration**:
   - A `for` loop is used to iterate through the array. Instead of using the array index directly, we use pointer arithmetic:
     - `*(ptr + i)` accesses the value at the current position of the pointer, where `i` is the current index in the loop.

5. **Output**:
   - The program prints the elements of the array.

### Output
When you run this code, you should see:
```
Array elements using pointers:
10 20 30 40 50
```

### Key Points

- **Pointer Arithmetic**: `ptr + i` computes the address of the `i`-th element by adding `i` to the pointer `ptr`. Since `ptr` points to an `int`, the compiler knows to move `i * sizeof(int)` bytes forward.
- **Dereferencing**: The `*` operator is used to dereference the pointer, giving access to the value at that memory address.

### Practice
Try modifying the program to:
- Reverse the array elements using pointers.
- Sum the elements of the array using a pointer.
- Create a function that takes a pointer to an array and its size, and prints the elements.

If you have any questions or need more examples, feel free to ask!