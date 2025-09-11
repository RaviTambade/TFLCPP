#include <iostream>
#include <stdlib.h>
#include "httplib.h"
#include "./services/EmployeeServices.h"
#include "./repository/EmployeeRepository.h"
#include <memory>
using namespace std;
using namespace httplib ;
int main()
{ // menu
    Server svr ;
    int choice;
    int id;
    string name;
    double salary;

    int experience;
    int age;
    IEmployeeRepository *empRepo = new EmployeeRepository();
    EmployeeServices empSer(empRepo);

    while (true)
    {

        cout << "\n***** Menu *****" << endl;
        cout << "1. Add employee" << endl;
        cout << "2.Update" << endl;
        cout << "3. remove" << endl;
        cout << "4. get by id" << endl;
        cout << "5. get all" << endl;
        cout << "6. exit" << endl;
        cout << "enter your choice :" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "enter id of employee" << endl;
            cin >> id;
            cout << "enter name of employee" << endl;
            cin >> name;
            cout << "enter salary of employee" << endl;
            cin >> salary;
            cout << "enter experience of employee" << endl;
            cin >> experience;
            cout << "enter age of employee" << endl;
            cin >> age;

            Employee emp(id, name, salary, experience, age);
            empSer.addEmployee(emp);
            break;
        }
        case 2:{
            cout<<"Enter id to update "<<endl ;
            cin>>id ;
             cout << "enter id of employee" << endl;
            cin >> id;
            cout << "enter name of employee" << endl;
            cin >> name;
            cout << "enter salary of employee" << endl;
            cin >> salary;
            cout << "enter experience of employee" << endl;
            cin >> experience;
            cout << "enter age of employee" << endl;
            cin >> age;

            Employee emp(id, name, salary, experience, age);
            empSer.updateEmployee(id, emp);
            break;
        }
        case 3 : {
            cout<<"Enter id to remove "<<endl ;
            cin>>id ;
            empSer.removeEmployee(id);
        }
        case 4 :{
            cout<<"Enter id to know information "<<endl ;
            cin>>id ;
           Employee e1= empSer.getEmployee(id);
           cout<<"\nid: "<<e1.id;
           cout<<"\nname: "<<e1.name;
           cout<<"\nsalary: "<<e1.salary;
           cout<<"\nexperience: "<<e1.experience;
           cout<<"\nage: "<<e1.age;

            break;
        }

        case 5 : {
            vector<Employee> allemp=empSer.getAllemployees();
            for(auto& e:allemp)
            {
                 cout<<"\nid: "<<e.id;
                cout<<"\nname: "<<e.name;
                cout<<"\nsalary: "<<e.salary;
                cout<<"\nexperience: "<<e.experience;
                cout<<"\nage: "<<e.age;
            }
            break;
        }
        case 6 :
            cout<<"tata bye";
            return 0 ;
        
        default:
            break;
        }
    }
    return 0;
}
//g++ -Iinclude -c ./services/EmployeeServices.cpp -o services.o
//g++ -Iinclude -c ./repository/EmployeeRepository.cpp -o repo.o
//g++ -Iinclude -c main.cpp -o main.o
//g++ repo.o services.o main.o -o server.exe

