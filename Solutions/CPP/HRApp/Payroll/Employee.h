#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <iostream>
using namespace std;


class Employee{
    private:
        int id;
        string name;
        float salary;
    public:
        // Constructor
        Employee(int empId, string empName, float empSalary);

        int getId() const ;
        string getName() const;
        float getSalary() const;

        void displayInfo() const;
};
#endif