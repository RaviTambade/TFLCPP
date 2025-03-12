### **Problem Statement for User and Roles Management System in C**

The **User and Roles Management System** is a software solution designed to manage users and their associated roles within an organization or application. It allows system administrators to define and assign roles to users, grant them specific permissions, and ensure secure access control to different features of the system. The system should provide functionality for adding new users, updating user roles, viewing users, and managing their access rights based on their roles.

This system will help an organization effectively control user access to resources and functionalities, ensuring that each user has appropriate permissions to perform their tasks while maintaining system security.

---

### **Objective:**

The objective of this **User and Roles Management System in C** is to implement a simple access control system where administrators can:
1. Add new users to the system.
2. Assign roles to users (such as Admin, Manager, Employee).
3. Update user details and roles.
4. View all users and their assigned roles.
5. Delete users from the system.

---

### **Functional Requirements:**

1. **User Management:**
   - **Add User**: The system should allow administrators to add new users by specifying their name, username, password, and role.
   - **View Users**: Display a list of all users along with their roles.
   - **Update User Information**: Modify existing user details, including changing their role or updating their credentials.
   - **Delete User**: Remove a user from the system.

2. **Role Management:**
   - **Define Roles**: Roles such as Admin, Manager, and Employee should be predefined, with each role having specific access permissions.
   - **Assign Roles to Users**: The system should allow the assignment of roles to users, ensuring that the role’s permissions govern the user’s actions in the system.

3. **Permissions Management:**
   - Each role will have different permissions, e.g.,:
     - **Admin**: Full access to the system, can add, update, delete users, and manage roles.
     - **Manager**: Limited access, can add and view users, but cannot delete users.
     - **Employee**: Can view their own information and update their details, but cannot make any changes to other users.

4. **Access Control:**
   - The system should ensure that users can only access functions allowed by their role.
   - For example, only Admins can delete users or assign roles, while Managers and Employees have limited access.

5. **Search Functionality:**
   - The system should allow searching for users by username or role.

---

### **Data Structures:**

1. **User Structure:**
   Each user will be represented by a structure containing their details such as username, password, role, and other necessary fields.

   ```c
   #define MAX_USERS 100

   // Structure to store user information
   struct User {
       int userID;              // Unique identifier for each user
       char username[50];       // Username
       char password[50];       // User's password
       char role[20];           // Role assigned to the user (Admin, Manager, Employee)
   };

   struct User users[MAX_USERS];  // Array to store users
   int totalUsers = 0;            // Total number of users
   ```

2. **Roles:**
   - Predefined roles such as "Admin", "Manager", and "Employee" will be assigned with specific permissions in the system.
   - The permissions will be limited based on the role the user is assigned.

---

### **System Operations and Functions:**

1. **Add User:**
   - The administrator can input details such as username, password, and role for a new user.
   - The system will check if the user already exists and add them only if they do not exist.

2. **View Users:**
   - Display a list of all users along with their details: username, role, and other relevant information.

3. **Update User Role/Details:**
   - The administrator can update a user's role or change their details (e.g., password, username).

4. **Delete User:**
   - The administrator can delete a user from the system, removing them from the user list.

5. **Role-based Access Control:**
   - The system should ensure that users can only perform tasks allowed by their roles.
   - For instance, a user with an "Employee" role can only view their own details, while a "Manager" can update or view others’ information but cannot delete users.

6. **Search Users:**
   - The administrator can search for users by username or by role.

7. **Permissions Based on Roles:**
   - Permissions assigned to roles should determine what actions a user can perform in the system. Admins will have the highest level of permissions, Managers will have limited permissions, and Employees will have minimal permissions.

---

### **Sample Menu Options:**

```
User and Roles Management System
=================================
1. Add User
2. View All Users
3. Update User Information
4. Delete User
5. Search User by Username
6. Search User by Role
7. Exit
Enter your choice (1-7):
```

---

### **Constraints and Assumptions:**

1. **Fixed Capacity:**
   - The system can store a maximum of `MAX_USERS` users. If the system exceeds this capacity, no new users can be added.

