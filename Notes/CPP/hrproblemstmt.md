### Problem Statement: HR Salary Processing System

#### Overview:
The HR department of a company needs to manage and process the salary information for employees at different levels. The employees can be of different roles: general employees, managers, and directors. The salary of each type of employee is calculated differently based on their respective bonuses and stock options.

In this system, you are required to design a C++ program that:
- Organizes employee data using a **multilevel class hierarchy**.
- Implements **salary calculation logic** specific to each employee type.
- Uses **namespace**, **inheritance**, **polymorphism**, and **overriding** techniques.

The program should also display detailed employee information including their name, ID, and salary breakdown.

#### Requirements:

1. **Namespace HR**:
   - All classes related to employee data and salary processing must be encapsulated inside a namespace called `HR` to avoid name conflicts.

2. **Base Class: Employee**:
   - Contains the following attributes:
     - `name` (string): The name of the employee.
     - `employeeID` (integer): The unique ID of the employee.
     - `basicSalary` (double): The base salary of the employee.
   - Contains the following methods:
     - A constructor to initialize employee details (`name`, `employeeID`, `basicSalary`).
     - A method `calculateSalary()` to calculate and return the employee's salary (returns `basicSalary` by default).
     - A method `displayDetails()` to display basic employee information.

3. **Derived Class: Manager** (inherits from `Employee`):
   - Adds a `bonus` (double) attribute to represent the manager's bonus.
   - The salary calculation for a manager is the sum of `basicSalary` and `bonus`.
   - Overrides the `calculateSalary()` method to include the bonus in the calculation.
   - Inherits the `displayDetails()` method from `Employee` and adds details about the manager's bonus.

4. **Derived Class: Director** (inherits from `Manager`, which inherits from `Employee`):
   - Adds a `stockOptions` (double) attribute to represent the director's stock options.
   - The salary calculation for a director is the sum of `basicSalary`, `bonus`, and `stockOptions`.
   - Overrides the `calculateSalary()` method to include the stock options in the calculation.
   - Inherits the `displayDetails()` method from `Manager` and adds details about the director's stock options.

5. **Salary Calculation**:
   - The `calculateSalary()` function for each class must correctly compute the total salary for the employee based on the class's role.
     - For a general employee, the salary is equal to the `basicSalary`.
     - For a manager, the salary is the sum of `basicSalary` and `bonus`.
     - For a director, the salary is the sum of `basicSalary`, `bonus`, and `stockOptions`.

6. **Display Employee Information**:
   - The program must print the following details for each employee:
     - Employee ID
     - Name
     - Basic Salary
     - Bonus (for managers)
     - Stock Options (for directors)
     - Total Salary (calculated using `calculateSalary()`)

#### Input:
- The program should create instances of the `Employee`, `Manager`, and `Director` classes.
- The attributes of each employee (name, ID, basic salary, bonus, stock options) are hardcoded within the program or can be taken as input from the user.

#### Output:
For each employee (Employee, Manager, and Director), the following information must be printed:
```
Employee Details and Salary Calculation:
Employee ID: <EmployeeID>
Name: <EmployeeName>
Basic Salary: <BasicSalary>
Salary: <CalculatedSalary>

Manager Details and Salary Calculation:
Employee ID: <EmployeeID>
Name: <EmployeeName>
Basic Salary: <BasicSalary>
Bonus: <Bonus>
Salary: <CalculatedSalary>

Director Details and Salary Calculation:
Employee ID: <EmployeeID>
Name: <EmployeeName>
Basic Salary: <BasicSalary>
Bonus: <Bonus>
Stock Options: <StockOptions>
Salary: <CalculatedSalary>
```

#### Example:

```
Employee Details and Salary Calculation:
Employee ID: 101
Name: John Doe
Basic Salary: 30000
Salary: 30000

Manager Details and Salary Calculation:
Employee ID: 102
Name: Alice Smith
Basic Salary: 50000
Bonus: 10000
Salary: 60000

Director Details and Salary Calculation:
Employee ID: 103
Name: Bob Johnson
Basic Salary: 70000
Bonus: 15000
Stock Options: 5000
Salary: 90000
```

#### Constraints:
- Employee salary should always be a positive value.
- Bonus and stock options should be reasonable for each type of employee:
  - Managers have a bonus that is greater than 0.
  - Directors have both a bonus and stock options, both of which are greater than 0.
  
#### Objective:
Design and implement a multilevel inheritance hierarchy using C++ and implement the salary processing logic that calculates total salary for employees based on their roles (Employee, Manager, Director). Use inheritance, polymorphism, and namespaces to achieve a clean and efficient design.