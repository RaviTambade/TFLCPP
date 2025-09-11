#ifndef IEMPLOYEEREPOSITORY_H
#define IEMPLOYEEREPOSITORY_H
#include"../entitity/employee.h"
#include <vector>
using namespace std ;

class IEmployeeRepository{
    public :
        virtual ~IEmployeeRepository()=default;
        virtual void add(Employee &employee)=0;
        virtual void update (int id , Employee &employee )=0;
        virtual void remove(int id )=0;
        virtual Employee get(int id )=0;
        virtual vector<Employee>getAllEmployees()=0 ;
};
#endif 