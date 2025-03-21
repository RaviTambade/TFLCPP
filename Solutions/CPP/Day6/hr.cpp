#include <iostream>
#include <string>
using namespace std;

// Declare HR namespace
namespace HR {

    // Base class Employee
    class Employee {
    protected:
        string name;
        int employeeID;
        double basicSalary;

    public:
        // Constructor
        Employee(string empName, int empID, double salary)
            : name(empName), employeeID(empID), basicSalary(salary) {
                
            }

        // Virtual function to calculate salary, can be overridden in derived classes
        virtual double calculateSalary() {
            return basicSalary;  // Base salary for a general employee
        }

        // Function to display employee details
        void displayDetails() {
            cout << "Employee ID: " << employeeID << endl;
            cout << "Name: " << name << endl;
            cout << "Basic Salary: " << basicSalary << endl;
        }
    };

    // Derived class Manager, inheriting from Employee
    class Manager : public Employee {
    protected:
        double bonus;

    public:
        // Constructor
        Manager(string empName, int empID, double salary, double bonusAmount)
            : Employee(empName, empID, salary), bonus(bonusAmount) {}

        // Override calculateSalary to include bonus
        double calculateSalary() override {
            return basicSalary + bonus;  // Manager's salary includes bonus
        }

        // Function to display manager details (in addition to Employee's details)
        void displayDetails() {
            Employee::displayDetails();  // Call base class function to display common details
            cout << "Bonus: " << bonus << endl;
        }
    };

    // Derived class Director, inheriting from Manager
    class Director : public Manager {
    private:
        double stockOptions;

    public:
        // Constructor
        Director(string empName, int empID, double salary, double bonusAmount, double stock)
            : Manager(empName, empID, salary, bonusAmount), stockOptions(stock) {}

        // Override calculateSalary to include stock options
        double calculateSalary() override {
            return basicSalary + bonus + stockOptions;  // Director's salary includes stock options
        }

        // Function to display director details (in addition to Manager's and Employee's details)
        void displayDetails() {
            Manager::displayDetails();  // Call base class function to display manager and employee details
            cout << "Stock Options: " << stockOptions << endl;
        }
    };
}

// Main function to test the HR namespace classes
int main() {
    // Creating objects for each class in the HR hierarchy
    HR::Employee emp("Ravi Tambade", 101, 30000);
    HR::Manager mgr("Sanika Bhor", 102, 50000, 10000);
    HR::Director dir("Chirag Patil", 103, 70000, 15000, 5000);

    // Display details and calculate salary for each employee
    cout << "Employee Details and Salary Calculation:" << endl;
    emp.displayDetails();
    cout << "Salary: " << emp.calculateSalary() << endl << endl;

    cout << "Manager Details and Salary Calculation:" << endl;
    mgr.displayDetails();
    cout << "Salary: " << mgr.calculateSalary() << endl << endl;

    cout << "Director Details and Salary Calculation:" << endl;
    dir.displayDetails();
    cout << "Salary: " << dir.calculateSalary() << endl;

    return 0;
}
