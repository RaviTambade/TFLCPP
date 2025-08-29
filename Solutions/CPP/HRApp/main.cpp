#include <iostream>
#include <string>
#include "Payroll/Employee.h"
#include "Payroll/SalesEmployee.h"

using namespace std;

int main() {
    Employee emp1(1, "Ishwari Karale", 50000);
    emp1.displayInfo();

    SalesEmployee emp2(2, "Sumit Bhor", 60000, 10);
    emp2.displayInfo();
    cout << "Total Salary with Commission: " << emp2.calculateTotalSalary() << endl;

    return 0;
}

//g++ -I  include .\Payroll\Employee.cpp  .\Payroll\SalesEmployee.cpp .\main.cpp -o hr.exe