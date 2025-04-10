# Class Relationship in C++

In C++, **class relationships** define how different classes are **connected** and **interact** with each other in an object-oriented program. These relationships help model **real-world entities and their interactions** more accurately and efficiently.

Class relationships make code more **organized**, **modular**, and **reusable** by showing how one class is related to another in terms of behavior and structure.

There are mainly **three types** of class relationships in C++:

1. **Is-a Relationship** (Inheritance)  
   → Represents a generalization-specialization relationship.  
   → Example: A `Manager` **is-a** type of `Employee`.

2. **Has-a Relationship** (Composition or Aggregation)  
   → Represents ownership or part-whole relationship.  
   → Example: A `Car` **has-a** `Engine`.

3. **Uses-a Relationship** (Dependency)  
   → Represents temporary usage of one class by another.  
   → Example: A `Printer` **uses-a** `Document` to print.

Understanding these relationships is essential for designing robust and scalable C++ applications.


---

### 🏢 Mini Project: Company System

#### 🎯 Goal:
- A **`Company`** has **`Employee`**s → "has-a" relationship
- Different types of employees like `Manager`, `Developer` → "is-a" relationship

---

### 📦 Structure:

```
Company (has-a) → list of Employees

Employee (base class)
 ├── Manager (is-a Employee)
 └── Developer (is-a Employee)
```

---

### 🧑‍💻 Code:

```cpp
#include <iostream>
#include <vector>
#include <memory>  // for smart pointers

using namespace std;

// ======= Base Class =======
class Employee {
protected:
    string name;
    int id;

public:
    Employee(string n, int i) : name(n), id(i) {}
    virtual void showDetails() = 0; // pure virtual (abstract class)
    virtual ~Employee() {}
};

// ======= Derived Classes =======

class Developer : public Employee { // is-a Employee
    string language;

public:
    Developer(string n, int i, string lang)
        : Employee(n, i), language(lang) {}

    void showDetails() override {
        cout << "Developer: " << name << ", ID: " << id
             << ", Language: " << language << endl;
    }
};

class Manager : public Employee { // is-a Employee
    int teamSize;

public:
    Manager(string n, int i, int tSize)
        : Employee(n, i), teamSize(tSize) {}

    void showDetails() override {
        cout << "Manager: " << name << ", ID: " << id
             << ", Team Size: " << teamSize << endl;
    }
};

// ======= Company Class =======

class Company {
private:
    string companyName;
    vector<shared_ptr<Employee>> employees;  // has-a relationship

public:
    Company(string name) : companyName(name) {}

    void addEmployee(shared_ptr<Employee> emp) {
        employees.push_back(emp);
    }

    void showAllEmployees() {
        cout << "\nCompany: " << companyName << "\n--- Employee List ---\n";
        for (auto& emp : employees)
            emp->showDetails();
    }
};

// ======= Main Function =======

int main() {
    Company myCompany("Transflower Learning");

    // Create employees
    shared_ptr<Employee> dev1 = make_shared<Developer>("Sharthak", 101, "C++");
    shared_ptr<Employee> dev2 = make_shared<Developer>("Sharayu", 102, "Python");
    shared_ptr<Employee> mgr1 = make_shared<Manager>("Shubhangi", 201, 5);

    // Add employees to company
    myCompany.addEmployee(dev1);
    myCompany.addEmployee(dev2);
    myCompany.addEmployee(mgr1);

    // Show all employee details
    myCompany.showAllEmployees();

    return 0;
}
```

---

### 🔍 Output:

```
Company: TechFusion Inc
--- Employee List ---
Developer: Alice, ID: 101, Language: C++
Developer: Bob, ID: 102, Language: Python
Manager: Charlie, ID: 201, Team Size: 5
```

---

### ✅ Concepts Covered:

| Concept              | Used In                      |
|----------------------|------------------------------|
| Class & Object        | `Company`, `Employee`, etc.  |
| Inheritance (`is-a`) | `Manager` and `Developer` from `Employee` |
| Composition (`has-a`)| `Company` has `Employee`s     |
| Polymorphism         | `showDetails()` via base class pointer |
| Smart Pointers       | For safe memory handling      |

---

Want to add features like salaries, roles, or file saving next?



### Problem Statement ( Shape and Point)

#### Overview:
The goal of this problem is to design a system that can represent various geometric shapes using **containment** relationships rather than inheritance. Specifically, the **`Point`** class will serve as a foundational unit for all shapes, and all shapes (e.g., **Line**, **Rectangle**, **Circle**, **Triangle**) will contain one or more **Point** objects as part of their definition. Each shape will have properties and methods to calculate area, perimeter, and display relevant information about the shape.

#### Requirements:

1. **Containment Relationship**:
   - Instead of inheritance, shapes will **contain** one or more **Point** objects to define their geometry.
   - For instance:
     - A **Point** represents a specific coordinate in the 2D plane.
     - A **Line** contains two **Point** objects (start and end points).
     - A **Rectangle** contains two **Point** objects (top-left and bottom-right corners).
     - A **Circle** contains one **Point** object (center) and a radius.
     - A **Triangle** contains three **Point** objects (representing the vertices).

