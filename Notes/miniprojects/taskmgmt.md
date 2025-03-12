### **Problem Definition for Task Management System Using C**

The task management system is an application designed to help users manage, organize, and track various tasks efficiently. Users should be able to perform basic operations like adding, deleting, marking tasks as completed, and viewing tasks in the system. This system will be implemented using **C programming** to give users the flexibility and control over their task list, and provide a simple but functional command-line interface.

---

### **Problem Objective:**

To develop a Task Management System in C that allows users to:
1. **Add tasks** with titles and descriptions.
2. **Mark tasks as completed**.
3. **Delete tasks** that are no longer required.
4. **View all tasks**, displaying their status (pending/completed).
5. **Exit the application** when finished.

---

### **System Features and Requirements:**

1. **User Input:**
   - The system should accept user input through the command line interface.
   - Each task can have a **title** and **description**. The description is optional.
   - The task has a **status**: "Pending" or "Completed".
   
2. **Task Operations:**
   - **Add Task**: The user should be able to add a new task with a title and description (optional).
   - **View All Tasks**: The user should be able to view all tasks, listing each task with its status (pending or completed).
   - **Mark Task as Completed**: The user should be able to mark a specific task as "Completed".
   - **Delete Task**: The user should be able to delete a task from the list.
   - **Exit**: The user should be able to exit the system gracefully.

3. **Task Storage:**
   - Tasks should be stored in an array or dynamic structure (like an array of structs) within the program's memory.
   - The task list should support **dynamic** resizing if needed (up to a limit).

4. **User Interface:**
   - The system will be operated via the console with a text-based menu.
   - The menu should provide clear options for each feature.

---

### **Data Structures:**

- **Task Structure**: A structure to represent a task. This will contain the title, description (optional), and status (completed or pending).
  
  Example of the struct:
  ```c
  struct Task {
      char title[100];     // Title of the task
      char description[200];  // Description (optional)
      int completed;       // Status (0 = Pending, 1 = Completed)
  };
  ```

- **Task Array**: An array of `struct Task` to hold the tasks.
  
  Example:
  ```c
  #define MAX_TASKS 100   // Maximum number of tasks
  struct Task tasks[MAX_TASKS];
  int taskCount = 0;      // Counter to keep track of the number of tasks
  ```

---

### **Functional Requirements:**

1. **Add a Task:**
   - Prompt the user to enter a task title and an optional description.
   - Add the task to the `tasks` array and increment `taskCount`.

2. **Mark a Task as Completed:**
   - Display all tasks to the user with their indices.
   - Prompt the user to choose a task to mark as completed.
   - Update the status of the chosen task from "Pending" to "Completed".

3. **Delete a Task:**
   - Display all tasks with their indices.
   - Prompt the user to choose a task to delete.
   - Shift remaining tasks in the array to fill the gap created by the deleted task and decrement `taskCount`.

4. **View All Tasks:**
   - Display all tasks with their title, description, and status (Pending/Completed).

5. **Exit the Application:**
   - The program should exit when the user chooses to do so, ensuring the user doesn’t lose any data.

---

### **Constraints and Assumptions:**

1. **Task List Capacity**: 
   - Initially, the system will support a fixed number of tasks (`MAX_TASKS`). The user will be notified if the task list reaches its capacity.
   - This number can be adjusted based on requirements, or dynamic memory allocation could be used to expand the array.

2. **No Persistence**:
   - The application will **not** save tasks permanently to disk. Once the program is closed, all tasks will be lost unless modified to support file saving in future extensions.

3. **User Input Validation**:
   - Basic validation should be performed to ensure that the user does not enter invalid input (e.g., marking a non-existent task as completed).

4. **Menu Options**:
   - The system should provide a main menu with the following options:
     - **1. Add Task**
     - **2. View All Tasks**
     - **3. Mark Task as Completed**
     - **4. Delete Task**
     - **5. Exit**

---

### **Sample Program Flow:**

1. **Initial Menu:**
   ```
   Task Management System
   ========================
   1. Add Task
   2. View All Tasks
   3. Mark Task as Completed
   4. Delete Task
   5. Exit
   Enter your choice (1-5):
   ```

2. **Add Task:**
   - User inputs task title and optional description. Task is added to the list.

3. **View All Tasks:**
   - Displays all tasks, their descriptions, and status.

4. **Mark Task as Completed:**
   - Displays tasks with indices. User selects a task index, and it is marked as completed.

5. **Delete Task:**
   - Displays tasks with indices. User selects a task index, and it is deleted. Remaining tasks shift accordingly.

6. **Exit:**
   - The program terminates.

---

### **Example Code Outline:**

```c
#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100

struct Task {
    char title[100];
    char description[200];
    int completed;
};

struct Task tasks[MAX_TASKS];
int taskCount = 0;

void addTask() {
    if (taskCount < MAX_TASKS) {
        printf("Enter task title: ");
        fgets(tasks[taskCount].title, 100, stdin);
        printf("Enter task description: ");
        fgets(tasks[taskCount].description, 200, stdin);
        tasks[taskCount].completed = 0; // Set status to pending
        taskCount++;
    } else {
        printf("Task list is full.\n");
    }
}

void viewTasks() {
    printf("All Tasks:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s[Status: %s]\n", i + 1, tasks[i].title, tasks[i].completed ? "Completed" : "Pending");
    }
}

void markTaskCompleted() {
    int taskNum;
    printf("Enter task number to mark as completed: ");
    scanf("%d", &taskNum);
    getchar(); // Consume the newline character
    if (taskNum > 0 && taskNum <= taskCount) {
        tasks[taskNum - 1].completed = 1;
        printf("Task %d marked as completed.\n", taskNum);
    } else {
        printf("Invalid task number.\n");
    }
}

void deleteTask() {
    int taskNum;
    printf("Enter task number to delete: ");
    scanf("%d", &taskNum);
    getchar(); // Consume the newline character
    if (taskNum > 0 && taskNum <= taskCount) {
        for (int i = taskNum - 1; i < taskCount - 1; i++) {
            tasks[i] = tasks[i + 1]; // Shift tasks
        }
        taskCount--;
        printf("Task %d deleted.\n", taskNum);
    } else {
        printf("Invalid task number.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nTask Management System\n");
        printf("========================\n");
        printf("1. Add Task\n");
        printf("2. View All Tasks\n");
        printf("3. Mark Task as Completed\n");
        printf("4. Delete Task\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        getchar(); // Consume newline left by scanf

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markTaskCompleted(); break;
            case 4: deleteTask(); break;
            case 5: return 0;
            default: printf("Invalid choice, please try again.\n");
        }
    }
}
```

---

### **Conclusion:**

This Task Management System allows users to manage tasks by adding, viewing, marking as completed, and deleting tasks. It is built using simple C constructs like arrays, structures, and functions, making it a great exercise in learning C programming and understanding how to manage data in a program.