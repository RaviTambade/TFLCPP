### **Problem Statement for Project Management System in C**

A **Project Management System** is a software application designed to help project managers and teams efficiently manage, track, and organize various aspects of a project from initiation to completion. This system will focus on the planning, scheduling, and tracking of tasks and resources throughout the project lifecycle. The system will help ensure that project deadlines are met, resources are efficiently allocated, and progress is regularly monitored.

In the **Project Management System in C**, the main objective is to allow users (project managers or team leads) to manage the following:

1. Add and define projects.
2. Create and manage tasks associated with a project.
3. Assign resources (team members) to tasks.
4. Track the progress of tasks and their completion status.
5. Set deadlines and milestones for the project.
6. View and generate reports on project progress, pending tasks, and overall status.

This system will allow for efficient project management for smaller teams or organizations, offering basic project tracking functionality. The solution will be implemented in **C programming** language, making use of appropriate data structures for storing project, task, and team member information.

---

### **Objective:**

The **Project Management System** will aim to:
1. Provide a clear overview of projects and tasks.
2. Allow task assignment and management.
3. Monitor the progress of tasks.
4. Generate reports and alerts for project progress and deadlines.
5. Enable users to track project milestones and resource allocation.

---

### **System Features and Functional Requirements:**

1. **Project Information Management:**
   - **Add New Project:** The system should allow users to add new projects, providing details such as project ID, project name, description, start date, end date, and project status (e.g., "Ongoing", "Completed").
   - **View Project Details:** Users should be able to view a list of all projects and their statuses.

2. **Task Management:**
   - **Add Task:** Users should be able to add tasks to a project, including task ID, task description, assigned team members, task start date, end date, and priority level (e.g., "High", "Medium", "Low").
   - **View Tasks:** The system should allow users to view tasks associated with a project and their current statuses (e.g., "Not Started", "In Progress", "Completed").
   - **Update Task Status:** Users should be able to update the status of tasks to track progress.

3. **Resource Assignment:**
   - **Assign Team Members to Tasks:** Users can assign one or more team members to a task, specifying roles and responsibilities.
   - **View Resource Allocation:** Users should be able to view the allocation of resources (team members) to tasks and monitor their workload.

4. **Project Monitoring and Reporting:**
   - **Progress Monitoring:** The system should allow users to track the overall progress of the project and individual tasks.
   - **Generate Reports:** The system should be able to generate reports on task completion, project progress, and resource utilization.
   - **Deadline Alerts:** Users should be notified when a task or project is approaching its deadline.

5. **Milestones:**
   - **Set Milestones:** The system should allow users to define project milestones (e.g., "Phase 1 Completed", "Final Review").
   - **Track Milestone Progress:** The system should monitor whether milestones are being achieved according to the project schedule.

6. **Data Validation:**
   - Ensure that all required fields are filled in and that task dates and deadlines are logically valid.

7. **User Interface:**
   - The system will provide a **text-based user interface** with clear menus for performing various operations such as adding projects, managing tasks, and generating reports.

---

### **Data Structures:**

1. **Project Structure:**
   Each project will be represented by a structure containing the following attributes:
   - Project ID (unique identifier)
   - Project name
   - Project description
   - Start date
   - End date
   - Project status (e.g., "Ongoing", "Completed")

   ```c
   #define MAX_PROJECTS 50
   #define MAX_TASKS 100
   #define MAX_TEAM_MEMBERS 10

   // Structure to store project details
   struct Project {
       int projectID;
       char projectName[100];
       char description[200];
       char startDate[20];
       char endDate[20];
       char projectStatus[20];  // e.g., "Ongoing", "Completed"
   };

   struct Project projects[MAX_PROJECTS];
   int totalProjects = 0;
   ```

2. **Task Structure:**
   Each task will be represented by a structure with attributes for task details and its status:
   - Task ID
   - Task description
   - Assigned team members
   - Start date
   - End date
   - Status (e.g., "Not Started", "In Progress", "Completed")

   ```c
   struct Task {
       int taskID;
       char taskDescription[200];
       char assignedTeamMembers[MAX_TEAM_MEMBERS][100];  // Team members assigned to the task
       char startDate[20];
       char endDate[20];
       char taskStatus[20];  // e.g., "Not Started", "In Progress", "Completed"
   };

   struct Task tasks[MAX_TASKS];
   int totalTasks = 0;
   ```

