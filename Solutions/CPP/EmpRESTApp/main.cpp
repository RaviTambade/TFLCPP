
//must go BEFORE httplib
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#define byte win_byte_override // avoid conflict with std::byte
#include <windows.h>
#undef byte

#include <iostream>
#include "./services/EmployeeServices.h"
#include "./repository/EmployeeRepository.h"
#include "httplib.h"
#include <memory>

using namespace std;
using namespace httplib;

int main()
{
    Server svr;

    IEmployeeRepository *empRepo = new EmployeeRepository();
    
    EmployeeServices  empSer(empRepo);


    svr.Get("/api/Employees", [&empSer]( const Request &req, Response &res)
        {
        
         vector<Employee> employees = empSer.getAllemployees();
       

        // Convert products to JSON and set response
        //set json array
        string json = "[";

        for (const auto& employee : employees) {
            //append json object to string 
            json += "{\"id\":" + to_string(employee.id) + ",\"name\":\"" + employee.name + "\",\"Salary\":" + to_string(employee.salary) + "},";
        }

        if (!employees.empty()) {
            json.pop_back();  // Remove last comma
        }
        
        //close json array
        json += "]";

        res.set_content(json, "text/json"); 
        });


    svr.Post("/api/Employee/add", [&empSer](const Request &req, Response &res)
            {
    
                auto id = req.get_param_value("id");
                auto name = req.get_param_value("name");
                auto salary = req.get_param_value("salary");
                auto experience = req.get_param_value("experience");
                auto age = req.get_param_value("age");

                Employee emp(stoi(id), name, stod(salary), stoi(experience), stoi(age));

                empSer.addEmployee(emp);
                res.set_content("Employee added: " + emp.name, "text/plain"); });

    svr.Delete("/api/Employee/delete", [&empSer](const Request &req, Response &res)
        {
            auto id = req.get_param_value("id");
            empSer.removeEmployee(stoi(id));
            res.set_content("Employee deleted: " + id, "text/plain");
        });

    svr.Put("/api/Employee/update", [&empSer](const Request &req, Response &res)
        { 
            auto id = req.get_param_value("id");
            auto name = req.get_param_value("name");
            auto salary = req.get_param_value("salary");
            auto experience = req.get_param_value("experience");
            auto age = req.get_param_value("age");

            Employee emp (stoi(id), name, stod(salary), stoi(experience), stoi(age));

            empSer.updateEmployee(stoi(id), emp);
            res.set_content("Employee updated: " + emp.name, "text/plain");
        });

    svr.listen("localhost", 9000);
    return 0;
}



//g++ main.cpp ./services/EmployeeServices.cpp ./repository/EmployeeRepository.cpp -o server.exe -D_WIN32_WINNT=0x0A00 -lws2_32 -lwsock32
