#include "SalesEmployee.h"


//Member Initialization
SalesEmployee::SalesEmployee(int empId, string empName, float empSalary, float empCommissionRate)
    : Employee(empId, empName, empSalary), commissionRate(empCommissionRate) {}

float SalesEmployee::getCommissionRate() const {
    return commissionRate;
}

void SalesEmployee::displayInfo() const {
    Employee::displayInfo();
    cout << "Commission Rate: " << commissionRate << "%" << endl;
}

double SalesEmployee::calculateTotalSalary() const {
    return getSalary() + (getSalary() * commissionRate / 100);
}