3. **Team Member Structure:**
   Each team member will be represented by a structure containing their personal details:
   - Member ID
   - Name
   - Role (e.g., "Developer", "Manager")

   ```c
   struct TeamMember {
       int memberID;
       char memberName[100];
       char role[50];
   };

   struct TeamMember teamMembers[MAX_TEAM_MEMBERS];
   int totalMembers = 0;
   ```

---

### **Functional Requirements:**

1. **Add New Project:**
   - Users should be able to add a project with its details (e.g., project name, description, start date, end date).

2. **View All Projects:**
   - Users should be able to view a list of all projects with key details such as name, start date, end date, and project status.

3. **Add Task to a Project:**
   - Users should be able to add tasks to an existing project, including assigning team members to tasks and setting deadlines.

4. **Update Task Status:**
   - Users should be able to update the status of tasks as they progress through stages (e.g., "Not Started" -> "In Progress" -> "Completed").

5. **Assign Team Members to Tasks:**
   - Users should be able to assign one or more team members to each task and track their workload.

6. **Track Project and Task Progress:**
   - The system should allow users to monitor the completion status of tasks and the overall progress of the project.

7. **Generate Project Reports:**
   - Users should be able to generate reports displaying the status of tasks, resources, and the project’s overall progress.

8. **Set and Track Milestones:**
   - Users should be able to define key project milestones and monitor progress toward achieving them.

9. **Deadline Alerts:**
   - The system should alert users when a task is nearing its deadline or if a project is behind schedule.

---

### **Sample Menu Options:**

```
Project Management System
===========================
1. Add New Project
2. View All Projects
3. Add Task to Project
4. Update Task Status
5. Assign Team Members to Task
6. Track Project Progress
7. Generate Project Report
8. Set Project Milestones
9. Exit
Enter your choice (1-9):
```

---

### **Constraints and Assumptions:**

1. **Fixed Capacity:**
   - The system will support a maximum of `MAX_PROJECTS` (e.g., 50), `MAX_TASKS` (e.g., 100), and `MAX_TEAM_MEMBERS` (e.g., 10). If the number of projects, tasks, or team members exceeds these limits, new entries cannot be added.

2. **Basic Data Validation:**
   - The system will perform basic validation to ensure that required fields (such as project names, task descriptions, and deadlines) are entered correctly.

3. **Temporary Data Storage:**
   - Data will be stored in memory during the session. Once the program ends, the data will be lost. For persistent data storage, the system can be extended to support file-based storage.

4. **Text-Based User Interface:**
   - The system will have a simple, text-based user interface for interacting with users. This can be extended in the future to a graphical interface or web-based system.

---

### **Sample Code Outline:**

```c
#include <stdio.h>
#include <string.h>

#define MAX_PROJECTS 50
#define MAX_TASKS 100
#define MAX_TEAM_MEMBERS 10

// Structures for Project, Task, and Team Members

// Functions to add projects, tasks, update statuses, etc.

int main() {
    int choice;
    while (1) {
        printf("\nProject Management System\n");
        printf("=========================\n");
        printf("1. Add New Project\n");
        printf("2. View All Projects\n");
        printf("3. Add Task to Project\n");
        printf("4. Update Task Status\n");
        printf("5. Assign Team Members to Task\n");
        printf("6. Track Project Progress\n");
        printf("7. Generate Project Report\n");
        printf("8. Set Project Milestones\n");
        printf("9. Exit\n");
        printf("Enter your choice (1-9): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addProject(); break;
            case 2: viewProjects(); break;
            case 3: addTask(); break;
            case 4: updateTaskStatus(); break;
            case 5: assignTeamMember(); break;
            case 6: trackProgress(); break;
            case 7: generateReport(); break;
            case 8: setMilestones(); break;
            case 9: return 0;
            default: printf("Invalid choice. Try again.\n");
        }
    }
}
```

---

### **Conclusion:**

The **Project Management System** in C will provide a simple but effective way for small

 teams or project managers to organize and track their projects. With features like task management, team member assignment, project progress tracking, and milestone monitoring, this system will assist in ensuring that projects are completed on time and with proper resource management. Future enhancements could include persistent data storage, advanced reporting capabilities, and integration with other tools (e.g., Gantt charts or team collaboration platforms).