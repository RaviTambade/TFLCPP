### **Problem Statement for Payroll System in C**

A **Payroll System** is a software application designed to manage the compensation of employees in an organization. It calculates employee salaries, handles deductions (such as taxes, insurance, etc.), and provides a detailed record of employee earnings. The system should be capable of storing employee information, calculating salaries based on hourly, daily, or monthly rates, and generating payroll reports.

The **Payroll System in C** aims to automate and streamline these processes, ensuring accurate and efficient payroll management while minimizing manual errors.

---

### **Problem Objective:**

The objective is to design and implement a **Payroll System in C** that can manage employee records, calculate salaries, handle deductions, and generate payroll reports. The system should include the following functionalities:
1. **Add Employee**: Add new employees to the payroll system.
2. **View Employee Records**: View details of all employees.
3. **Calculate Salary**: Calculate employee salaries based on their work type (e.g., hourly, monthly) and apply deductions.
4. **Generate Payroll Report**: View detailed payroll reports for all employees, including basic salary, deductions, and net salary.
5. **Exit**: Exit the system.

---

### **System Features and Requirements:**

1. **Employee Information:**
   - Each employee will have the following details:
     - **Employee ID**: A unique identifier for each employee.
     - **Name**: The name of the employee.
     - **Designation**: The job title or role of the employee.
     - **Basic Salary**: The base salary of the employee.
     - **Hours Worked**: The number of hours worked (for hourly employees).
     - **Deductions**: Various deductions like tax, insurance, etc.
     - **Net Salary**: The final salary after applying deductions.

2. **Payroll Calculation:**
   - The payroll calculation will depend on the type of employee:
     - **Hourly Employees**: Salary is calculated based on the hours worked multiplied by the hourly wage rate.
     - **Monthly Employees**: Salary is a fixed amount, with deductions applied based on the employee's record.

3. **Deductions:**
   - Various deductions will be applied to the salary, such as:
     - **Tax**: A fixed percentage of the salary (e.g., 10%).
     - **Insurance**: A fixed amount or percentage.
     - **Other Deductions**: Any other employee-specific deductions (e.g., loan repayment, provident fund).

4. **User Operations:**
   - **Add Employee**: The user can add a new employee to the system by entering their details such as name, designation, salary type (hourly or monthly), and salary-related information.
   - **View Employees**: The user can view the list of all employees with their details.
   - **Calculate Salary**: The user can calculate and display the salary for an employee, including basic salary, deductions, and net salary.
   - **Generate Payroll Report**: The system can generate a report for all employees showing their gross salary, deductions, and net salary.
   - **Exit**: The user can exit the system.

---

### **Data Structures:**

1. **Employee Structure:**
   Each employee is represented by a structure containing details such as name, designation, salary type, deductions, and calculated salaries.

   ```c
   #define MAX_EMPLOYEES 100

   struct Employee {
       int empID;               // Unique identifier for each employee
       char name[100];          // Name of the employee
       char designation[100];   // Job title or role of the employee
       float basicSalary;       // Base salary (monthly or hourly)
       float hoursWorked;       // Hours worked (if hourly employee)
       float deductions;        // Deductions from the salary
       float netSalary;         // Final salary after deductions
       char salaryType[10];     // Type of salary: "hourly" or "monthly"
   };

   struct Employee employees[MAX_EMPLOYEES];
   int totalEmployees = 0;  // Total number of employees in the system
   ```

2. **Deductions Calculation:**
   The system will calculate deductions (e.g., tax, insurance) based on the salary type.

   ```c
   float calculateDeductions(float basicSalary) {
       float tax = basicSalary * 0.1; // 10% tax deduction
       float insurance = 50.0; // Fixed insurance deduction
       return tax + insurance;
   }
   ```

3. **Salary Calculation for Hourly and Monthly Employees:**
   - **Hourly Employee**: The salary is calculated based on hours worked multiplied by the hourly wage rate.
   - **Monthly Employee**: The salary is fixed, and deductions are applied to it.

---

### **Functional Requirements:**

1. **Add Employee:**
   - The user can input the employee's details such as employee ID, name, designation, salary type (hourly or monthly), and basic salary.
   - For hourly employees, the user will also enter the number of hours worked.

2. **View Employees:**
   - The user can view a list of all employees with their details: name, designation, salary type, and basic salary.
   
3. **Calculate Salary:**
   - The user can choose an employee and calculate their salary.
     - If the employee is **hourly**, the salary is calculated by multiplying the hours worked with the hourly wage rate.
     - If the employee is **monthly**, the salary is taken as the fixed amount with deductions applied.
     - The system will then calculate and display the **net salary** after applying deductions.

4. **Generate Payroll Report:**
   - The system will generate a report showing the details for each employee, including their:
     - **Employee ID**
     - **Name**
     - **Basic Salary**
     - **Deductions**
     - **Net Salary**

5. **Exit:**
   - The user can choose to exit the system.

---

### **Constraints and Assumptions:**

1. **Fixed Capacity:**
   - The system can store a maximum of `MAX_EMPLOYEES` employees. If the number of employees exceeds this limit, the system will notify the user.