2. **Basic Input Validation:**
   - The system will ensure that username and password are non-empty and meet basic requirements.
   - Role assignments will be checked to ensure they are one of the predefined roles ("Admin", "Manager", "Employee").

3. **No Persistent Data Storage:**
   - The system will not use file handling or databases for storing data. All user information is stored temporarily while the program is running.

4. **Basic Role Permissions:**
   - The role system will have basic predefined roles like Admin, Manager, and Employee, with simple access control, which can be extended in future iterations.

---

### **Sample Code Outline:**

```c
#include <stdio.h>
#include <string.h>

#define MAX_USERS 100

struct User {
    int userID;
    char username[50];
    char password[50];
    char role[20];
};

struct User users[MAX_USERS];
int totalUsers = 0;

void addUser() {
    if (totalUsers < MAX_USERS) {
        struct User newUser;
        printf("Enter Username: ");
        scanf("%s", newUser.username);
        printf("Enter Password: ");
        scanf("%s", newUser.password);
        printf("Enter Role (Admin, Manager, Employee): ");
        scanf("%s", newUser.role);
        
        newUser.userID = totalUsers + 1;
        users[totalUsers++] = newUser;

        printf("User added successfully!\n");
    } else {
        printf("Cannot add more users. Maximum capacity reached.\n");
    }
}

void viewUsers() {
    printf("\nList of Users:\n");
    for (int i = 0; i < totalUsers; i++) {
        printf("ID: %d, Username: %s, Role: %s\n", users[i].userID, users[i].username, users[i].role);
    }
}

void updateUser() {
    int userID;
    printf("Enter User ID to update: ");
    scanf("%d", &userID);

    if (userID > 0 && userID <= totalUsers) {
        printf("Enter new Username: ");
        scanf("%s", users[userID - 1].username);
        printf("Enter new Password: ");
        scanf("%s", users[userID - 1].password);
        printf("Enter new Role (Admin, Manager, Employee): ");
        scanf("%s", users[userID - 1].role);
        
        printf("User details updated successfully!\n");
    } else {
        printf("User not found.\n");
    }
}

void deleteUser() {
    int userID;
    printf("Enter User ID to delete: ");
    scanf("%d", &userID);

    if (userID > 0 && userID <= totalUsers) {
        for (int i = userID - 1; i < totalUsers - 1; i++) {
            users[i] = users[i + 1];
        }
        totalUsers--;
        printf("User deleted successfully!\n");
    } else {
        printf("User not found.\n");
    }
}

void searchUserByUsername() {
    char username[50];
    printf("Enter username to search: ");
    scanf("%s", username);

    for (int i = 0; i < totalUsers; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("User found: ID: %d, Username: %s, Role: %s\n", users[i].userID, users[i].username, users[i].role);
            return;
        }
    }

    printf("User not found.\n");
}

void searchUserByRole() {
    char role[20];
    printf("Enter role to search (Admin, Manager, Employee): ");
    scanf("%s", role);

    for (int i = 0; i < totalUsers; i++) {
        if (strcmp(users[i].role, role) == 0) {
            printf("User found: ID: %d, Username: %s, Role: %s\n", users[i].userID, users[i].username, users[i].role);
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nUser and Roles Management System\n");
        printf("=================================\n");
        printf("1. Add User\n");
        printf("2. View All Users\n");
        printf("3. Update User Information\n");
        printf("4. Delete User\n");
        printf("5. Search User by Username\n");
        printf("6. Search User by Role\n");
        printf("7. Exit\n");
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addUser(); break;
            case 2: viewUsers(); break;
            case 3: updateUser(); break;
            case 4: deleteUser(); break;
            case 5: searchUserByUsername(); break;
            case 6: searchUserByRole(); break;
            case 7: return 0;
            default: printf("Invalid choice. Try again.\n");
        }
    }
}
```

---

### **Conclusion:**

The **User and Roles Management System** designed in C allows administrators to manage users, assign roles, and control access to system features based on user roles. It includes functionalities like adding users, viewing users, updating information, deleting users, and searching users by their username or role. The system ensures that access is appropriately controlled based on the user's role, offering a simple access control solution. Future enhancements can include data persistence, advanced role permissions, and a more complex user interface.