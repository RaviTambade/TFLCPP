#ifndef EMPLOYEESERVICES_H
#define EPLOYEESERVICES_H
#include "../repository/EmployeeRepository.h"
#include "IEmployeeServices.h"
class EmployeeServices: public IEmployeeServices{

public:
    IEmployeeRepository *repository ;
    EmployeeServices( IEmployeeRepository *repository);
    void addEmployee(Employee &employee) override;
    void removeEmployee(int id) override;
    void updateEmployee(int id , Employee &employee) override;
    Employee getEmployee(int id ) override;
    vector<Employee>getAllemployees() override;
};

#endif
