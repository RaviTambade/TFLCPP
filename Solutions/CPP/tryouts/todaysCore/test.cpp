#include <iostream>
#include <string>
using namespace std;

// Base class
class Employee {
protected:
    string firstName;
    string lastName;
    double baseSalary;

public:
    Employee() {
        firstName = "";
        lastName = "";
        baseSalary = 0.0;
        cout << "Default Employee constructor called" << endl;
    }

    // Parameterized constructor
    Employee(const string& f, const string& l, double salary)
        : firstName(f), lastName(l), baseSalary(salary) {
        cout << "Employee constructor called for " << firstName << " " << lastName << endl;
    }

    // Display function
    virtual void display() const {
        cout << "Name: " << firstName << " " << lastName 
             << ", Base Salary: " << baseSalary << endl;
    }

    //pure virutal function
    virtual double computePay() const = 0;

};

// Derived class
class SalesEmployee : public Employee {
private:
    double salesAmount;
    double commissionRate;

public:
    // Derived class constructor calls base class constructor
    SalesEmployee(const string& f, const string& l, double salary,
                  double sales, double rate)
        : Employee(f, l, salary), salesAmount(sales), commissionRate(rate) {
      
        cout << "SalesEmployee constructor called for " << firstName << " " << lastName << endl;
    }

    // Override display function
    void display() const override {
        double totalPay = baseSalary + (salesAmount * commissionRate);
        cout << "Name: " << firstName << " " << lastName
             << ", Base Salary: " << baseSalary
             << ", Sales: " << salesAmount
             << ", Commission Rate: " << commissionRate
             << ", Total Pay: " << totalPay << endl;
    }

    double computePay() const override {
        return baseSalary + (salesAmount * commissionRate);
    }
         


};

int main() {

    //C++
    
    SalesEmployee se1("John", "Doe", 40000, 60000, 0.06);
    se1.display();

    SalesEmployee se2("Ravi", "Tambade", 30000, 50000, 0.05);
    se2.display();

    SalesEmployee *ptr = new SalesEmployee("Alice", "Johnson", 50000, 70000, 0.07);
    ptr->display();
    delete ptr;

    return 0;
}
