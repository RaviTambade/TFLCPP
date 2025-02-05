# File I/O (Input/Output

File I/O (Input/Output) in C allows you to read from and write to files.

### Basic Concepts

1. **File Pointers**: Use `FILE *fp;` to declare a file pointer.
2. **Opening a File**: Use `fopen("filename", "mode")` to open a file. Modes include:
   - `"r"`: Read
   - `"w"`: Write (creates a new file or truncates an existing one)
   - `"a"`: Append (adds to the end of a file)
   - `"r+"`: Read and write
   - `"w+"`: Read and write (creates a new file or truncates)
   - `"a+"`: Read and append

3. **Closing a File**: Use `fclose(fp);` to close the file when done.

4. **Reading/Writing**: Use functions like `fgetc()`, `fgets()`, `fprintf()`, and `fscanf()` for reading and writing data.

### Example: Writing to and Reading from a File

Here's a simple program that demonstrates writing to a file and then reading from it.

```c
#include <stdio.h>

int main() {
    FILE *fp;
    char data[100];

    // Writing to a file
    fp = fopen("example.txt", "w");  // Open for writing
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }
    fprintf(fp, "Hello, world!\n");
    fprintf(fp, "This is a test file.\n");
    fclose(fp);  // Close the file

    // Reading from a file
    fp = fopen("example.txt", "r");  // Open for reading
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }
    while (fgets(data, sizeof(data), fp) != NULL) {
        printf("%s", data);  // Print each line
    }
    fclose(fp);  // Close the file

    return 0;
}
```

### Explanation:

1. **Opening a File for Writing**: 
   - `fopen("example.txt", "w")` creates (or truncates) the file `example.txt`.
   - `fprintf()` writes formatted text to the file.

2. **Closing the File**: Always close the file with `fclose()` to free resources.

3. **Opening a File for Reading**:
   - `fopen("example.txt", "r")` opens the file for reading.
   - `fgets()` reads each line into `data`, and we print it.

### Tips:
- Always check if `fopen()` returns `NULL` to handle errors.
- Be careful with file modes to avoid unintentional data loss.

This should give you a good starting point for file I/O in C! Let me know if you have any questions!