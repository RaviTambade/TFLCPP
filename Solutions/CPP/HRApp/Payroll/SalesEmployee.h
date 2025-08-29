#include <string>
#include <iostream>
#include "Employee.h" // Include the header for Employee
using namespace std;    

class SalesEmployee : public Employee {
    private:
        float commissionRate;
    public:
        SalesEmployee(int empId, string empName, float empSalary, float empCommissionRate);
        float getCommissionRate() const;
        void displayInfo() const;
        double calculateTotalSalary() const;
};  