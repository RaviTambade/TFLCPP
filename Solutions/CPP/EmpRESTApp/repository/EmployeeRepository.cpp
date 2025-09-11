#include"employeeRepository.h"
#include"employee.h"
#include"./IO/FileIOManager.h"

#include<vector>
#include<algorithm>
using namespace std ;

void EmployeeRepository::add(Employee &employee){
    FileIOManager mgr=FileIOManager();
    vector<Employee> employees = mgr.readFromFile("employees.txt");
     
    employees.push_back(employee);
    mgr.writeToFile("employees.txt", employees);

}

void EmployeeRepository::update(int id , Employee &employee ){
     FileIOManager mgr=FileIOManager();
    vector<Employee> employees = mgr.readFromFile("employees.txt");
    for (auto& e : employees) {
        if (e.id == id) {
            e = employee;
            break;
        }
    }
    mgr.writeToFile("employees.txt", employees);
}

void EmployeeRepository::remove (int id ){
    FileIOManager mgr=FileIOManager();
    vector<Employee> employees = mgr.readFromFile("employees.txt");
    employees.erase(remove_if(employees.begin(), employees.end(),
            [id](const Employee& p) { return p.id == id; }), employees.end());
    mgr.writeToFile("employees.txt", employees);
}

Employee EmployeeRepository:: get(int id ){
    FileIOManager mgr=FileIOManager();
    vector<Employee> employees = mgr.readFromFile("employees.txt");
    for (const auto& e : employees) {
        if (e.id == id) {
            return e;
        }
    }
}
vector<Employee>EmployeeRepository::getAllEmployees(){

    FileIOManager mgr=FileIOManager();
    vector<Employee> employees = mgr.readFromFile("employees.txt");
    return employees;
}