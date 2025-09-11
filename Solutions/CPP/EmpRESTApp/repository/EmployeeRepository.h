#ifndef EMPLOYEEREPOSITORY_H
#define EMPLOYEEREPOSITORY_H
#include"../entitity/employee.h"
#include "IemployeeRepository.h"
#include <vector>
using namespace std ;

class EmployeeRepository:public IEmployeeRepository{
    public :

        vector<Employee>employees ;
        void add(Employee &employee) override;
        void update (int id , Employee &employee )override;
        void remove(int id )override;
        Employee get(int id )override;
        vector<Employee>getAllEmployees()override ;
};
#endif 