2. **Basic Input Validation:**
   - The system will ensure that salary values and hours worked are positive.
   - It will also check that an employee's salary type is either **"hourly"** or **"monthly"**.

3. **No Persistent Data Storage:**
   - The system does not save data to files. All data will be lost when the program terminates. This can be extended in the future by integrating file handling for data persistence.

4. **User Interface:**
   - The system will use a **text-based command-line interface (CLI)**, where users can select options from a menu.

---

### **Sample Menu Options:**

```
Payroll System
===============
1. Add Employee
2. View Employees
3. Calculate Salary
4. Generate Payroll Report
5. Exit
Enter your choice (1-5):
```

---

### **Sample Code Outline:**

```c
#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    int empID;
    char name[100];
    char designation[100];
    float basicSalary;
    float hoursWorked;
    float deductions;
    float netSalary;
    char salaryType[10];
};

struct Employee employees[MAX_EMPLOYEES];
int totalEmployees = 0;

float calculateDeductions(float basicSalary) {
    float tax = basicSalary * 0.1; // 10% tax deduction
    float insurance = 50.0; // Fixed insurance deduction
    return tax + insurance;
}

void addEmployee() {
    if (totalEmployees < MAX_EMPLOYEES) {
        struct Employee newEmployee;
        printf("Enter Employee ID: ");
        scanf("%d", &newEmployee.empID);
        getchar();  // Consume newline
        printf("Enter Employee Name: ");
        fgets(newEmployee.name, 100, stdin);
        newEmployee.name[strcspn(newEmployee.name, "\n")] = '\0';  // Remove newline
        printf("Enter Employee Designation: ");
        fgets(newEmployee.designation, 100, stdin);
        newEmployee.designation[strcspn(newEmployee.designation, "\n")] = '\0';  // Remove newline
        printf("Enter Salary Type (hourly/monthly): ");
        fgets(newEmployee.salaryType, 10, stdin);
        newEmployee.salaryType[strcspn(newEmployee.salaryType, "\n")] = '\0';  // Remove newline
        printf("Enter Basic Salary: ");
        scanf("%f", &newEmployee.basicSalary);

        if (strcmp(newEmployee.salaryType, "hourly") == 0) {
            printf("Enter Hours Worked: ");
            scanf("%f", &newEmployee.hoursWorked);
        }

        newEmployee.deductions = calculateDeductions(newEmployee.basicSalary);
        newEmployee.netSalary = newEmployee.basicSalary - newEmployee.deductions;

        employees[totalEmployees++] = newEmployee;
        printf("Employee added successfully!\n");
    } else {
        printf("Cannot add more employees. Maximum capacity reached.\n");
    }
}

void viewEmployees() {
    printf("\nList of Employees:\n");
    for (int i = 0; i < totalEmployees; i++) {
        printf("ID: %d, Name: %s, Designation: %s, Salary Type: %s, Basic Salary: %.2f, Net Salary: %.2f\n",
               employees[i].empID, employees[i].name, employees[i].designation,
               employees[i].salaryType, employees[i].basicSalary, employees[i].netSalary);
    }
}

void calculateSalary() {
    int empID;
    printf("Enter Employee ID to calculate salary: ");
    scanf("%d", &empID);

    int found = 0;
    for (int i = 0; i < totalEmployees; i++) {
        if (employees[i].empID == empID) {
            found = 1;
            if (strcmp(employees[i].salaryType, "hourly") == 0) {
                employees[i].netSalary = employees[i].hoursWorked * employees[i].basicSalary - employees[i].deductions;
            } else if (strcmp(employees[i].salaryType, "monthly") == 0) {
                employees[i].netSalary = employees[i].basicSalary - employees[i].deductions;
            }
            printf("Net Salary for Employee ID %d: %.2f\n", employees[i].empID, employees[i].netSalary);
            break;
        }
    }
    if (!found) {
        printf("Employee not found.\n");


    }
}

void generatePayrollReport() {
    printf("\nPayroll Report:\n");
    for (int i = 0; i < totalEmployees; i++) {
        printf("ID: %d, Name: %s, Designation: %s, Basic Salary: %.2f, Deductions: %.2f, Net Salary: %.2f\n",
               employees[i].empID, employees[i].name, employees[i].designation,
               employees[i].basicSalary, employees[i].deductions, employees[i].netSalary);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nPayroll System\n");
        printf("===============\n");
        printf("1. Add Employee\n");
        printf("2. View Employees\n");
        printf("3. Calculate Salary\n");
        printf("4. Generate Payroll Report\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: viewEmployees(); break;
            case 3: calculateSalary(); break;
            case 4: generatePayrollReport(); break;
            case 5: return 0;
            default: printf("Invalid choice. Try again.\n");
        }
    }
}
```

---

### **Conclusion:**

The **Payroll System** designed in C automates the process of managing employee records, calculating salaries, applying deductions, and generating payroll reports. The system can handle both hourly and monthly employees and provides detailed payroll calculations and reports. Future improvements could include persistent data storage, more complex deductions, and an expanded user interface for ease of use.