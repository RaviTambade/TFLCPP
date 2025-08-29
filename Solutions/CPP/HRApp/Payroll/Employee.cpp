#include "Employee.h"

//scope resolution operator
Employee::Employee(int empId, string empName, float empSalary) {
    id = empId;
    name = empName;
    salary = empSalary;
}

int Employee::getId() const {
    return id;
}

string Employee::getName() const {
    return name;
}

float Employee::getSalary() const {
    return salary;
}

void Employee::displayInfo() const {
    cout << "Employee ID: " << id << endl;
    cout << "Employee Name: " << name << endl;
    cout << "Employee Salary: " << salary << endl;
}