2. **Class Definitions**:

   - **Base Class: `Point`**:
     - Represents a point in the 2D plane with `x` and `y` coordinates.
     - Contains:
       - `x` (double): X-coordinate of the point.
       - `y` (double): Y-coordinate of the point.
     - A constructor to initialize the point's coordinates.
     - A method to display the point's coordinates (`displayPoint()`).

   - **Class: `Shape`**:
     - A generic base class that provides common methods for shapes, such as `calculateArea()` and `calculatePerimeter()`. These methods will be virtual, allowing derived classes to override them.
     - Includes a `display()` method to display information about the shape.
     - **Note**: This class will not directly represent a shape but will serve as a common interface for all derived shapes.

   - **Derived Class: `Line`** (contains two `Point` objects):
     - Represents a line segment defined by two points: a start point and an end point.
     - Contains two `Point` objects, `startPoint` and `endPoint`.
     - A constructor to initialize the line's start and end points.
     - A method to calculate the length of the line using the distance formula between the two points.
     - A method to display the line's start and end points.

   - **Derived Class: `Rectangle`** (contains two `Point` objects):
     - Represents a rectangle defined by two points: the top-left corner and the bottom-right corner.
     - Contains two `Point` objects, `topLeft` and `bottomRight`.
     - A constructor to initialize the rectangle's coordinates.
     - Methods to calculate the area and perimeter of the rectangle.
     - A method to display the rectangle's details, including the coordinates of the top-left and bottom-right corners.

   - **Derived Class: `Circle`** (contains one `Point` object):
     - Represents a circle defined by its center (a point) and radius.
     - Contains a `Point` object for the center and a `double` value for the radius.
     - A constructor to initialize the circle's center and radius.
     - Methods to calculate the area and circumference of the circle.
     - A method to display the circle's center and radius.

   - **Derived Class: `Triangle`** (contains three `Point` objects):
     - Represents a triangle defined by three points, representing the vertices of the triangle.
     - Contains three `Point` objects for the triangle’s vertices.
     - A constructor to initialize the triangle's vertices.
     - Methods to calculate the area of the triangle using the determinant formula or Heron's formula.
     - A method to display the triangle's vertex coordinates.

3. **Key Operations**:
   - Each class should provide methods to:
     - **Calculate Area**: Calculate the area of the shape (specific formulas for each shape).
     - **Calculate Perimeter/Circumference**: Calculate the perimeter (for polygons) or circumference (for circles).
     - **Display Shape Information**: Display the relevant information about the shape (e.g., coordinates, area, perimeter).

4. **Method Inheritance**:
   - Each derived class should override the `calculateArea()` and `calculatePerimeter()` methods.
   - The `display()` method should provide a detailed description of each shape's properties, such as coordinates and area.

5. **Output**:
   - For each shape, the program should display the following details:
     - Shape type
     - Coordinates (for points, lines, and polygons)
     - Area (for appropriate shapes)
     - Perimeter or Circumference (for appropriate shapes)

#### Input:
- The program should create objects for the following shapes:
  - **Point**: A single point with coordinates.
  - **Line**: Two points representing the start and end of the line.
  - **Rectangle**: Two points representing the top-left and bottom-right corners.
  - **Circle**: A point for the center and a radius value.
  - **Triangle**: Three points representing the triangle's vertices.

#### Output:
The program should display the following details for each shape:

```
Shape Type: Point
Coordinates: (x, y)

Shape Type: Line
Start Point: (x1, y1)
End Point: (x2, y2)
Length of Line: <length>

Shape Type: Rectangle
Top-Left: (x1, y1)
Bottom-Right: (x2, y2)
Area: <area>
Perimeter: <perimeter>

Shape Type: Circle
Center: (x, y)
Radius: <radius>
Area: <area>
Circumference: <circumference>

Shape Type: Triangle
Vertices: (x1, y1), (x2, y2), (x3, y3)
Area: <area>
```

#### Example:

```
Shape Type: Point
Coordinates: (1.0, 2.0)

Shape Type: Line
Start Point: (1.0, 2.0)
End Point: (3.0, 4.0)
Length of Line: 2.82843

Shape Type: Rectangle
Top-Left: (0.0, 5.0)
Bottom-Right: (4.0, 1.0)
Area: 20
Perimeter: 14

Shape Type: Circle
Center: (0.0, 0.0)
Radius: 5.0
Area: 78.5398
Circumference: 31.4159

Shape Type: Triangle
Vertices: (0.0, 0.0), (4.0, 0.0), (2.0, 3.0)
Area: 6
```

#### Constraints:
- All coordinates (x, y) are floating-point values.
- The program should support dynamic memory allocation for shape objects.
- Ensure proper input validation (e.g., for non-negative radius and valid point coordinates).
- Use appropriate mathematical formulas to compute area and perimeter/circumference.
  
#### Objective:
Design and implement the **Point**, **Shape**, **Line**, **Rectangle**, **Circle**, and **Triangle** classes with a **containment** relationship in C++ using **composition** rather than inheritance. Each shape should contain instances of the **Point** class as part of its structure. Implement the necessary methods for calculating areas, perimeters, and displaying shape details.